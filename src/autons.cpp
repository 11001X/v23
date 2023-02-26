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
  // chassis.set_drive_pid(10, );
}
// Drive Example
void skills_auton() {
  
}
// Turn Example
void disc_auton() {
  // disc_constants();
  chassis.set_drive_brake(pros::E_MOTOR_BRAKE_HOLD);

  set_flywheel(127);
  set_intake(127);
  chassis.set_drive_pid(10, 127, false);
  chassis.wait_drive(); 
  pros::delay(600);
  set_intake(0);

  flywheelPIDWait(105);

  intake(-127, 600);
  // pros::delay(500);
  flywheelPIDWait(106);
  // pros::delay(100);
  intake(-127, 600);
  // pros::delay(500);
  flywheelPIDWait(115);
  // // vision_align();
  // flywheelPIDWait(105);
  // // pros::delay(200);
  // // flywheel_until_speed(1,0);
  // intake(-127, 300);
  // // pros::delay(300);
  // // flywheel_until_speed(1,0);
  // flywheelPIDWait(106);
  // intake(-127, 300);
  // // pros::delay(500);
  // // flywheel_until_speed
  // flywheelPIDWait(115);
  intake(-127, 400);
  set_intake(127);

  chassis.set_turn_pid(10, 127);
  chassis.wait_drive(); 

  chassis.set_drive_pid(8, 127);
  chassis.wait_drive();
  pros::delay(100);

  chassis.set_drive_pid(-4, 127);
  chassis.wait_drive();

  chassis.set_turn_pid(-70, 125);
  chassis.wait_drive(); 

  set_flywheel(0);

  set_intake(0);
  // set_flywheel(120);

    // chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);

  chassis.set_drive_pid(-21, 127);
  chassis.wait_until(-16);
  chassis.set_max_speed(80);
  chassis.wait_drive();

  chassis.set_turn_pid(-22, 120);
  chassis.wait_drive();

  chassis.set_drive_pid(-2, 127);
  chassis.wait_drive();
  intake(-127, 300);
  set_flywheel(127);
  chassis.set_swing_pid(ez::RIGHT_SWING, -73, 127);
  chassis.wait_drive();

  set_intake(127);
  chassis.set_drive_pid(36, 127);
  chassis.wait_drive();
  
  chassis.set_turn_pid(20, 120);
  chassis.wait_drive();
  // chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
  // chassis.set_drive_pid(-32, 127, false);
  // chassis.wait_drive();
  // chassis.set_drive_pid(-6, 80, false);
  // chassis.wait_drive();

  // chassis.set_turn_pid(-90, 127);
  // chassis.wait_drive();

  // chassis.set_drive_pid(-2, 127, false);
  // chassis.wait_drive();


  // // vision_align();
  intake(-127,200);
  pros::delay(100);
  intake(-127,200);
  pros::delay(100);
  intake(-127,200);
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
  set_flywheel(117);
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
  intake(-127, 600);
  // pros::delay(500);
  flywheelPIDWait(100);
  // pros::delay(100);
  intake(-127, 600);
  // pros::delay(500);
  flywheelPIDWait(105);
  intake(-127, 700);
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
  
  chassis.set_drive_pid(-1, 127, false);
  chassis.wait_drive();
  
  intake(-127,200);
  set_intake(-127);
  chassis.set_swing_pid(ez::LEFT_SWING, -82.5, 127);
  chassis.wait_drive();
  intake(-127,300);
  pros::delay(100);
  intake(-127,300);
  pros::delay(100);
  intake(-127,300);
  
  
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