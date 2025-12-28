#!/usr/bin/env python3
# Author: lnotspotl, abutalipovvv
import rclpy
import numpy as np
from RoboticsUtilities.Transformations import rotxyz
from .PIDController import PID_controller

class RestController:
    def __init__(self, default_stance):
        self.def_stance = default_stance

        # TODO: configure kp, ki и kd
        #                                     kp     ki    kd
        self.pid_controller = PID_controller(0.75, 2.29, 0.0)
        self.use_imu = False
        self.use_button = True
        self.pid_controller.reset()

    def updateStateCommand(self, msg, state, command):
        
        state.body_local_position[0] = msg.axes[2] * 0.08
        state.body_local_position[1] = msg.axes[5] * 0.08
        state.body_local_position[2] = msg.axes[1] * 0.08

        
        state.body_local_orientation[0] = msg.axes[0] * 0.8
        state.body_local_orientation[1] = msg.axes[4] * 0.6
        state.body_local_orientation[2] = msg.axes[3] * 0.6

        if self.use_button:
            if msg.buttons[7]:
                self.use_imu = not self.use_imu
                self.use_button = False
                print(f"Rest Controller - Использование компенсации крена/тангажа: {self.use_imu}")

        if not self.use_button:
            if not msg.buttons[7]:
                self.use_button = True

    @property
    def default_stance(self):
        return self.def_stance

    def step(self, state, command):
        temp = self.default_stance
        temp[2] = [command.robot_height] * 4


        if self.use_imu:
            compensation = self.pid_controller.run(state.imu_roll, state.imu_pitch)
            roll_compensation = -compensation[0]
            pitch_compensation = -compensation[1]

            rot = rotxyz(roll_compensation, pitch_compensation, 0)
            temp = np.matmul(rot, temp)

        return temp

    def run(self, state, command):
        state.foot_locations = self.step(state, command)
        return state.foot_locations
