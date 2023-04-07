#include "PIDSystem.hpp"

PIDSystem::PIDSystem()

{}


float PIDSystem::calculate_current_speed(int hall_pulses){
    current_speed = current_speed * (1.0+(accel_percentage/100)); // TODO: IMPLEMENT read_sensor_value FOR CURRENT SPEED and hall pulses calculations 
    return current_speed;
}

float PIDSystem::get_new_acceleration(float setpoint_speed, float dt_){
    setpoint = setpoint_speed;


    float error = get_speed_error();
    i_error += (error*dt_);
    float error_div = (error - prev_error) / dt_;

    float action = Kp*error + Ki*i_error + Kd*error_div;
    prev_error = error;

    action > 100 ? action = 100 : 
        action < 0 ? action = 0 : action;
    accel_percentage = action;

    return action;

}

float PIDSystem::get_speed_error(){
    float error = setpoint - calculate_current_speed(10);
    return error; // implement hall pulses readout for now use 10

}

float PIDSystem::get_current_speed(){
    return current_speed;
}

void PIDSystem::set_setpoint(float setpoint){
    setpoint = setpoint;
}