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

void wp_auton() {
  //set_drive_pid(Distance, Max_Speed, enabling a slew)
  chassis.set_drive_pid(-2, DRIVE_SPEED, false);
  chassis.wait_drive(); //Delay for drive to move.

  intake(-127, 500);

  chassis.set_drive_pid(10, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(63, HIGHER_SPEED, false);
  chassis.wait_until(30);
  set_flywheel(112);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(0,0);
  chassis.wait_drive();

  pros::delay(300);
  shooter_set(100);
  pros::delay(980);
  shooter_set(100); 
  pros::delay(100);
  set_flywheel(0);

  set_intake(-117);
  chassis.set_drive_pid(-5, HIGHER_SPEED);
  chassis.wait_drive();
  
  chassis.set_turn_pid(-138, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-71, HIGHER_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-9, HIGHER_SPEED, false);
  chassis.wait_drive(); //Delay for drive to move.

  intake(-127, 600);

  chassis.set_drive_pid(0, HIGHER_SPEED, true);
  chassis.wait_drive();
}



// Drive Example
void skills_auton() {
  //Back Up
  chassis.set_drive_pid(-2, DRIVE_SPEED, false);
  chassis.wait_drive(); 

  intake(-127, 200);
  //Move 
  chassis.set_drive_pid(10, DRIVE_SPEED, false);
  chassis.wait_drive();

  set_intake(127);

  //Turn towards other Roller
  chassis.set_turn_pid(140, TURN_SPEED);
  chassis.wait_drive();
  
  chassis.set_drive_pid(-19, DRIVE_SPEED);
  chassis.wait_drive();
  pros::delay(500);

  // set_intake(0);
  //Turn towards Other Roller
  chassis.set_turn_pid(90, 110);
  chassis.wait_drive();

  // set_intake(127); //Turn Intake to turn roller up
  chassis.set_drive_pid(-10, HIGHER_SPEED); //Back Up
  chassis.wait_drive();
  pros::delay(100);
  

  //Move away from Roller
  // set_flywheel(122);
  
  chassis.set_drive_pid(10, HIGHER_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-3, 110);
  chassis.wait_drive();
  // set_intake(127);
  // chassis.set_drive_pid(60, HIGHER_SPEED);
  // chassis.wait_drive();
  // set_intake(0);
  // chassis.set_drive_pid(6, HIGHER_SPEED);
  // chassis.wait_drive();
  set_intake(110);
  pros::delay(200);
  shooter_set(200);
  pros::delay(800);
  shooter_set(200);
  pros::delay(800);
  shooter_set(200);
  set_flywheel(0);
  pros::delay(400);
  set_intake(0);

  // chassis.set_drive_pid(-6, HIGHER_SPEED);
  // chassis.wait_drive();
  
  chassis.set_turn_pid(0, 120);
  chassis.wait_drive();

  chassis.set_drive_pid(12, HIGHER_SPEED);//used to be -48
  chassis.wait_drive();  

  chassis.set_turn_pid(-135, TURN_SPEED);
  chassis.wait_drive();

  set_intake(120);
  chassis.set_drive_pid(-70, 55);
  chassis.wait_until(-60);
  // set_intake(0);
  // set_intake(120);
  chassis.wait_drive(); 
  pros::delay(1000);
  // set_intake(0);
  // set_intake(120);
  set_flywheel(108);
  chassis.set_turn_pid(-60, TURN_SPEED);
  chassis.wait_drive();

  pros::delay(200);
  shooter_set(300);
  pros::delay(300);
  shooter_set(300);
  pros::delay(260);
  shooter_set(300);
  set_flywheel(-70);
  // set_intake(0);

  chassis.set_turn_pid(-60, TURN_SPEED);
  chassis.wait_drive();
  set_flywheel(0);
  set_intake(100);
  chassis.set_drive_pid(-22, DRIVE_SPEED);
  chassis.wait_drive(); 
  pros::delay(200);
  chassis.set_drive_pid(6, DRIVE_SPEED);
  chassis.wait_drive(); 
  set_intake(127);

  chassis.set_turn_pid(-135, TURN_SPEED);
  chassis.wait_drive();
  
  chassis.set_drive_pid(-25, 70);
  chassis.wait_drive(); 
  // pros::delay(100);
  // chassis.set_drive_pid(-9, 70);
  // chassis.wait_drive();  

  pros::delay(500);
  set_intake(-127);
  chassis.set_drive_pid(-30, 80);
  chassis.wait_drive(); 
  set_intake(0);
  
  chassis.set_drive_pid(18, 80);
  chassis.wait_drive(); 
  // intake(127, 500);
  set_intake(127);
  chassis.set_turn_pid(-180, 110);
  pros::delay(200);

  chassis.set_drive_pid(-19, DRIVE_SPEED, true);
  chassis.wait_drive(); 
  pros::delay(100);

  chassis.set_drive_pid(26, DRIVE_SPEED, false);  
  chassis.wait_drive();
  pros::delay(500);

  set_intake(-127);
  //Turn towards Other Roller
  chassis.set_turn_pid(-90, 110);
  chassis.wait_drive();

  // set_intake(127); //Turn Intake to turn roller up
  chassis.set_drive_pid(-21, HIGHER_SPEED); //Back Up
  chassis.wait_drive();
  pros::delay(100);

  chassis.set_drive_pid(20, HIGHER_SPEED); //Back Up
  chassis.wait_drive();  
  

}
// Turn Example
void disc_auton() {
  chassis.set_drive_pid(-2, DRIVE_SPEED, false);
  chassis.wait_drive(); //Delay for drive to move.

  intake(-127, 500);

  chassis.set_drive_pid(2, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-130, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-55, DRIVE_SPEED, true);
  chassis.wait_until(-45);
  set_intake(127);
  chassis.wait_drive();
  set_intake(0);

  set_intake(127);
  chassis.set_drive_pid(-10, DRIVE_SPEED, false);
  chassis.wait_drive();
  set_intake(0);

  set_intake(127);
  chassis.set_drive_pid(-10, DRIVE_SPEED, false);
  chassis.wait_drive();
  set_intake(0);
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