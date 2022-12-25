#pragma once

#include "EZ-Template/drive/drive.hpp"

extern Drive chassis;
extern pros::Controller controller;
extern pros::Motor liftmotor;
extern pros::Motor flywheelmotor;   
extern pros::Motor intakemotor;
extern pros::ADIDigitalOut shooter;

void wp_auton();

void skills_auton();
void disc_auton();

void default_constants();
void exit_condition_defaults();