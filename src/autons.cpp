#include "main.h"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 110; // 110/127; Recommended Constant for Driving. 
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;
const int HIGHER_SPEED = 120;

void test_auton() {
  //set_drive_pid(Distance, Max_Speed, enabling a slew)
  chassis.set_drive_pid(-2, DRIVE_SPEED, false);
  chassis.wait_drive(); //Delay for drive to move.

  intake(-127, 500);

  chassis.set_drive_pid(10, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(66, DRIVE_SPEED, true);
  chassis.wait_until(40);
  set_flywheel(127);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();
  set_flywheel(0);

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(40, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_drive_pid(0, DRIVE_SPEED, true);
  chassis.wait_drive();
  
}



// Drive Example
void drive_example() {
  
}
// Turn Example
void turn_example() {
  chassis.set_drive_pid(-2, DRIVE_SPEED, false);
  chassis.wait_drive(); //Delay for drive to move.

  intake(-127, 500);

  chassis.set_drive_pid(2, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-130, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-80, DRIVE_SPEED, true);
  chassis.wait_until(-45);
  set_intake(127);
  chassis.wait_drive();
}

// Constants definitions as of EZ-Template
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