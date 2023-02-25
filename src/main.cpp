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

Chassis - 4 Motor Drive; Left ports: 2, 5; Right ports: 3, 4; Right Reversed
    IMU - PORT 13, Wheel size: 4.125, RPM - 200, 1 External Gear Ratio

Lift - Singular Lift Motor: PORT:7, Gear ratio:18, Reversed: false

Flywheel Motor: PORT:10, Gear ratio:18, Reversed: false
Intake Motor: PORT:18, Gear ratio:18, Reversed: true

**/

pros::Controller controller(pros::E_CONTROLLER_MASTER);
Drive chassis({-8, -2, 7}, {-5, 4, 6}, 13, 3.125, 200, 1);

pros::Motor flywheelmotor(17, pros::E_MOTOR_GEARSET_06, false);
pros::Motor intakemotor(10, pros::E_MOTOR_GEARSET_06, false);

shared_ptr<ChassisController> myChassis = ChassisControllerBuilder().withMotors({-8, -2, 7}, {5, 4, -6})
                                              // Green gearset, 4 in wheel diam, 11.5 in wheel track
                                              .withDimensions(AbstractMotor::gearset::blue, {{3.5_in, 12.5_in}, imev5BlueTPR})
                                              .build();

shared_ptr<AsyncMotionProfileController> profileController =
    AsyncMotionProfileControllerBuilder()
        .withLimits({
            1.0, // Maximum linear velocity of the Chassis in m/s
            2.0, // Maximum linear acceleration of the Chassis in m/s/s
            10.0 // Maximum linear jerk of the Chassis in m/s/s/s
        })
        .withOutput(myChassis)
        .buildMotionProfileController();

#define SHOOTER_PORT 'E'
#define LAUNCHER1_PORT 'B'
#define LAUNCHER2_PORT 'C'
#define INTAKEPISTON_PORT 'D'
#define ANGLER_PORT 'A'

pros::Vision vision_sensor(15);
pros::ADIDigitalOut shooter(SHOOTER_PORT, false);
pros::ADIDigitalOut launcher1(LAUNCHER1_PORT, false);
pros::ADIDigitalOut launcher2(LAUNCHER2_PORT, false);
pros::ADIDigitalOut intakepiston(INTAKEPISTON_PORT, false);
pros::ADIDigitalOut angler(ANGLER_PORT, false);
bool intakeval = true;

void initialize()
{
  // Print our branding over your terminal :D
  ez::print_ez_template();

  pros::delay(500); // Stop the user from doing anything while legacy ports configure.
  // shooter.set_value(false);
  // Configure your chassis controls
  chassis.toggle_modify_curve_with_controller(true); // Enables modifying the controller curve with buttons on the joysticks
  chassis.set_active_brake(0);                       // Sets the active brake kP. We recommend 0.1.
  chassis.set_curve_default(0, 0);                   // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)
  default_constants();                               // Set the drive to your own constants from autons.cpp!
  exit_condition_defaults();                         // Set the exit conditions to your own constants from autons.cpp!
  // Autonomous Selector using LLEMU

  ez::as::auton_selector.add_autons({
      Auton("NewWP\n\nTEST", newwp_auton),
      Auton("Test\n\nTEST", test_auton),
      Auton("Win Point\nDrive forward and come back.", wp_auton),
      Auton("Skills\n\n\n\nSKILLS", skills_auton),
      Auton("Roller\n\n\nROLLER.", roller_auton),

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
  // . . .
  shooter.set_value(false);
}

void competition_initialize()
{
  // . . .
}

void autonomous()
{
  chassis.reset_pid_targets();               // Resets PID targets to 0
  chassis.reset_gyro();                      // Reset gyro position to 0
  chassis.reset_drive_sensor();              // Reset drive sensors to 0
  chassis.set_drive_brake(MOTOR_BRAKE_HOLD); // Set motors to hold.  This helps autonomous consistency.
  // pros::delay(2000);
  // drive_example();
  pros::Task flywheel ( [] { flywheelPID(0); } );
  ez::as::auton_selector.call_selected_auton(); // Calls selected auton from autonomous selector.
  // set_flywheel_velocity(600);
}

#define EXAMPLE_SIG 3
void opcontrol()
{
  // Chassis Coasting
  chassis.set_drive_brake(MOTOR_BRAKE_COAST);
  bool down = false;
  bool anglerposition = true;


  while (true)
  {

    chassis.tank();

    // intake in speed, intake out speed
    intake_control(127, -127);
    // flywheel rotation speed
    // int val = flywheelset_control(3600);
    flywheel_control(110);
    // To launch
    launcher_control();
    

    // Defines current state of flywheel indexers
    down = intakepiston_control(down);
    anglerposition = angler_control(anglerposition);
    pros::delay(ez::util::DELAY_TIME); // Timer calculations for chassis movement.
    
  }
}

// vision::signature SIG_1 (1, 1387, 2275, 1830, -4737, -3679, -4208, 0.800, 0);