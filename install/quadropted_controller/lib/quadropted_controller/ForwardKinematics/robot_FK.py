#!/usr/bin/env python3
import numpy as np
from math import sin, cos

class ForwardKinematics:
    def __init__(self, body_dimensions, leg_dimensions):
        """
        Инициализация параметров робота.
        :param body_dimensions: Размеры корпуса [длина, ширина]
        :param leg_dimensions: Размеры звеньев ног [l1, l2, l3, l4]
        """
        self.body_length = body_dimensions[0]
        self.body_width = body_dimensions[1]

        self.l1 = leg_dimensions[0]  # Высота корпуса (от центра масс до основания ног)
        self.l2 = leg_dimensions[1]  # Длина бедра
        self.l3 = leg_dimensions[2]  # Длина голени
        self.l4 = leg_dimensions[3]  # Длина копыта

    def homog_transform(self, dx, dy, dz, alpha, beta, gamma):
        """
        Создает однородную матрицу преобразования 4x4.
        :param dx, dy, dz: Смещение по осям x, y, z
        :param alpha, beta, gamma: Углы вращения вокруг осей x, y, z (в радианах)
        :return: Матрица преобразования 4x4
        """
        # Вращение вокруг оси X
        rx = np.array([
            [1, 0, 0, 0],
            [0, cos(alpha), -sin(alpha), 0],
            [0, sin(alpha), cos(alpha), 0],
            [0, 0, 0, 1]
        ])

        # Вращение вокруг оси Y
        ry = np.array([
            [cos(beta), 0, sin(beta), 0],
            [0, 1, 0, 0],
            [-sin(beta), 0, cos(beta), 0],
            [0, 0, 0, 1]
        ])

        # Вращение вокруг оси Z
        rz = np.array([
            [cos(gamma), -sin(gamma), 0, 0],
            [sin(gamma), cos(gamma), 0, 0],
            [0, 0, 1, 0],
            [0, 0, 0, 1]
        ])

        # Смещение
        trans = np.array([
            [1, 0, 0, dx],
            [0, 1, 0, dy],
            [0, 0, 1, dz],
            [0, 0, 0, 1]
        ])

        # Итоговая матрица преобразования: сначала вращения, затем смещение
        return trans @ rz @ ry @ rx

    def forward_kinematics_per_leg(self, theta_hip, theta_thigh, theta_calf, leg_index):
        """
        Вычисление позиции лапы на основе углов суставов для одной ноги.
        :param theta_hip: Угол hip_joint (в радианах)
        :param theta_thigh: Угол thigh_joint (в радианах)
        :param theta_calf: Угол calf_joint (в радианах)
        :param leg_index: Индекс ноги (0: FR, 1: FL, 2: RR, 3: RL)
        :return: Позиция лапы (x, y, z) относительно корпуса
        """
        # Определяем положение базового звена каждой ноги
        if leg_index == 0:  # FR
            base_x = self.body_length / 2
            base_y = self.body_width / 2
        elif leg_index == 1:  # FL
            base_x = self.body_length / 2
            base_y = -self.body_width / 2
        elif leg_index == 2:  # RR
            base_x = -self.body_length / 2
            base_y = self.body_width / 2
        elif leg_index == 3:  # RL
            base_x = -self.body_length / 2
            base_y = -self.body_width / 2
        else:
            raise ValueError("Invalid leg_index. Must be 0 (FR), 1 (FL), 2 (RR), or 3 (RL).")

        # Начальная трансформация: смещение на позицию ноги и высота корпуса
        T_base = self.homog_transform(base_x, base_y, -self.l1, 0, 0, 0)

        # Вращение hip_joint вокруг Z (abduction/adduction)
        T_hip_abd = self.homog_transform(0, 0, 0, 0, 0, theta_hip)

        # Вращение thigh_joint вокруг Y (pitch)
        T_thigh_pitch = self.homog_transform(0, 0, 0, 0, theta_thigh, 0)

        # Смещение вдоль X на длину бедра
        T_thigh = self.homog_transform(self.l2, 0, 0, 0, 0, 0)

        # Вращение calf_joint вокруг Y (pitch)
        T_calf_pitch = self.homog_transform(0, 0, 0, 0, theta_calf, 0)

        # Смещение вдоль X на длину голени
        T_calf = self.homog_transform(self.l3, 0, 0, 0, 0, 0)

        # Смещение вдоль X на длину копыта
        T_foot = self.homog_transform(self.l4, 0, 0, 0, 0, 0)

        # Итоговая матрица преобразования
        T_total = T_base @ T_hip_abd @ T_thigh_pitch @ T_thigh @ T_calf_pitch @ T_calf @ T_foot

        # Позиция лапы в локальной системе координат
        foot_position = T_total @ np.array([0, 0, 0, 1])

        return foot_position[:3]  # Возвращаем только x, y, z

    def forward_kinematics_all_legs(self, joint_angles):
        """
        Вычисление позиций лап для всех ног.
        :param joint_angles: Список из 12 углов суставов [FR_hip, FR_thigh, FR_calf, FL_hip, FL_thigh, FL_calf,
                                                                  RR_hip, RR_thigh, RR_calf, RL_hip, RL_thigh, RL_calf]
        :return: Список из 4 позиций лап [(x_FR, y_FR, z_FR), ..., (x_RL, y_RL, z_RL)]
        """
        if len(joint_angles) != 12:
            raise ValueError("Expected 12 joint angles.")

        foot_positions = []
        for leg in range(4):
            idx = leg * 3
            theta_hip = joint_angles[idx]
            theta_thigh = joint_angles[idx + 1]
            theta_calf = joint_angles[idx + 2]

            foot_pos = self.forward_kinematics_per_leg(theta_hip, theta_thigh, theta_calf, leg)
            foot_positions.append(foot_pos)

        return foot_positions
