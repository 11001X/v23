#pragma once

#include "EZ-Template/drive/drive.hpp"

void set_intake(int val);
void set_flywheel(int val);
void intake(int velocity, int time);
void outtake(int velocity, int time);
void flywheel(int velocity, int time);
void set_flywheel_velocity(int velocity);
void flywheel_until_speed(int delay, int adjustment);
void shooter_set(int time);
void intake_up();
void intake_down();
void deploylaunch();
void discfire(int target_speed, int outtake_time = 100);
void direct_fire(int target_speed, int post_delay, int outtake_speed = 127, int outtake_time = 100);
void vision_align();
void flywheelPID(double target);
void set_flywheel_speed(int speed);
void flywheelPIDWait(double target, double threshold = 5);