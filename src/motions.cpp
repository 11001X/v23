#include "main.h"

void set_intake(int val){
    intakemotor = val;
}


void set_flywheel(int val){
    flywheelmotor = val;
}

void intake(int velocity, int time){
    set_intake(velocity);
    pros::delay(time);
    set_intake(0);
}


void flywheel(int velocity, int time){
    set_flywheel(velocity);
    pros::delay(time);
    set_flywheel(0);
}
void set_flywheel_velocity(int velocity){
    flywheelmotor.move_velocity(velocity);
}
void flywheel_until_speed(int delay, int adjustment=0){
    while(flywheelmotor.get_target_velocity()>flywheelmotor.get_actual_velocity()+adjustment){
        pros::delay(delay);
        ez::print_to_screen("Trial");
    }
}


void shooter_set(int time){
    shooter.set_value(true);
    pros::delay(time);
    shooter.set_value(false);
}