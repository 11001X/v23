#pragma once

#include "EZ-Template/drive/drive.hpp"

void set_intake(int val);
void set_lift(int val);
void set_flywheel(int val);

void intake(int velocity, int time);
void flywheel(int velocity, int time);
void lift(int velocity, int time);