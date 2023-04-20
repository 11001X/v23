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
  set_intake(127); //Initial intake for first roller
  chassis.set_drive_pid(-0.5, HIGHER_SPEED); 
  chassis.wait_drive();
  pros::delay(100); //Delay to intake
  chassis.set_drive_pid(0.5, HIGHER_SPEED); //Return to initial position.
  chassis.wait_drive();

  set_flywheel(127); //FIRST SET flywheel starting.

  //Turn towards corner disc (SWING turn, right side only)
  chassis.set_swing_pid(ez::RIGHT_SWING, -40, TURN_SPEED);
  chassis.wait_drive();

  //Forward Motion towards the slanted disc
  chassis.set_drive_pid(3.5, HIGHER_SPEED);
  chassis.wait_drive();
  set_intake(0);
  chassis.set_drive_pid(-3.5, HIGHER_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-8, TURN_SPEED); //Turn towards high goal
  chassis.wait_drive();

  //Shooting Code for Set 1
  // direct_fire(127, 100);
  // direct_fire(127, 100);
  // direct_fire(127, 100);
  
  set_flywheel(110); //SECOND set of shots flywheel;

  set_intake(127); //Starts Intake
  intake_up(); //Moves the intake up

  chassis.set_turn_pid(51, TURN_SPEED); //Turns and moves parallel to the 3 stack (FIRST)
  chassis.wait_drive();

  chassis.set_drive_pid(18, HIGHER_SPEED); //Moves towards 3 STACK. (FIRST)
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED); //Turns towards 3 stack (FIRST)
  chassis.wait_drive();

  chassis.set_drive_pid(7, HIGHER_SPEED); //Moves towards 3 stack. (FIRST)
  chassis.wait_drive();
  
  intake_down();
  pros::delay(1000); //Intakes and piston down and intaking 3stack (FIRST)

  chassis.set_drive_pid(-7, HIGHER_SPEED); //Moves backwards from 3 stack. (FIRST)
  chassis.wait_drive();
  intake_up(); //Intake up for 3 stack

  chassis.set_turn_pid(-15, TURN_SPEED); //2ND Turn towards high goal  
  chassis.wait_drive();

  //Shooting Code for Set 2
  direct_fire(110, 100);
  direct_fire(110, 100);
  direct_fire(110, 100);

  pros::delay(1000);


  chassis.set_turn_pid(51, TURN_SPEED); //Turns back towards 3 stack (SECOND)
  chassis.wait_drive();

  chassis.set_drive_pid(10, HIGHER_SPEED); //Moves towards 3 stack. (SECOND)
  chassis.wait_drive();

  intake_down();
  pros::delay(200); //Intakes and piston down 3 stack (SECOND)
 
  chassis.set_turn_pid(-22.5, HIGHER_TURN_SPEED); //Turn towards high goal
  chassis.wait_drive();

  direct_fire(110, 100);
  direct_fire(110, 100);
  direct_fire(110, 100);
}

//OST - This is our far-side autonomous, made to maximize discs made and get a roller.
void outside_auton() {
  set_intake(127);
  chassis.set_drive_pid(11.5, 100); //First disc in line with shooting 
  chassis.wait_drive();

  //1ST SHOOTING SET
  // direct_fire(110, 100);
  // direct_fire(110, 100);
  // direct_fire(110, 100);
  // set_flywheel(127);
  pros::delay(1000);

  chassis.set_turn_pid(18, TURN_SPEED); //Disc on line
  chassis.wait_drive();

  chassis.set_drive_pid(17, 100); //First disc in line with shooting 
  chassis.wait_drive();
  pros::delay(500);
  chassis.set_drive_pid(-10, 100); //First disc in line with shooting 
  chassis.wait_drive();

  chassis.set_turn_pid(-64, TURN_SPEED); //Turn towards other discs
  chassis.wait_drive();

  chassis.set_drive_pid(33, 100); //Pick them up
  chassis.wait_drive();

  chassis.set_turn_pid(18, TURN_SPEED); //Turn To shoot.
  chassis.wait_drive();

  //2ND SHOOTING SET
  // direct_fire(127, 100);
  // direct_fire(127, 100);
  // direct_fire(127, 100);
  // set_flywheel(127);

  chassis.set_turn_pid(-64, TURN_SPEED); //Turn backwards
  chassis.wait_drive();

  chassis.set_drive_pid(-43, 100); //Move back towards rollers
  chassis.wait_drive();

  chassis.set_turn_pid(-15, TURN_SPEED); //Turn towards the high goal
  chassis.wait_drive();

  chassis.set_drive_pid(-3, 100); //Pick them up
  chassis.wait_drive();
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