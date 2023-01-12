#include "main.h"
#include <bits/stdc++.h>
using namespace std;

using namespace ez;
/** 
main.cpp
Contains the definition to all the motors
Contains function definitions

Author's Note: Reversed means Left-sided 

------------------------------------------------
Controller: controller

Chassis - 4 Motor Drive; Left ports: 2, 5; Right ports: 3, 4; Right Reversed
    IMU - PORT 13, Wheel size: 4.125, RPM - 200, 1 External Gear Ratio
    
Lift - Singular Lift Motor: PORT:7, Gear ratio:18, Reversed: false

Flywheel Motor: PORT:10, Gear ratio:18, Reversed: false
Intake Motor: PORT:18, Gear ratio:18, Reversed: true

**/

pros::Controller controller(pros::E_CONTROLLER_MASTER);
Drive chassis ( {-1, 2, 12}, {3, -4, -18}, 5, 3.125, 200, 1);

pros::Motor flywheelmotor(17, pros::E_MOTOR_GEARSET_06, false);
pros::Motor intakemotor(10, pros::E_MOTOR_GEARSET_06, true);

#define SHOOTER_PORT 'A'

pros::ADIDigitalOut shooter(SHOOTER_PORT, false);

void initialize() {
  // Print our branding over your terminal :D
  ez::print_ez_template();
  
  pros::delay(500); // Stop the user from doing anything while legacy ports configure.
  // shooter.set_value(false);
  // Configure your chassis controls
  chassis.toggle_modify_curve_with_controller(true); // Enables modifying the controller curve with buttons on the joysticks
  chassis.set_active_brake(0); // Sets the active brake kP. We recommend 0.1.
  chassis.set_curve_default(0, 0); // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)  
  default_constants(); // Set the drive to your own constants from autons.cpp!
  exit_condition_defaults(); // Set the exit conditions to your own constants from autons.cpp!

  // Autonomous Selector using LLEMU
  ez::as::auton_selector.add_autons({
    Auton("Example Drive\n\nDrive forward and come back.", skills_auton),
    Auton("Example Turn\n\nTurn 3 times.", disc_auton)
  });

  // Initialize chassis and auton selector
  chassis.initialize();
  ez::as::initialize();
}



/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  // . . .
  shooter.set_value(false);
}

void competition_initialize() {
  // . . .
}

void autonomous() {
  chassis.reset_pid_targets(); // Resets PID targets to 0
  chassis.reset_gyro(); // Reset gyro position to 0
  chassis.reset_drive_sensor(); // Reset drive sensors to 0
  chassis.set_drive_brake(MOTOR_BRAKE_HOLD); // Set motors to hold.  This helps autonomous consistency.
  // pros::delay(2000);
  // drive_example();
  // ez::as::auton_selector.call_selected_auton(); // Calls selected auton from autonomous selector.
  skills_auton();
  // set_flywheel_velocity(600);
}

void opcontrol() {
  // This is preference to what you like to drive on.
  chassis.set_drive_brake(MOTOR_BRAKE_COAST);
  bool down = false;
  while (true) {
    
    chassis.tank();

    //intake in speed, intake out speed
    intake_control(127, -127);
    flywheel_control(127);

    down = shooter_control();

    pros::delay(ez::util::DELAY_TIME); // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
    if(down){
      pros::delay(100);
      shooter.set_value(false);
    }
  }
}
