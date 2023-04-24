#include "main.h"
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
using namespace ez;

/**
main.cpp
Contains the definition to all the motors
Contains function definitions

Author's Note: Reversed means Left-sided

------------------------------------------------
Controller: controller

Chassis - 4 Motor Drive; Left ports: 2, 7, 8; Right ports: 4, 5, 6; Right Reversed
    IMU - PORT 13, Wheel size: 4.125, RPM - 200, 1 External Gear Ratio

Flywheel Motor: PORT:10, Gear ratio:none, Reversed: false
Intake Motor: PORT:17, Gear ratio:blue, Reversed: true

**/

pros::Controller controller(pros::E_CONTROLLER_MASTER);
Drive chassis({-8, -2, 7}, {5, 4, -6}, 13, 3.25, 360, 1);

pros::Motor flywheelmotor(17, pros::E_MOTOR_GEARSET_06, true);
pros::Motor intakemotor(10, pros::E_MOTOR_GEARSET_06, true);

//Piston ports
#define SHOOTER_PORT 'E'
#define LAUNCHER1_PORT 'B'
#define LAUNCHER2_PORT 'C'
#define INTAKEPISTON_PORT 'D'
#define ANGLER_PORT 'A'

pros::Vision vision_sensor(15);
//All these initial states are false.
pros::ADIDigitalOut shooter(SHOOTER_PORT, false); 
pros::ADIDigitalOut launcher1(LAUNCHER1_PORT, false);
pros::ADIDigitalOut launcher2(LAUNCHER2_PORT, false);
pros::ADIDigitalOut intakepiston(INTAKEPISTON_PORT, false);
pros::ADIDigitalOut angler(ANGLER_PORT, false);

void initialize() //Runs when the program starts
{
  pros::delay(500); // Stop the user from doing anything while legacy ports configure.
  // Configure your chassis controls
  chassis.toggle_modify_curve_with_controller(true); // Enables modifying the controller curve with buttons on the joysticks
  chassis.set_active_brake(0.1);                       // Sets the active brake kP. We recommend 0.1.
  chassis.set_curve_default(0, 0);                   // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)
  default_constants();                               // Set the drive to your own constants from autons.cpp!
  exit_condition_defaults();                         // Set the exit conditions to your own constants from autons.cpp!
  
  // Autonomous Selector using LLEMU
  ez::as::auton_selector.add_autons({
      Auton("\nOutside Auton\n\n\n\n", outside_auton),
      Auton("Inside Auton\n", inside_auton),
      Auton("\n\nSolo Win Point\n\n\n", solowinpoint),
      Auton("\n\n\nSkills\n\n", skills_auton),
      
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
void disabled()
{

}

void competition_initialize() //Runs between autonomous and driver control.
{
  
}

void autonomous()
{
  chassis.reset_pid_targets();               // Resets PID targets to 0
  chassis.reset_gyro();                      // Reset gyro position to 0
  chassis.reset_drive_sensor();              // Reset drive sensors to 0
  ez::as::auton_selector.call_selected_auton(); // Calls selected auton from autonomous selector.
}


void opcontrol()
{
  // Chassis Coasting Brake Mode
  chassis.set_drive_brake(MOTOR_BRAKE_COAST);

  bool INTAKE_PISTON_DOWN = false; 

  //Sets original state of Angler at the beginning of driver control
  angler.set_value(true);
  bool ANGLER_UP = true;

  // set_flywheel(113); //Start the flywheel to 113/127.
  set_flywheel(127);
  bool FLYWHEEL_RUNNING = true;

  while (true) //Start of actual driver control loop.
  {

    chassis.tank(); //Chassis tank control.

    // Intake speed control (intake, outtake)
    intake_control(127, -127);

    //Flywheel movement and speed definition.
    FLYWHEEL_RUNNING = flywheelcontrol(127, FLYWHEEL_RUNNING);
    
    // To launch string
    launcher_control();
  
    // Defines intake piston state and control
    INTAKE_PISTON_DOWN = intakepiston_control(INTAKE_PISTON_DOWN);
    
    // Defines angler piston state and control
    ANGLER_UP = angler_control(ANGLER_UP);

    pros::delay(ez::util::DELAY_TIME); // Timer calculations for chassis movement.
  }
}

// vision::signature SIG_1 (1, 1387, 2275, 1830, -4737, -3679, -4208, 0.800, 0);