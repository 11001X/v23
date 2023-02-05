#include "main.h"

//Set intake motor speed to a value from -127 to 127
void set_intake(int val){
    intakemotor = val;
}

void flywheelauto(double target) {
  target = flywheelmotor.get_position()+target;
  flywheelPID.set_target(target);
  ez::exit_output exit = ez::RUNNING;
  while (flywheelPID.exit_condition({flywheelmotor}, true) == ez::RUNNING) {
    double output = flywheelPID.compute(flywheelmotor.get_position());
    set_flywheel(output);
    pros::delay(ez::util::DELAY_TIME);
  }
  set_flywheel(0);
}

//Set flywheel motor speed to a value from -127 to 127
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

//Set shooter to a value from -127 to 127
void shooter_set(int time){
    shooter.set_value(true);
    pros::delay(time);
    shooter.set_value(false);
}

//Launch
void deploylaunch(){
    launcher1.set_value(true);
    launcher2.set_value(true);
}