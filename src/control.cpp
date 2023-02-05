#include "main.h"


//Defines intake controls
void intake_control(int in, int out){
    if (controller.get_digital(DIGITAL_L1))
        set_intake(in);
    else if (controller.get_digital(DIGITAL_R1))
        set_intake(out);
    else
        set_intake(0);
}

//Defines flywheel controls
void flywheel_control(int val){
    if (controller.get_digital(DIGITAL_L2)){
        set_flywheel(val); 
    }else if (controller.get_digital(DIGITAL_B)){
        set_flywheel(-val);
    }else{
        set_flywheel(0);
    }
}

//Defines shooter controls
bool shooter_control(){
    if(controller.get_digital(DIGITAL_R2)){
        shooter.set_value(true);
        return true;
    }
    return false;
}

//Defines launcher controls
void launcher_control(){
    if(controller.get_digital(DIGITAL_Y)){
        deploylaunch();
    }
}
