#!/usr/bin/env python3
# Author: lnotspotl, abutalipovvv
import rclpy
from rclpy.time import Time
import numpy as np

class PID_controller:
    def __init__(self, kp, ki, kd):
        self.kp = kp
        self.ki = ki
        self.kd = kd

        self.desired_roll_pitch = np.array([0.0, 0.0])

        self.I_term = np.array([0.0, 0.0])
        self.D_term = np.array([0.0, 0.0])

        self.max_I = 0.2
        self.last_error = np.array([0.0, 0.0])
        self.last_time = None

    def run(self, roll, pitch):
        error = self.desired_roll_pitch - np.array([roll, pitch])

        t_now = self.get_time_in_seconds()
        if self.last_time is None:
            self.last_time = t_now
            return np.array([0.0, 0.0])  

        step = t_now - self.last_time

        if step < 1e-6:  
            return np.array([0.0, 0.0])

        self.I_term += error * step

        for i in range(2):
            if self.I_term[i] < -self.max_I:
                self.I_term[i] = -self.max_I
            elif self.I_term[i] > self.max_I:
                self.I_term[i] = self.max_I

        self.D_term = (error - self.last_error) / step

        self.last_time = t_now
        self.last_error = error

        P_ret = self.kp * error
        I_ret = self.I_term * self.ki
        D_ret = self.D_term * self.kd

        return P_ret + I_ret + D_ret

    def reset(self):
        self.last_time = self.get_time_in_seconds()
        self.I_term = np.array([0.0, 0.0])
        self.D_term = np.array([0.0, 0.0])
        self.last_error = np.array([0.0, 0.0])

    def set_desired_RP_angles(self, des_roll, des_pitch):
        self.desired_roll_pitch = np.array([des_roll, des_pitch])

    def get_time_in_seconds(self):
        return Time().seconds_nanoseconds()[0] + Time().seconds_nanoseconds()[1] * 1e-9
