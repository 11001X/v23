#include "main.h"

//Controls for the entire robotics system during driver control (ie. button assignments)

// Defines intake controls (L1 for in, R2 for out)
// Takes 2 arguments, in and out-speeds for each.
void intake_control(int in, int out)
{
    if (controller.get_digital(DIGITAL_L1))
        set_intake(in);
    else if (controller.get_digital(DIGITAL_R2))
        set_intake(out);
    else
        set_intake(0);
}

// Defines flywheel controls (L2 to start, with a boolean to check if it is running)
bool flywheelcontrol(int val, bool running){
    if (controller.get_digital(DIGITAL_L2)){
        if(running){ //If the flywheel is currently running (true),
            set_flywheel(0); //set its speed to 0
            pros::delay(70); //Delay to prevent over clicking
            return false; 
        }else{
            set_flywheel(val); //If it is not running, start it.
            pros::delay(70);
            return true;
        }
    }
    if (controller.get_digital(DIGITAL_DOWN)){
        set_flywheel(-val);
        return false;
    }
    return running;
}

// Defines shooter controls (R2 to launch and immediately come down)
bool shooter_control()
{
    if (controller.get_digital(DIGITAL_R2))
    {
        shooter.set_value(true);
        return true;
    }
    return false;
}

// Defines launcher controls (Y to launch both launchers: they are controlled by one pneumatics system.)
void launcher_control()
{
    if (controller.get_digital(DIGITAL_Y))
    {
        deploylaunch();
    }
}

//Reversing the angler piston using a previously stored value.
bool angler_control(bool anglerposition)
{
    if (controller.get_digital(DIGITAL_LEFT))
    {
        if (anglerposition) //If the angler is up (true), 
        {
            angler.set_value(false); //Set it down
            pros::delay(200);
            return false;
        }
        else
        {
            angler.set_value(true);
            pros::delay(200);
            return true;
        }
    }
    return anglerposition;
}

//Dual-button flywheel control
void flywheelset_control(){
    if(controller.get_digital(DIGITAL_A)){
        set_flywheel(127);
    }
    if(controller.get_digital(DIGITAL_RIGHT)){
        set_flywheel(0);
    }
}

//Reversing the intake height position using a previously stored value.
bool intakepiston_control(bool intakeval)
{
    if (controller.get_digital(DIGITAL_UP))
    {
        if (intakeval) //If the intake piston is retracted and up (true),
        {
            intakepiston.set_value(false); //Put it down
            pros::delay(500);
            return false;
        }
        else
        {
            intakepiston.set_value(true); // Put it up.
            pros::delay(500);
            return true;
        }
    }
    return intakeval;
}