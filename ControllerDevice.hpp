#ifndef CONTROLLER_DEVICE_HPP
#define CONTROLLER_DEVICE_HPP

#include <iostream>
#include "ControllerInputData.hpp"

class ControllerDevice {
private:
    ControllerInputData & input_data;
    bool cruise_state;
    int speed_throttle; // TODO: make class? to read out value.


public:
    ControllerDevice(ControllerInputData & input_data);

    void set_cruise_state(bool state);
    void set_brake(bool brake);
    int read_acceleration();
};

#endif // CONTROLLER_DEVICE_HPP