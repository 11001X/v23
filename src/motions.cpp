#include "main.h"

// Set intake motor speed to a value from -127 to 127
void set_intake(int val)
{
    intakemotor = val;
}

void flywheelauto(double target)
{
//     target = flywheelmotor.get_position() + target;
//     flywheelPID.set_target(target);
//     ez::exit_output exit = ez::RUNNING;
//     while (flywheelPID.exit_condition({flywheelmotor}, true) == ez::RUNNING)
//     {
//         double output = flywheelPID.compute(flywheelmotor.get_position());
//         set_flywheel(output);
//         pros::delay(ez::util::DELAY_TIME);
//     }
//     set_flywheel(0);
}

// Set flywheel motor speed to a value from -127 to 127
void set_flywheel(int val)
{
    flywheelmotor = val;
}

void intake(int velocity, int time)
{
    set_intake(velocity);
    pros::delay(time);
    set_intake(0);
}

void flywheel(int velocity, int time)
{
    set_flywheel(velocity);
    pros::delay(time);
    set_flywheel(0);
}

void set_flywheel_velocity(int velocity)
{
    flywheelmotor.move_velocity(velocity);
}

void flywheel_until_speed(int delay, int adjustment = 0)
{
    while (flywheelmotor.get_target_velocity() > flywheelmotor.get_actual_velocity() + adjustment)
    {
        pros::delay(delay);
        ez::print_to_screen("Trial");
    }
}

// Set shooter to a value from -127 to 127
void shooter_set(int time)
{
    shooter.set_value(true);
    pros::delay(time);
    shooter.set_value(false);
}

// Launch
void deploylaunch()
{
    launcher1.set_value(true);
    launcher2.set_value(true);
}

void flywheelPIDWait(double target){
    double kP = 0.3;
    double kV = .0354;
    double threshold = 5;

    double error = 0;
    double prevError = 0;

    double output = 0;
    target = (target/127)*600;
    while (true)
    {

        // Proportional
        error = target - flywheelmotor.get_actual_velocity();
        cout<<"Acc velocity"<<flywheelmotor.get_actual_velocity()<<endl;
        cout<<"target"<<target<<endl;
        // Set speed of flywheel
        if (error > threshold)
        {
            output = 127;
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

void set_flywheel_speed(int speed) {
  static std::unique_ptr<pros::Task> pidTask {};
  if (pidTask != nullptr) { pidTask->remove(); }
  pidTask = (speed == -1) ? nullptr : std::make_unique<pros::Task>([=]{ flywheelPID(speed); });
}

// vision::signature SIG_1 (1, 601, 7681, 4142, -2711, -495, -1602, 0.800, 0);
// vex::vision vision1 ( vex::PORT1, 22, SIG_1, SIG_2, SIG_3, SIG_4, SIG_5, SIG_6, SIG_7 );



void vision_align()
{
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
            double dist = sqrt(
                pow(rtn.x_middle_coord - (VISION_FOV_WIDTH / 2), 2) +
                pow(rtn.y_middle_coord - (VISION_FOV_HEIGHT / 2), 2));
            if (dist < 15)
            {
                cout << "Within (" << dist << ")" << endl;
                break;
            }
            // Too Far Right, so turn right
            if (rtn.x_middle_coord > VISION_FOV_WIDTH / 2)
            {
                chassis.set_turn_pid(chassis.imu.get_heading() + 1, 127);
            }
            else
            {
                chassis.set_turn_pid(chassis.imu.get_heading() - 1, 127);
            }

            // pros::delay(2);
        }
    }
}