#pragma once

#include "EZ-Template/drive/drive.hpp"

extern Drive chassis;
extern pros::Controller controller;
extern pros::Motor liftmotor;
extern pros::Motor flywheelmotor;   
extern pros::Motor intakemotor;
extern pros::ADIDigitalOut shooter;

void test_auton();

void drive_example();
void turn_example();

void default_constants();
void exit_condition_defaults();