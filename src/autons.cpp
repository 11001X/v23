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
void roller_auton(){
  chassis.set_drive_pid(-2, HIGHER_SPEED, false);
  chassis.wait_drive(); 

  //Outtakes to turn the roller up
  intake(-127, 300);
}
// Drive Example
void skills_auton() {
  disc_constants();
  set_flywheel(96);
  chassis.set_drive_pid(-1.5, HIGHER_SPEED, false);
  chassis.wait_drive(); 

  //Outtakes to turn the roller up
  intake(127, 300);
  set_intake(127);
  chassis.set_swing_pid(ez::RIGHT_SWING, -40, TURN_SPEED);
  chassis.wait_drive(); 

  chassis.set_drive_pid(10, HIGHER_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(90, 110);
  chassis.wait_drive();
  set_intake(0);


  chassis.set_drive_pid(-6, HIGHER_SPEED);
  chassis.wait_drive();

  intake(127, 250);

  chassis.set_drive_pid(2, HIGHER_SPEED);
  chassis.wait_drive();

  set_intake(127);
  chassis.set_turn_pid(0, 110);
  chassis.wait_drive();
  
  angler.set_value(true);

  chassis.set_drive_pid(31, 127);
  chassis.wait_until(15);
  set_intake(0);
  chassis.wait_drive();
  
  chassis.set_turn_pid(11, 110);
  chassis.wait_drive();

  //first set of shots
  intake(-127, 400);
  set_flywheel(125);
  intake(-127, 400);
  set_flywheel(127);
  pros::delay(300);
  intake(-127, 900);
  set_flywheel(0);
  set_flywheel(106);
  angler.set_value(false);

  chassis.set_turn_pid(0, HIGHER_TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-31, HIGHER_SPEED);
  chassis.wait_drive();
  set_intake(127);
  chassis.set_turn_pid(40, HIGHER_TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(44, HIGHER_SPEED);
  chassis.wait_drive();

  pros::delay(400);
  set_intake(0);
  chassis.set_turn_pid(-46, HIGHER_TURN_SPEED);
  chassis.wait_drive();
  
  
  //second set of shots
  intake(-127, 400);
  set_flywheel(123);
  pros::delay(300);
  intake(-127, 400);
  set_flywheel(127);
  pros::delay(200);
  intake(-127, 550);
  set_flywheel(104);

   
  chassis.set_turn_pid(45, HIGHER_TURN_SPEED);
  chassis.wait_drive();

  //1st 3Stack Intaking
  set_intake(127);

  intakepiston.set_value(true);

  chassis.set_drive_pid(11.70, HIGHER_SPEED);
  chassis.wait_drive();

  intakepiston.set_value(false);

  chassis.set_drive_pid(7.5, DRIVE_SPEED);
  chassis.wait_drive();

  pros::delay(800);

  chassis.set_turn_pid(-75, HIGHER_TURN_SPEED);
  chassis.wait_drive();

  //shoot 3rd set
  // flywheelPIDWait(108,18);
  // intake(-127, 400);
  // set_flywheel(92);
  // pros::delay(100);
  // flywheelPIDWait(92, 10);
  // set_flywheel(112);
  // pros::delay(400);
  // flywheelPIDWait(112, 15);
  // intake(-127, 1300);

  intake(-127, 400);
  set_flywheel(123);
  pros::delay(300);
  intake(-127, 400);
  set_flywheel(127);
  pros::delay(200);
  intake(-127, 400);

  chassis.set_turn_pid(85, HIGHER_TURN_SPEED);
  chassis.wait_drive();

  //2nd 3Stack Intaking
  intakepiston.set_value(true);

  set_intake(127);

  chassis.set_drive_pid(8, 110);
  chassis.wait_drive();

  intakepiston.set_value(false);
  set_flywheel(98);
  chassis.set_drive_pid(7.5, 95);
  chassis.wait_drive();

  pros::delay(1000);

  chassis.set_turn_pid(-78, HIGHER_TURN_SPEED);
  chassis.wait_drive();
  

  //put up angler for closerange shooting of 2nd 3 stack
  angler.set_value(true);
  
  chassis.set_drive_pid(28, HIGHER_SPEED);
  chassis.wait_until(12);
  set_intake(0);
  chassis.wait_drive();

 
  //4th set of shots shooting
  intake(-127, 400);
  set_flywheel(108);
  intake(-127, 300);
  set_flywheel(112);
  pros::delay(700);
  intake(-127, 550);
  set_flywheel(0);
  // set_flywheel(110);
  angler.set_value(false);

  chassis.set_drive_pid(-24, HIGHER_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-97, HIGHER_TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-18.25, 80, false);
  chassis.wait_drive();

  //3rd roller
  intake(127, 780);

  chassis.set_drive_pid(14.5, HIGHER_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-180, HIGHER_TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-14.25, 85, false);
  chassis.wait_drive();
  //4th Roller
  intake(127, 400);
  
  set_intake(127);

  set_flywheel(106);

  //Move towards line of three on the next side
  chassis.set_swing_pid(ez::LEFT_SWING, -175, 110);
  chassis.wait_drive();
   
  chassis.set_drive_pid(27, 120);
  chassis.wait_drive();

  chassis.set_turn_pid(-135, HIGHER_TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(25, 120);
  chassis.wait_drive();

  chassis.set_turn_pid(-226.5, HIGHER_TURN_SPEED);
  chassis.wait_drive();
  
  //5th set of shots
  // flywheelPIDWait(106,15);
  // intake(-127, 400);
  // set_flywheel(114);
  // flywheelPIDWait(114, 12);
  // intake(-127, 1100);
  // set_flywheel(104);

  intake(-127, 400);
  set_flywheel(123);
  pros::delay(300);
  intake(-127, 400);
  set_flywheel(127);
  pros::delay(200);
  intake(-127, 550);
  set_flywheel(104);


  chassis.set_turn_pid(-132, HIGHER_TURN_SPEED);
  chassis.wait_drive();

  // intake 3rd 3Stack
  set_intake(127);

  intakepiston.set_value(true);

  chassis.set_drive_pid(12, HIGHER_SPEED);
  chassis.wait_drive();

  intakepiston.set_value(false);

  chassis.set_drive_pid(6, DRIVE_SPEED);
  chassis.wait_drive();

  pros::delay(850);
  

  chassis.set_turn_pid(-255, HIGHER_TURN_SPEED);
  chassis.wait_drive();
  set_intake(0);
  pros::delay(100);

  //6th set of shots
  // flywheelPIDWait(104,18);
  // intake(-127, 400);
  // set_flywheel(90);
  // pros::delay(100);
  // flywheelPIDWait(90, 15);
  // set_flywheel(97);
  // pros::delay(200);
  // flywheelPIDWait(97, 15);
  // intake(-127, 1400);
  intake(-127, 400);
  set_flywheel(123);
  pros::delay(300);
  intake(-127, 400);
  set_flywheel(127);
  pros::delay(200);
  intake(-127, 400);
  set_flywheel(118);


  chassis.set_turn_pid(-87, HIGHER_TURN_SPEED);
  chassis.wait_drive();
  set_intake(127);

  //Intake 4th 3Stack
  intakepiston.set_value(true);

  chassis.set_drive_pid(5.5, 112);
  chassis.wait_drive();
  pros::delay(100);

  intakepiston.set_value(false);
  
  set_flywheel(98);
  chassis.set_drive_pid(7.5, 90);
  chassis.wait_drive();

  pros::delay(700);

  // chassis.set_turn_pid(102, HIGHER_TURN_SPEED);
  // chassis.wait_drive();

  chassis.set_turn_pid(102, HIGHER_TURN_SPEED);
  chassis.wait_drive();
  
  chassis.set_drive_pid(3, HIGHER_SPEED);
  chassis.wait_drive();
  set_intake(0);

  // angler.set_value(true);

  // chassis.set_drive_pid(26.5, HIGHER_SPEED);
  // chassis.wait_drive();
  // set_intake(0);

  //7th set
  // intake(-127, 400);
  // set_flywheel(108);
  // intake(-127, 300);
  // set_flywheel(112);
  // pros::delay(700);
  // intake(-127, 550);
  // set_flywheel(0);

  intake(-127, 400);
  set_flywheel(124);
  pros::delay(200);
  intake(-127, 300);
  set_flywheel(127);
  pros::delay(700);
  intake(-127, 650);

  

  // chassis.set_drive_pid(-25, 127);
  // chassis.wait_drive();

  chassis.set_turn_pid(45, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(-15, 127);
  chassis.wait_drive();

  launcher1.set_value(true);

}
// Turn Example
void disc_auton() {
  chassis.set_drive_brake(pros::E_MOTOR_BRAKE_HOLD);

  set_flywheel(127);
  set_intake(127);
  chassis.set_drive_pid(10, 127, false);
  chassis.wait_drive(); 
  pros::delay(500);
  set_intake(0);

  flywheelPIDWait(114);
  intake(-127, 400);
  flywheelPIDWait(116);
  intake(-127, 300);
  pros::delay(100);
  flywheelPIDWait(115);
  intake(-127, 500);
  set_intake(127);
  set_flywheel(0);
  set_flywheel(127);

  chassis.set_turn_pid(15, 127);
  chassis.wait_drive(); 

  chassis.set_drive_pid(8, 127);
  chassis.wait_drive();
  pros::delay(100);

  chassis.set_drive_pid(-4, 127);
  chassis.wait_drive();
  

  chassis.set_turn_pid(-70, 125);
  chassis.wait_drive(); 

  chassis.set_drive_pid(9, 127); //NEW 
  chassis.wait_drive(); //NEW 
  pros::delay(100);
  
  
  chassis.set_drive_pid(-30, 127);
  chassis.wait_drive();
  set_intake(0);
  chassis.set_turn_pid(-22, 124);
  chassis.wait_drive();

  chassis.set_drive_pid(-2, 127);
  chassis.wait_drive();
  intake(-127, 150);
  chassis.set_swing_pid(ez::LEFT_SWING, -14, 127);
  chassis.wait_drive();
  // chassis.set_drive_pid(2, 127);
  // chassis.wait_drive();
  intake(-127, 400);
  // flywheelPIDWait(116);
  // intake(-127, 300);
 
}

void test_auton(){
  // myChassis->moveDistanceAsync(10_in);

  profileController->generatePath(
    {
      {0_ft, 0_ft, 0_deg}, 
      {1_ft, 1_ft, 0_deg}
    }, "A");
  profileController->setTarget("A");
  profileController->waitUntilSettled();
}

void newwp_auton(){
  chassis.set_drive_brake(pros::E_MOTOR_BRAKE_HOLD);
  //Backs up to roll the first roller at 120
  chassis.set_drive_pid(-2, HIGHER_SPEED, false);
  chassis.wait_drive(); 
  intakepiston.set_value(true);
  
  //Outtakes to turn the roller up
  intake(-127, 200);

  //Moves forward for 6 inches
  chassis.set_drive_pid(2, 127, false);
  chassis.wait_drive();

  chassis.set_turn_pid(51, 120);
  chassis.wait_drive();
  set_intake(127);
  set_flywheel(127);
  chassis.set_drive_pid(16, 127, false);
  chassis.wait_drive();
  chassis.set_drive_pid(16, 60, false);
  chassis.wait_until(4);
  intakepiston.set_value(false);
  chassis.wait_drive();
  chassis.set_turn_pid(-31.5, 127);
  chassis.wait_drive();
  pros::delay(200);
  set_intake(0);
  flywheelPIDWait(118);
  intake(-127, 500);
  // pros::delay(500);
  flywheelPIDWait(104);
  // pros::delay(100);
  intake(-127, 500);
  pros::delay(200);
  flywheelPIDWait(106);
  intake(-127, 500);
  set_intake(127);
  set_flywheel(127);
  chassis.set_turn_pid(45, 127);
  chassis.wait_drive();
  
  chassis.set_drive_pid(46, 127, false);
  chassis.wait_drive();
  chassis.set_turn_pid(-143, 127);
  chassis.wait_drive();
  set_intake(0);
  // set_intake(-127);
  chassis.set_drive_pid(-2.75, 127, false);
  // chassis.wait_until(-5);
  // chassis.set_max_speed(40);
  chassis.wait_drive();
  

  chassis.set_swing_pid(ez::RIGHT_SWING, -90, 127);
  chassis.wait_drive();
  
  chassis.set_drive_pid(-2.5, 127, false);
  chassis.wait_drive();
  
  intake(-127,150);
  // set_intake(-127);
  chassis.set_swing_pid(ez::LEFT_SWING, -82.5, 127);
  chassis.wait_drive();
  flywheelPIDWait(123);
  intake(-127,300);
  // pros::delay(100);
  // intake(-127,300);
  // pros::delay(100);
  // intake(-127,300);
  
  
}

void default_constants() {
  chassis.set_slew_min_power(120, 120);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 13.75, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void disc_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 16, 0, 25, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 7, 0.003, 38, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

// void disc_constants() {
//   chassis.set_slew_min_power(120, 120);
//   chassis.set_slew_distance(7, 7);
//   chassis.set_pid_constants(&chassis.headingPID, 16, 0, 20, 0);
//   chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
//   chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
//   chassis.set_pid_constants(&chassis.turnPID, 8, 0.003, 35, 15);
//   chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
// }

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}