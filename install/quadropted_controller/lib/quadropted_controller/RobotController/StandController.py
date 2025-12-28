#!/usr/bin/env python3
# Author: lnotspotl, abutalipovvv
import numpy as np

class StandController:
    def __init__(self, node, default_stance):
        self.node = node  
        self.def_stance = default_stance
        self.max_reach = 0.065

        
        self.body_velocity_scale = 0.01  # Масштаб для линейных скоростей
        self.body_angular_scale = 0.005  # Масштаб для угловой скорости

        
        self.max_linear_velocity = 0.035  # [m/s]
        self.max_angular_velocity = 0.1   # [rad/s]

    @property
    def default_stance(self):
        
        return np.copy(self.def_stance)

    def run(self, state, command):
        
        temp = self.default_stance.copy()
        temp[2] = [command.robot_height] * 4

        
        linear_vel = command.velocity  
        angular_vel = command.yaw_rate  

        
        linear_vel = np.clip(linear_vel, 
                             [-self.max_linear_velocity, -self.max_linear_velocity, -self.max_linear_velocity],
                             [self.max_linear_velocity, self.max_linear_velocity, self.max_linear_velocity])
        
        
        angular_vel = np.clip(angular_vel, 
                              [-self.max_angular_velocity, -self.max_angular_velocity, -self.max_angular_velocity],
                              [self.max_angular_velocity, self.max_angular_velocity, self.max_angular_velocity])

        
        state.body_local_position[0] += linear_vel[0] * self.body_velocity_scale  # x
        state.body_local_position[1] += linear_vel[1] * self.body_velocity_scale  # y
        state.body_local_position[2] += linear_vel[2] * self.body_velocity_scale  # z 

        
        state.body_local_orientation[0] += angular_vel[0] * self.body_angular_scale  # Roll
        state.body_local_orientation[1] += angular_vel[1] * self.body_angular_scale  # Pitch
        state.body_local_orientation[2] += angular_vel[2] * self.body_angular_scale  # Yaw

        
        if self.node.verbose:
            self.node.get_logger().info(f"Updated body position: {state.body_local_position}")
            self.node.get_logger().info(f"Updated body orientation: {state.body_local_orientation}")

        
        state.foot_locations = temp
        return state.foot_locations
