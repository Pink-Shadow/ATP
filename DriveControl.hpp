#ifndef DRIVECONTROL_HPP
#define DRIVECONTROL_HPP

#include <iostream>
#include "BrakeSystem.hpp"
// #include "WheelMotor.hpp" #TODO: IMPLEMENT WHEEL MOTOR
#include "PIDSystem.hpp"


class DriveControl{
public:
    DriveControl(BrakeSystem & brakes, PIDSystem & pid_sys);
    void change_brakes(const bool & brake);
    float calculate_appropriate_accel(float setpoint, float dt);
    float get_current_speed();

private:

    BrakeSystem & brakes;
    PIDSystem & pid_sys;
    // WheelMotor & motor # TODO: IMPLEMENT WHEEL MOTOR CLASS
    float current_acceleration;

};

#endif // DRIVECONTROL_HPP