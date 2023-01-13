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
  chassis.set_drive_pid(-3, HIGHER_SPEED, false);
  chassis.wait_drive(); //Delay for drive to move.

  intake(-127, 150);

  chassis.set_drive_pid(9, HIGHER_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(44, HIGHER_TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(63, HIGHER_SPEED, false);
  chassis.wait_until(30);
  set_flywheel_velocity(400);
  chassis.wait_drive();

  chassis.set_turn_pid(-47, HIGHER_TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(0,0);
  chassis.wait_drive();

  pros::delay(200);
  flywheel_until_speed(1,-1.5);
  shooter_set(100);
  pros::delay(200);
  flywheel_until_speed(1,-1.5);
  shooter_set(100); 
  
  set_flywheel(0);
  pros::delay(600);

  set_intake(127);

  chassis.set_turn_pid(-65, HIGHER_TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-9, HIGHER_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(2, HIGHER_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-133, HIGHER_TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-53, HIGHER_SPEED, false);
  chassis.wait_drive();
  
  chassis.set_turn_pid(-180, HIGHER_TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-10, HIGHER_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, HIGHER_TURN_SPEED);
  chassis.wait_drive();

  // chassis.set_turn_pid(-90, TURN_SPEED);
  // chassis.wait_drive();
  set_intake(-127);
  // chassis.set_swing_pid(RIGHT_SWING, -92, 120);
  // chassis.wait_drive();
  chassis.set_drive_pid(-11.25, HIGHER_SPEED);
  chassis.wait_drive();
  set_flywheel_velocity(465);
  
  // chassis.set_drive_pid(-6.5, HIGHER_SPEED, false);
  // chassis.wait_drive(); //Delay for drive to move.
  pros::delay(30);
  

  chassis.set_drive_pid(2, HIGHER_SPEED, true);
  chassis.wait_drive();

  chassis.set_swing_pid(LEFT_SWING, -83,127);

  // pros::delay(400);
  flywheel_until_speed(1,0);
  shooter_set(100);
  pros::delay(200);
  flywheel_until_speed(1,-1.5);
  shooter_set(100); 
  pros::delay(200);
  flywheel_until_speed(1,-1.5);
  shooter_set(100); 
  
  chassis.set_drive_pid(0, HIGHER_SPEED, true);
  chassis.wait_drive();
}



// Drive Example
void skills_auton() {
  //Back Up
  chassis.set_drive_pid(-3, DRIVE_SPEED, false);
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
  chassis.set_drive_pid(-12.5, HIGHER_SPEED); //Back Up
  chassis.wait_drive();
  // pros::delay(100);
  

  //Move away from Roller
  // set_flywheel(122);
  // set_flywheel(106);
  chassis.set_drive_pid(10, HIGHER_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, 110);
  chassis.wait_drive();
  //FIRST SET
  set_flywheel_velocity(333);
  chassis.set_drive_pid(35, HIGHER_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-5, HIGHER_SPEED);
  chassis.wait_drive();

  flywheel_until_speed(1,0); //-2
  shooter_set(100);
  // set_flywheel_velocity(405);
  pros::delay(1000);
  flywheel_until_speed(1,0); //2
  shooter_set(100);
  pros::delay(1000);
  flywheel_until_speed(1,-1); //3
  shooter_set(1000);
  
  set_flywheel(0);
  pros::delay(400);
  set_intake(0);

  chassis.set_turn_pid(0, 120);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, HIGHER_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-135, TURN_SPEED);
  chassis.wait_drive();

  set_intake(120);
  chassis.set_drive_pid(-70, 55);
  chassis.wait_until(-60);
  // set_intake(0);
  // set_intake(120);
  chassis.wait_drive(); 
  pros::delay(100);
  //SECOND SET
  set_flywheel_velocity(337);
  chassis.set_turn_pid(-65, TURN_SPEED);
  chassis.wait_drive();

  pros::delay(1000);

  flywheel_until_speed(1,0);
  shooter_set(100);

  pros::delay(1000);

  flywheel_until_speed(1,-1);
  shooter_set(100);
  pros::delay(1000);

  flywheel_until_speed(1,0);
  shooter_set(100);
  set_flywheel_velocity(0);
  pros::delay(1500);
  // set_intake(0);

  chassis.set_turn_pid(-136, TURN_SPEED);
  chassis.wait_drive();
  // set_flywheel(0);
  set_intake(-127);
  chassis.set_drive_pid(-13, 127);
  chassis.wait_drive();
  pros::delay(100);
  chassis.set_drive_pid(8, HIGHER_SPEED);
  chassis.wait_until(3);
  set_intake(127);
  chassis.wait_drive();
  

  chassis.set_drive_pid(-42, 40);
  chassis.wait_until(-34);
  chassis.set_max_speed(110);
  chassis.wait_until(-40);
  pros::delay(1000);
  set_intake(0);
  chassis.wait_drive();
  chassis.set_swing_pid(LEFT_SWING, -182, 100);
  intake(127, 500);

  chassis.set_drive_pid(4,100);
  chassis.wait_drive();
  pros::delay(100);
  chassis.set_turn_pid(-33, TURN_SPEED);
  chassis.wait_drive();
  
  set_intake(-127);

  chassis.set_drive_pid(-20, 110);
  chassis.wait_drive();
  
  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-16, HIGHER_SPEED);
  chassis.wait_drive();

  pros::delay(50);

  chassis.set_drive_pid(10, HIGHER_SPEED);
  chassis.wait_drive();
  set_intake(0);

  chassis.set_turn_pid(-180, 110);
  chassis.wait_drive();

  set_flywheel_velocity(335);
  chassis.set_drive_pid(35, HIGHER_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-183, 110);
  chassis.wait_drive();

  flywheel_until_speed(1,0); //-2
  shooter_set(100);
  // set_flywheel_velocity(405);
  pros::delay(1000);
  flywheel_until_speed(1,-1); //2
  shooter_set(100);
  pros::delay(1000);
  flywheel_until_speed(1,0); //3
  shooter_set(1000);
  
  set_flywheel(0);
  pros::delay(400);
  set_intake(0);

  chassis.set_drive_pid(-24, HIGHER_SPEED);
  chassis.wait_drive();


  // chassis.set_drive_pid(1)

  // // chassis.set_drive_pid(-9, 70);
  // // chassis.wait_drive();  

  // pros::delay(500);
  // set_intake(-127);
  // chassis.set_drive_pid(-30, 80);
  // chassis.wait_drive(); 
  // set_intake(0);
  
  // chassis.set_drive_pid(18, 80);
  // chassis.wait_drive(); 
  // // intake(127, 500);
  // set_intake(127);
  // chassis.set_turn_pid(-180, 110);
  // pros::delay(200);

  // chassis.set_drive_pid(-19, DRIVE_SPEED, true);
  // chassis.wait_drive(); 
  // pros::delay(100);

  // chassis.set_drive_pid(26, DRIVE_SPEED, false);  
  // chassis.wait_drive();
  // pros::delay(500);

  // set_intake(-127);
  // //Turn towards Other Roller
  // chassis.set_turn_pid(-90, 110);
  // chassis.wait_drive();

  // // set_intake(127); //Turn Intake to turn roller up
  // chassis.set_drive_pid(-21, HIGHER_SPEED); //Back Up
  // chassis.wait_drive();
  // pros::delay(100);

  // chassis.set_drive_pid(20, HIGHER_SPEED); //Back Up
  // chassis.wait_drive();  
  

}
// Turn Example
void disc_auton() {
  set_intake(127);
  set_flywheel_velocity(423);
  chassis.set_drive_pid(-27.5, DRIVE_SPEED, false);
  chassis.wait_drive(); //Delay for drive to move.
  set_intake(0);
  chassis.set_turn_pid(-156, HIGHER_TURN_SPEED);
  chassis.wait_drive();

  flywheel_until_speed(1,0);
  pros::delay(200);
  shooter_set(100);
  flywheel_until_speed(1,-1);
  shooter_set(100);
  pros::delay(100);
  flywheel_until_speed(1,0);
  shooter_set(100);
  set_flywheel_velocity(0);

  set_intake(127);

  chassis.set_drive_pid(-4, 127);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, HIGHER_TURN_SPEED);
  chassis.wait_drive();

  set_flywheel_velocity(400);
  chassis.set_drive_pid(-46, DRIVE_SPEED, false);
  chassis.wait_drive();
  set_intake(0);

  chassis.set_turn_pid(-130, HIGHER_TURN_SPEED);
  chassis.wait_drive();

  flywheel_until_speed(1,0);
  pros::delay(200);
  shooter_set(100);
  flywheel_until_speed(1,-1);
  shooter_set(100);
  set_flywheel_velocity(0);

  chassis.set_turn_pid(137, HIGHER_TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-75, 127);
  chassis.wait_drive();
  set_intake(-100);
  chassis.set_swing_pid(RIGHT_SWING, 183, 127);
  chassis.wait_drive();
  pros::delay(50);
  set_intake(0);


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