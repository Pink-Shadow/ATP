#ifndef PIDSYSTEM_HPP
#define PIDSYSTEM_HPP

#include <iostream>

class PIDSystem{
public:
    PIDSystem();
    float get_new_acceleration(float setpoint_speed, float dt_);
    float get_current_speed();


private:
    float Kp = 1;
    float Ki = 0.001;
    float Kd = 0;

    float prev_error;
    float setpoint;
    float i_error = 0;

    float accel_percentage;
    float current_speed = 50;

    float calculate_current_speed(int hall_pulses);
    float get_speed_error();
    void set_setpoint(float setpoint);


};



#endif // PIDSYSTEM_HPP
