#include "main.h"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////

const int DRIVE_SPEED = 110; // 110/127; Recommended Constant for Driving. 
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;
const int HIGHER_SPEED = 120;
const int HIGHER_TURN_SPEED = 100;
//sdfdsf
/*
This is the auton we have to get both rollers and shoot 5 discs up, a solo win-point.
*/
void wp_auton() {

  //Backs up to roll the first roller at 120
  chassis.set_drive_pid(-3, HIGHER_SPEED, false);
  chassis.wait_drive(); 
  
  //Outtakes to turn the roller up
  intake(-127, 150);

  //Moves forward for 8.5 inches
  chassis.set_drive_pid(8.5, 127, false);
  chassis.wait_drive();

  //Turns to face the area between the disks 
  chassis.set_turn_pid(44, 110);
  chassis.wait_drive();

  //Drives between the disks, avoiding them
  chassis.set_drive_pid(64, 1271);
  chassis.wait_until(30);
  set_flywheel_velocity(400); //Starts the flywheel and sets the intended speed
  chassis.wait_drive();

  //Turns to face the goal
  chassis.set_turn_pid(-47, HIGHER_TURN_SPEED);
  chassis.wait_drive();

  //Delays between shots
  pros::delay(200);
  flywheel_until_speed(1,-7); //Lets the flywheel reach 6.5 more than the intended speed
  shooter_set(50); //Shoots and retracts the flywheel piston
  pros::delay(200);
  flywheel_until_speed(1,-3); //Lets the flywheel reach 11 more than the intended speed
  shooter_set(50); 
  pros::delay(50);

  set_flywheel_velocity(-400); //Reverses the flywheel to stop disks from flying out while intaking
  pros::delay(300);
  set_flywheel_velocity(0); //Stops the flywheel
  
  set_intake(127); //Starts the intake

  chassis.set_turn_pid(-110, 127); //turns toward the back disks
  chassis.wait_drive();

  chassis.set_drive_pid(-13, 127); //moves back to collect the first disk of the three
  chassis.wait_drive();

  // chassis.set_drive_pid(2, 127); //moves forward to align with the other two disks
  // chassis.wait_drive();

  chassis.set_turn_pid(-133, 127); //turns towards the other disks
  chassis.wait_drive();

  set_flywheel_velocity(468); //Starts the flywheel again
  chassis.set_drive_pid(-54, 127, false); //moves forward while intaking
  chassis.wait_drive();
  set_intake(-90); //Starts outtaking
  pros::delay(100);

  chassis.set_swing_pid(ez::RIGHT_SWING, -93, 127);
  chassis.wait_drive();

  // chassis.set_turn_pid(-90, 127); //Turn towards the final roller
  // chassis.wait_drive();
  // chassis.set_drive_pid(-5, 127, false); //Moves back towards the roller while outtaking
  // chassis.wait_drive();
  // pros::delay(10); //10ms wait to turn the roller

  chassis.set_drive_pid(4, 127, false); //Moves forward
  chassis.wait_drive();

  chassis.set_turn_pid(-81,127); //Turns towards goal
  chassis.wait_drive();

  flywheel_until_speed(1,2); //Flywheel routine
  shooter_set(50);
  pros::delay(100);
  flywheel_until_speed(1,-1);
  shooter_set(50); 
  pros::delay(100);
  flywheel_until_speed(1,0);
  shooter_set(50); 
  
  // chassis.set_drive_pid(0, HIGHER_SPEED, true); //Stops the robot
  // chassis.wait_drive();
}

void roller_auton(){
  chassis.set_drive_pid(-3, HIGHER_SPEED, false);
  chassis.wait_drive();

  intake(-127, 150);

  chassis.set_drive_pid(8.5, HIGHER_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(44, 110);
  chassis.wait_drive();

  chassis.set_drive_pid(64, 127, false);
  chassis.wait_until(30);
  set_flywheel_velocity(390);
  chassis.wait_drive();

  chassis.set_turn_pid(-48, HIGHER_TURN_SPEED);
  chassis.wait_drive();

  pros::delay(200);
  flywheel_until_speed(1,-6.5);
  shooter_set(50);
  pros::delay(200);
  flywheel_until_speed(1,-12);
  shooter_set(50); 
  pros::delay(100);

  set_flywheel_velocity(-100);
  pros::delay(700);
  set_flywheel_velocity(0);
  set_intake(127);

  chassis.set_turn_pid(-63, 110);
  chassis.wait_drive();

  chassis.set_drive_pid(-11, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(2, 127);
  chassis.wait_drive();

  chassis.set_turn_pid(-133, 110);
  chassis.wait_drive();

  set_flywheel_velocity(470);
  chassis.set_drive_pid(-16, 125, true);
  chassis.wait_drive();
  chassis.set_turn_pid(-47, 115);
  chassis.wait_drive();

  chassis.set_drive_pid(2.5, 127, false);
  chassis.wait_drive();

  // pros::delay(400);
  flywheel_until_speed(1,0);
  shooter_set(100);
  pros::delay(200);
  flywheel_until_speed(1,-1);
  shooter_set(100); 
  pros::delay(200);
  flywheel_until_speed(1,0);
  shooter_set(100); 
  
  chassis.set_drive_pid(0, HIGHER_SPEED, true);
  chassis.wait_drive();
}

// Drive Example
void skills_auton() {
  //Back Up
  chassis.set_drive_pid(-3, HIGHER_SPEED, false);
  chassis.wait_drive(); 

  intake(-127, 290);
  //Move 
  set_intake(127);
  chassis.set_drive_pid(10, HIGHER_SPEED, false);
  chassis.wait_drive();

  

  //Turn towards other Roller
  chassis.set_turn_pid(140, TURN_SPEED);
  chassis.wait_drive();
  
  chassis.set_drive_pid(-16.1, HIGHER_SPEED);
  chassis.wait_drive();
  pros::delay(195);
  set_intake(0);
  // set_intake(0);
  //Turn towards Other Roller
  chassis.set_turn_pid(90, 110);
  chassis.wait_drive();

  // set_intake(127); //Turn Intake to turn roller up
  chassis.set_drive_pid(-14, HIGHER_SPEED); //Back Up
  chassis.wait_drive();
  // pros::delay(100);
  
  intake(-127,290);

  //Move away from Roller
  // set_flywheel(122);
  // set_flywheel(106);
  chassis.set_drive_pid(10, HIGHER_SPEED);
  chassis.wait_drive();

  set_intake(120);
  chassis.set_turn_pid(0, 110);
  chassis.wait_drive();
  //FIRST SET
  set_flywheel_velocity(340);
  chassis.set_drive_pid(35, HIGHER_SPEED);
  chassis.wait_drive();
  set_intake(0);
  chassis.set_turn_pid(-5, 117);
  chassis.wait_drive();

  flywheel_until_speed(1,-5.5); //-2
  shooter_set(100);
  pros::delay(700);
  flywheel_until_speed(1,0); //2
  shooter_set(100);
  pros::delay(700);
  flywheel_until_speed(1,-6); //3
  shooter_set(100);
  
  set_flywheel(0);
  pros::delay(400);
  set_intake(0);

  chassis.set_turn_pid(0, 120);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, HIGHER_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-135, HIGHER_TURN_SPEED);
  chassis.wait_drive();

  set_intake(123);
  chassis.set_drive_pid(-68, 102);

  chassis.wait_drive(); 
  pros::delay(100);
  //SECOND SET
  set_flywheel_velocity(340);
  chassis.set_turn_pid(-57, HIGHER_TURN_SPEED);
  chassis.wait_drive();

  flywheel_until_speed(1,0); //-2
  shooter_set(100);
  pros::delay(700);
  flywheel_until_speed(1,0); //2
  shooter_set(100);
  pros::delay(700);
  flywheel_until_speed(1,0); //3
  shooter_set(100);
  
  set_flywheel(0);
  pros::delay(400);
  set_intake(0);

  chassis.set_turn_pid(-139, TURN_SPEED);
  chassis.wait_drive();
  // set_flywheel(0);
  // set_intake(-127);
  chassis.set_drive_pid(-23, 127);
  chassis.wait_drive();
  pros::delay(40);
  chassis.set_drive_pid(13, 123);
  chassis.wait_until(3);
  set_intake(127);
  chassis.wait_drive();
  

  chassis.set_drive_pid(-40, 30);
  chassis.wait_until(-38);
  chassis.set_max_speed(110);
  chassis.wait_drive();
  pros::delay(1000);
  set_intake(0);

  chassis.set_turn_pid(-90, 110);
  chassis.wait_drive();
  chassis.set_drive_pid(-7, 120);
  chassis.wait_drive();
  chassis.set_turn_pid(-180, 110);
  chassis.wait_drive();
  chassis.set_drive_pid(-7.8,120);
  chassis.wait_drive();

  intake(127, 350);

  chassis.set_drive_pid(4.5,100);
  chassis.wait_drive();
  pros::delay(100);
  chassis.set_turn_pid(-33, HIGHER_SPEED);
  chassis.wait_drive();
  

  chassis.set_drive_pid(-24, 120);
  chassis.wait_drive();

  chassis.set_drive_pid(2.5, 124);
  chassis.wait_drive();
  
  chassis.set_turn_pid(-90, HIGHER_TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-15.8, HIGHER_SPEED);
  chassis.wait_drive();
  //FOURTH ROLLER
  intake(-127,400);

  chassis.set_drive_pid(10.5, HIGHER_SPEED);
  chassis.wait_drive();
  set_intake(0);

  chassis.set_turn_pid(-180, 110);
  chassis.wait_drive();

  set_flywheel_velocity(346);
  chassis.set_drive_pid(35, HIGHER_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-183, 115);
  chassis.wait_drive();

  //THIRD SET
  flywheel_until_speed(1,-4); //-2
  shooter_set(50);
  pros::delay(800);
  flywheel_until_speed(1,0); //2
  shooter_set(50);
  pros::delay(800);
  flywheel_until_speed(1,0); //3
  shooter_set(50);
  
  set_flywheel(0);
  pros::delay(403);
  set_intake(0);

  chassis.set_drive_pid(-21, HIGHER_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(45, 110);
  chassis.wait_drive();

  set_intake(120);
  chassis.set_drive_pid(-70, 120);
  chassis.wait_drive(); 
  

  set_flywheel_velocity(340);
  chassis.set_turn_pid(120, 115);
  chassis.wait_drive();
  
  //FOURTH SET
  flywheel_until_speed(1,-2); //-2
  shooter_set(50);
  pros::delay(700);
  flywheel_until_speed(1,0); //2
  shooter_set(50);
  pros::delay(700);
  flywheel_until_speed(1,0); //3
  shooter_set(50);
  set_intake(0);
  
  set_flywheel(0);
  // pros::delay(400);
  set_intake(-127);

  chassis.set_turn_pid(90, 120);
  chassis.wait_drive();

  chassis.set_drive_pid(-21, 127);
  chassis.wait_drive();
  pros::delay(100);
  chassis.set_turn_pid(-135, HIGHER_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(46,125, true);
  chassis.wait_drive();
 
  deploylaunch();
}
// Turn Example
void disc_auton() {

  set_intake(127);
  //Starts Intake
  set_flywheel_velocity(422);
  chassis.set_drive_pid(-27.5, HIGHER_SPEED, false); //Moves back while intaking to take disks
  chassis.wait_drive(); //Delay for drive to move.
  
  chassis.set_turn_pid(-153.5, HIGHER_TURN_SPEED); //Turns towards the goal
  chassis.wait_drive();
  pros::delay(100);
  set_intake(0);
  //FIRST SET OF SHOTS
  // pros::delay(200);
  flywheel_until_speed(1,0);
  shooter_set(50);
  pros::delay(70);
  flywheel_until_speed(1,0);
  shooter_set(50);
  pros::delay(70);
  flywheel_until_speed(1,0);
  shooter_set(70); 
  set_flywheel_velocity(0);
  set_flywheel(0);
  pros::delay(100);

  //Drives Backwards
  chassis.set_drive_pid(-25, 127);
  chassis.wait_drive();

  //Turns backwards
  chassis.set_turn_pid(-270, 127);
  chassis.wait_drive();
  
  //Drives towards rollers
  chassis.set_drive_pid(-35, 127);
  chassis.wait_drive();

  set_intake(-60); //Starts intake for rollers
  chassis.set_turn_pid(-180, 127);
  chassis.wait_drive();
  
  chassis.set_drive_pid(-13.5, 127); // Backup into roller
  chassis.wait_drive();
  // pros::delay(50);

  chassis.set_drive_pid(5, 127);
  chassis.wait_drive();

  set_intake(127);// Starts intake for row of disk
  chassis.set_turn_pid(-46, 115); //Turns towards discs
  chassis.wait_drive();
  chassis.set_drive_pid(-63, 123, false); //Drives into discs
  chassis.wait_until(-40);
  set_flywheel_velocity(422); //Starts flywheel
  chassis.wait_drive();

  chassis.set_turn_pid(-138, 120); //Turns towards goals
  chassis.wait_drive();

  //SECOND SET OF SHOTS
  flywheel_until_speed(1,0);
  shooter_set(50);
  // pros::delay(50);
  flywheel_until_speed(1,-1);
  shooter_set(50);
  pros::delay(400);
  set_flywheel_velocity(0);
  set_intake(0);
  // chassis.set_turn_pid(136, 110);
  // chassis.wait_drive();
  
  // chassis.set_drive_pid(-77, 127);
  // chassis.wait_drive();
  // set_intake(-100);
  // // chassis.set_swing_pid(RIGHT_SWING, 183, 127);
  // chassis.set_turn_pid(180, 127);
  // chassis.wait_drive();

  // chassis.set_drive_pid(-7.5, 127);
  // chassis.wait_drive();
  // pros::delay(20);
  // set_intake(0);


  // chassis.set_turn_pid(-180, 120);
  // chassis.wait_drive();
  
}

void testauton(){
  set_flywheel_velocity(400);
  flywheel_until_speed(1, 0);
  shooter_set(100);
  flywheelmotor.move_velocity(flywheelmotor.get_target_velocity()+1);
  flywheel_until_speed(1, 0);
  shooter_set(100);
  flywheelmotor.move_velocity(flywheelmotor.get_target_velocity()+1);
  flywheel_until_speed(1, 0);
  shooter_set(100);
}

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}