#include "main.h"

// Defines intake controls
void intake_control(int in, int out)
{
    if (controller.get_digital(DIGITAL_L1))
        set_intake(in);
    else if (controller.get_digital(DIGITAL_R2))
        set_intake(out);
    else
        set_intake(0);
}

// Defines flywheel controls
void flywheel_control(int val)
{
    if (controller.get_digital(DIGITAL_L2))
    {
        set_flywheel(val);
    }
    else if (controller.get_digital(DIGITAL_B))
    {
        set_flywheel(-val);
    }
    else
    {
        set_flywheel(0);
    }
}

// Defines shooter controls
bool shooter_control()
{
    if (controller.get_digital(DIGITAL_R2))
    {
        shooter.set_value(true);
        return true;
    }
    return false;
}

// Defines launcher controls
void launcher_control()
{
    if (controller.get_digital(DIGITAL_Y))
    {
        deploylaunch();
    }
}

bool angler_control(bool anglerposition)
{
    if (controller.get_digital(DIGITAL_LEFT))
    {
        if (anglerposition)
        {
            angler.set_value(false);
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

void flywheelset_control(){
    if(controller.get_digital(DIGITAL_A)){
        // set_flywheel_speed(3300);
        set_flywheel(127);
    }
    if(controller.get_digital(DIGITAL_RIGHT)){
        // set_flywheel_speed(0);
        set_flywheel(0);
    }
}

bool intakepiston_control(bool intakeval)
{
    if (controller.get_digital(DIGITAL_UP))
    {
        if (intakeval)
        {
            intakepiston.set_value(false);
            pros::delay(500);
            return false;
        }
        else
        {
            intakepiston.set_value(true);
            pros::delay(500);
            return true;
        }
    }
    return intakeval;
}