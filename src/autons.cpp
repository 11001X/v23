#include "main.h"

//Autonomous Routines Definition

//Speed Constants
const int DRIVE_SPEED = 110; // 110/127; Recommended Constant for Driving. 
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;
const int HIGHER_SPEED = 120;
const int HIGHER_TURN_SPEED = 100;

//IST - This is our near-side autonomous routine, designed to get a roller and 5 shots. 
void inside_auton(){

}

//OST - This is our far-side autonomous, made to maximize discs made and get a roller.
void outside_auton() {

}

//SWP - This is our solo win point autonomous, made to shoot 4 discs and get the two rollers.
void solowinpoint(){

}

//SKILLS - This is our current skills autonomous routine following a specified path. 
void skills_auton() {

}

//Define the PID constants for our autonomous routines.
void default_constants() {
  chassis.set_slew_min_power(120, 120);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 13.75, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

//Default exit condition definitions
void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}