#pragma once

#include "EZ-Template/drive/drive.hpp"

void set_intake(int val);
void set_lift(int val);
void set_flywheel(int val);
void set_flywheel_velocity(int velocity);
void flywheelauto(double target);
void flywheel_until_speed(int delay, int adjustment);

void intake(int velocity, int time);
void flywheel(int velocity, int time);
void lift(int velocity, int time);

void shooter_set(int time);
void deploylaunch();
void vision_align();
void flywheelPID(double target);
void set_flywheel_speed(int speed);
void flywheelPIDWait(double target, double threshold = 5);