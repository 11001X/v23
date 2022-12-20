#include "main.h"

void intake_control(int in, int out){
    if (controller.get_digital(DIGITAL_R1))
        set_intake(in);
    else if (controller.get_digital(DIGITAL_R2))
        set_intake(out);
    else
        set_intake(0);
}

void lift_control(int up, int down){
    // if (controller.get_digital(DIGITAL_))
    //     set_lift(up);
    // else if (controller.get_digital(DIGITAL_L2))
    //     set_lift(down);
    // else
    //     set_lift(0);
}

void flywheel_control(int val){
    if (controller.get_digital(DIGITAL_L1))
        set_flywheel(val);
    else
        set_flywheel(0);
}


void shooter_control(bool val){
    if(controller.get_digital(DIGITAL_Y)){
        shooter.set_value(true);
    }else{
        shooter.set_value(false);
    }
}