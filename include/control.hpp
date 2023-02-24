#pragma once

#include "EZ-Template/drive/drive.hpp"

void intake_control(int in, int out);
void flywheel_control(int val);
bool shooter_control();
void launcher_control();
bool intakepiston_control(bool intakeval);
bool angler_control(bool anglerposition);
int flywheelset_control(int val);