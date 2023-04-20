# 11001x - Pentabotix
### *Akul Singhal, Arihan Dixit, Naren Kanugula, Nihal Shah, Nikhil Koteru*


## Introduction
We are team 11001x Pentabotix, based out of Ashburn, Virginia. We are an independent team formed with the goal of achieving the highest honors in the VEX Robotics Competition. Our current target? _Vex Worlds 2023_. Visit https://pentabotix.cjshah.org/.

Our code is designed using PROS and EZtemplate, coded entirely in C++.

Our file structure:
```
├───include
│   │   api.h
│   │   autons.hpp
│   │   control.hpp
│   │   main.h
│   │   motions.hpp
└───src
        autons.cpp
        control.cpp
        main.cpp
        motions.cpp
```

## _main.cpp_
All the main methods called by the VEX competition switch
1. void initialize() 
   - Runs when the program starts
2. void disabled()
   - Runs while the robot is in the disabled state of the competition switch
3. void autonomous()
   - Calls selected autonomous
4. void opcontrol()
   - Runs the driver control and calls methods from control.cpp

## _control.cpp_
Control methods for the entire robotics system used in driver control
1. void intake_control(int in, int out) 
   - Defines intake controls (L1 for in, R2 for out)
2. bool flywheelcontrol(int val, bool running)
   - Defines flywheel controls (L2 to start, with a boolean to check if it is running)
3. void launcher_control()
   - Defines launcher controls (Y to launch both launchers: they are controlled by one pneumatics system).
4. bool angler_control(bool anglerposition)
   - Reversing the angler piston using a previously stored value.
5. void flywheelset_control()
   - Dual-button flywheel control **(Not in use)**
6. bool intakepiston_control(bool intakeval)
   - Reversing the intake height position using a previously stored value.

## _autons.cpp_ 
Autonomous Routines Definition
1. void inside_auton()
   - The near-side autonomous routine, designed to get a roller and 5 shots. 
2. void outside_auton()
   - The far-side autonomous, made to maximize discs made and get a roller.
3. void solowinpoint()
   - The solo win point autonomous, made to shoot 4 discs and get the two rollers.
4. void skills_auton()
   - The current skills autonomous routine following a specified path. 
5. void default_constants()
   - Definition of the PID constants for our autonomous routines.
6. void exit_condition_defaults()
   - Default exit condition definitions

## _motions.cpp_
Synchronous methods for autonomous movement
1. void set_intake(int val)
   - Set intake motor speed to a value from -127 to 127
2. void set_flywheel(int val)
   - Set flywheel motor speed to a value from -127 to 127
3. void intake(int velocity, int time) 
   - Intake for a certain amount of time and stop (Speed of 0 to 127)
4. void outtake(int velocity, int time)
   - Outtake for a certain amount of time and stop (Speed of 0 to 127)
5. void flywheel(int velocity, int time)
   - Flywheel motion for a period of time from a speed of 127 to -127, where negative is reversed spinning.
6. void set_flywheel_velocity(int velocity)
   - Flywheel timed motion by velocity (out of 600).
7. void flywheel_until_speed(int delay, int adjustment = 0)
   - Flywheel one-sided motion checking
8. void intake_up()
   - Set Intake Piston Up
9.  void intake_down()
   - Set Intake Piston Down
10. void deploylaunch()
   - Launch synchronous launcher
11. void discfire(int target_speed, int outtake_time)
    - Firing procedure combined (PID wait + shooting)
12. void flywheelPIDWait(double target, double threshold)
   - PID control for flywheel speed.
13. void vision_align()
   - Vision sensor alignment