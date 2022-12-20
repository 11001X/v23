#include "main.h"

void set_intake(int val){
    intakemotor = val;
}

void set_lift(int val){
    liftmotor = val;
}

void set_flywheel(int val){
    flywheelmotor = val;
}

void intake(int velocity, int time){
    set_intake(velocity);
    pros::delay(time);
    set_intake(0);
}

void lift(int velocity, int time){
    set_lift(velocity);
    pros::delay(time);
    set_lift(0);
}

void flywheel(int velocity, int time){
    set_flywheel(velocity);
    pros::delay(time);
    set_flywheel(0);
}