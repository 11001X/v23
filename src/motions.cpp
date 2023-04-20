#include "main.h"

//Synchronous methods for autonomous movement

// Set intake motor speed to a value from -127 to 127
void set_intake(int val){
    intakemotor = val;
}

// Set flywheel motor speed to a value from -127 to 127
void set_flywheel(int val)
{
    flywheelmotor = val;
}

//Intake for a certain amount of time and stop from a speed of 0 to 127
void intake(int velocity, int time) 
{
    set_intake(fabs(velocity));
    pros::delay(time);
    set_intake(0);
}

//Outtake for a certain amount of time and stop from a speed of 0 to 127
void outtake(int velocity, int time) 
{
    set_intake(-fabs(velocity));
    pros::delay(time);
    set_intake(0);
}

//Flywheel motion for a period of time from a speed of 127 to -127, where negative is reversed spinning.
void flywheel(int velocity, int time)
{
    set_flywheel(velocity);
    pros::delay(time);
    set_flywheel(0);
}

//flywheel timed motion by velocity (out of 600).
void set_flywheel_velocity(int velocity)
{
    flywheelmotor.move_velocity(velocity);
}

// Flywheel one-sided motion checking
// Runs until the flywheel is at or greater than the desired speed
void flywheel_until_speed(int delay, int adjustment = 0)
{
    //Target velocity is the previously set flywheel velocity. 
    while (flywheelmotor.get_target_velocity() > flywheelmotor.get_actual_velocity() + adjustment)
    {
        pros::delay(delay); //Incremental delay
    }
}

// Set shooter to a value from -127 to 127 (Not in use)
void shooter_set(int time)
{
    shooter.set_value(true);
    pros::delay(time);
    shooter.set_value(false);
}

//Set Intake Piston Up
void intake_up(){
    intakepiston.set_value(false);
}

//Set Intake Piston Down
void intake_down(){
    intakepiston.set_value(true);
}

// Launch synchronous launcher
void deploylaunch()
{
    launcher1.set_value(true);
    launcher2.set_value(true);
}

//Firing procedure combined
void discfire(int target_speed, int outtake_time){
    flywheelPIDWait(target_speed);
    outtake(127, outtake_time);
}

//Firing procedure without PIDs, utilizes delays to shoot.
void direct_fire(int target_speed, int post_delay, int outtake_speed, int outtake_time){
    set_flywheel(target_speed);
    pros::delay(post_delay);
    outtake(outtake_speed, outtake_time);   
}

//PID control for flywheel speed. 
void flywheelPIDWait(double target, double threshold){
    double kP = 0.3; //Proportional Constant
    double kV = .0354; //Velocity constnat
    // double threshold = thr;

    double error = 0;
    double prevError = 0;

    double output = 0;
    target = (target/127)*600; //Converts speed out of 127 (Motor voltage units) to speed out of 600 (Velocity units)
    
    while (true) //Loops till within target threshold
    {

        error = target - flywheelmotor.get_actual_velocity(); //Error (distance)
        
        cout<<"Acc velocity"<<flywheelmotor.get_actual_velocity()<<endl; //Actual velocity of the flywheel motor as it is spinning.
        cout<<"target"<<target<<endl; //The target velocity we want it to be.

        // Set speed of flywheel
        if (error > threshold) 
        {
            output = 127; //Run max speed if its lower.
        }
        else if (error < -threshold)
        {
            output = 0;
            
        }
        else
        {
            output = (kV * target) + (kP * error);
            break;
        }

        // Sets the speed of the flywheel

        if (output > 127)
        {
            output = 127;
        }
        else if (output < 0)
        {
            output = 0;
        }

        flywheelmotor.move(output);

        prevError = error;
        pros::delay(10);
    }
    pros::delay(300);
}

//Task-based flyweel PID (Not in use)
void flywheelPID(double target) {
  // Constants
  double kP = 0.3;
  double kV = .0354; 
  double threshold = 10;

  double error = 0;
  double prevError = 0;

  double output = 0;

    target = (target/127)*600;
  while (true) {

    // Proportional
    error = target - flywheelmotor.get_actual_velocity();

    // Set speed of flywheel
    if (error > threshold){
      output = 127;
    }
    else if (error < -threshold){
      output = 0;
    }
    else{
      output = (kV * target) + (kP * error) ;
    }

    // Sets the speed of the flywheel
    
    if(output > 127){
      output = 127;
    }
    else if(output < 0){
      output = 0; 
    }

    flywheelmotor.move(output);

    prevError = error;
    pros::delay(10);

  }
}

//Flywheel PID speed setting (Not in use)
void set_flywheel_speed(int speed) {
  static std::unique_ptr<pros::Task> pidTask {};
  if (pidTask != nullptr) { pidTask->remove(); }
  pidTask = (speed == -1) ? nullptr : std::make_unique<pros::Task>([=]{ flywheelPID(speed); });
}

//Vision sensor alignment
void vision_align()
{   
    double currentheading = chassis.imu.get_heading();
    while (true)
    {
        vision_sensor.set_exposure(100);
        pros::vision_object_s_t rtn = vision_sensor.get_by_sig(0, 1);

        // Gets the largest object
        // if(vision_sensor.get_object_count()==1){
        // cout<<"Area: " << rtn.width*rtn.height<<endl;
        // }
        
        if (rtn.signature == 1)
        {       
            
            // double dist = sqrt(
            //     pow(rtn.x_middle_coord - (VISION_FOV_WIDTH / 2), 2) +
            //     pow(rtn.y_middle_coord - (VISION_FOV_HEIGHT / 2), 2));
            double dist = rtn.x_middle_coord-(VISION_FOV_WIDTH / 2);
            cout<<"RTN detected, Dist: "<<dist<<endl;
            if (fabs(dist)<3 ) {
                cout << "Within (" << dist << ")" << endl;
                break;
            }
            // Too Far Right, so turn right
            if (dist>0){   
                cout<<"bro did it hit"<<endl;
                currentheading = currentheading+1;
                chassis.set_turn_pid(currentheading, 127);
            } else {   
                currentheading = currentheading-1;
                chassis.set_turn_pid(currentheading, 127);
            }

            pros::delay(5);
        }
    }
}