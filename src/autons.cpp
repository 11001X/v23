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
  set_flywheel(127); //FIRST SET flywheel starting.
  set_intake(50); //Initial intake for first roller
  chassis.set_drive_pid(-1.5, HIGHER_SPEED); 
  chassis.wait_drive();
  // pros::delay(); //Delay to intake
  chassis.set_drive_pid(1.5, HIGHER_SPEED); //Return to initial position.
  chassis.wait_drive();
  set_intake(122);
  

  //Turn towards corner disc (SWING turn, right side only)
  chassis.set_swing_pid(ez::RIGHT_SWING, -40, 110);
  chassis.wait_drive();

  //Forward Motion towards the slanted disc
  chassis.set_drive_pid(4, HIGHER_SPEED);
  chassis.wait_drive();
  pros::delay(600);
  // chassis.set_drive_pid(-4, HIGHER_SPEED);
  // chassis.wait_drive();

  chassis.set_turn_pid(-10.5, 113); //Turn towards high goal
  chassis.wait_drive();

  set_intake(0);

  // pros::delay(2000);

  //Shooting Code for Set 1
  direct_fire(127, 500, 200);
  direct_fire(127, 1000, 200);
  direct_fire(127, 1000, 400);
  pros::delay(200);
  set_intake(0);
  
  set_flywheel(115); //SECOND set of shots flywheel;

  chassis.set_swing_pid(ez::RIGHT_SWING, 51, 113);
  chassis.wait_drive();

  // chassis.set_turn_pid(54.5, 113); //Turns and moves parallel to the 3 stack (FIRST)
  // chassis.wait_drive(); 


  // chassis.set_drive_pid(18, HIGHER_SPEED); //Moves towards 3 STACK. (FIRST)
  // chassis.wait_drive();
  // pros::delay(400);

  // chassis.set_turn_pid(-45, TURN_SPEED); //Turns towards 3 stack (FIRST)
  // chassis.wait_drive();
  // pros::delay(500);
  // set_intake(-127);
  chassis.set_drive_pid(34.5, 127); //Moves towards 3 stack. (FIRST)
  chassis.wait_drive();
  set_intake(127); //Starts Intake
 
  chassis.set_drive_pid(24, 30); //Moves towards 3 stack. (SECOND)
  chassis.wait_drive();
  pros::delay(1000);
  set_intake(0);

  chassis.set_turn_pid(-41, HIGHER_TURN_SPEED); //Turn towards high goal
  chassis.wait_drive();
  // set_intake(0);
  // chassis.set_drive_pid(7, 127);
  // // chassis.wait_until(1);
  direct_fire(115, 500, 230);
  // // chassis.wait_until(3);
  direct_fire(127, 700, 200);
  // // chassis.wait_until(5);
  direct_fire(127, 700, 300);
  // chassis.wait_drive();
}

//OST - This is our far-side autonomous, made to maximize discs made and get a roller.
void outside_auton() {
  set_intake(127);
  set_flywheel(124);

  chassis.set_drive_pid(13.5, 50); //First disc in line with shooting 
  chassis.wait_until(3.5);
  chassis.set_max_speed(110);
  chassis.wait_until(6.5);
  chassis.set_max_speed(115);
  chassis.wait_until(9.5);
  chassis.set_max_speed(120);
  chassis.wait_until(11.5);
  chassis.set_max_speed(127);
  chassis.wait_drive();

  pros::delay(750);
  set_intake(0);

  chassis.set_turn_pid(2, HIGHER_TURN_SPEED); //Turn towards other discs
  chassis.wait_drive();

chassis.set_drive_pid(2, 123); //First disc in line with shooting 
  chassis.wait_drive();

  

  set_intake(0);
  //1ST SHOOTING SET
  direct_fire(124, 100, 220);
  direct_fire(127, 800, 220);
  direct_fire(127, 800, 300);
  // set_flywheel(127);
  pros::delay(100);
  set_intake(127);

  chassis.set_drive_pid(-2, 123); //First disc in line with shooting 
  chassis.wait_drive();

  chassis.set_turn_pid(14, 110); //Disc on line
  chassis.wait_drive();

  chassis.set_drive_pid(15, 123); //First disc in line with shooting 
  chassis.wait_drive();
  pros::delay(400);
  chassis.set_drive_pid(-10, 123); //First disc in line with shooting 
  chassis.wait_drive();

  chassis.set_turn_pid(-64, 110); //Turn towards other discs
  chassis.wait_drive();

  chassis.set_drive_pid(37, 123); //Pick them up
  chassis.wait_drive();
  pros::delay(100);

  chassis.set_turn_pid(17, 110); //Turn To shoot.
  chassis.wait_drive();
  set_intake(0);

  // //2ND SHOOTING SET
  direct_fire(127, 500, 200);
  direct_fire(127, 800, 200);
  direct_fire(127, 800, 300);
  set_flywheel(127);
  set_intake(127);

  chassis.set_turn_pid(-64, HIGHER_TURN_SPEED); //Turn backwards
  chassis.wait_drive();

  chassis.set_drive_pid(-67, 127); //Move back towards rollers
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, -15, 120); //Turn towards the high goal
  chassis.wait_drive();
  pros::delay(100);
  chassis.set_drive_pid(3, 127); //Move back towards rollers
  chassis.wait_drive();
  // set_intake(40);
  // chassis.set_drive_pid(-3, 123); //Pick them up
  // chassis.wait_drive();
  // chassis.set_drive_pid(3, 123); //Pick them up
  // chassis.wait_drive();
}

//SWP - This is our solo win point autonomous, made to shoot 4 discs and get the two rollers.
void solowinpoint(){
  set_intake(127); //Initial intake for first roller
  chassis.set_drive_pid(-0.5, HIGHER_SPEED); 
  chassis.wait_drive();
  pros::delay(100); //Delay to intake
  chassis.set_drive_pid(0.5, HIGHER_SPEED); //Return to initial position.
  chassis.wait_drive();

  set_flywheel(127); //FIRST SET flywheel starting.

  set_intake(127); //Starts Intake
  intake_up(); //Moves the intake up

  chassis.set_turn_pid(51, TURN_SPEED); //Turns and moves parallel to the 3 stack (FIRST)
  chassis.wait_drive();

  chassis.set_drive_pid(25, HIGHER_SPEED); //Moves towards 3 STACK. (FIRST)
  chassis.wait_drive();
  
  intake_down();
  pros::delay(1000); //Intakes and piston down and intaking 3stack (FIRST)

  intake_up(); //Intake up for 3 stack

  chassis.set_turn_pid(-22.5, TURN_SPEED); //1ST Turn towards high goal  
  chassis.wait_drive();

  set_intake(0);

  //Shooting Code for Set 1
  // direct_fire(110, 100);
  // direct_fire(110, 100);
  // direct_fire(110, 100);

  set_intake(127);
  pros::delay(1000);


  chassis.set_turn_pid(51, TURN_SPEED); //Turns back towards 3 stack (SECOND)
  chassis.wait_drive();

  chassis.set_drive_pid(40, HIGHER_SPEED); //Moves towards Roller. (SECOND)
  chassis.wait_drive();

  chassis.set_turn_pid(-90, HIGHER_TURN_SPEED); //Turn towards high goal
  chassis.wait_drive();


  chassis.set_drive_pid(-3, HIGHER_SPEED); //Moves towards Roller. (SECOND)
  chassis.wait_drive();

  pros::delay(100); //Outtake 2ND roller
  
  chassis.set_swing_pid(LEFT_SWING, -86, HIGHER_TURN_SPEED); //Turn towards high goal
  chassis.wait_drive();

  set_intake(0);

  direct_fire(110, 100);
  direct_fire(110, 100);
  direct_fire(110, 100);

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

void outside_constants() {
  chassis.set_slew_min_power(120, 120);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 12, 2, 23, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}