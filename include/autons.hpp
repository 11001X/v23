#pragma once

#include "EZ-Template/drive/drive.hpp"
#include "okapi/api.hpp"


extern Drive chassis;
extern pros::Controller controller;
extern pros::Motor liftmotor;
extern pros::Motor flywheelmotor;   
extern pros::Motor intakemotor;
extern pros::ADIDigitalOut shooter;
extern pros::ADIDigitalOut launcher1;
extern pros::ADIDigitalOut launcher2;
extern pros::ADIDigitalOut intakepiston;
extern pros::ADIDigitalOut angler;
extern shared_ptr<okapi::ChassisController> myChassis;
extern shared_ptr<okapi::AsyncMotionProfileController> profileController;
extern pros::Vision vision_sensor;
extern pros::Motor l1;
extern pros::Motor l2;
extern pros::Motor l3;
extern pros::Motor r1;
extern pros::Motor r2;
extern pros::Motor r3;

void wp_auton();

void skills_auton();
void disc_auton();
void roller_auton();
void test_auton();
void newwp_auton();
void disc_constants();
void default_constants();
void exit_condition_defaults();