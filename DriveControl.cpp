#include "DriveControl.hpp"

DriveControl::DriveControl(BrakeSystem & brakes, PIDSystem & pid_sys):
    brakes(brakes),
    pid_sys(pid_sys)
{}

void DriveControl::change_brakes(const bool & brake){
    brake ? brakes.brakes_enable() : brakes.brakes_disable();
}

float DriveControl::calculate_appropriate_accel(float setpoint, float dt){
    current_acceleration = pid_sys.get_new_acceleration(setpoint, dt);
    return current_acceleration;
}

float DriveControl::get_current_speed(){
    return pid_sys.get_current_speed();
}