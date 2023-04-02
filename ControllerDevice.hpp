#include <iostream>
// #include "serial/serial.h"

class ControllerDevice {
private:
    // serial::Serial &USB_Device;
    bool cruise_state;
    int speed_throttle; // TODO: make class? to read out value.

public:
    ControllerDevice(); //serial::Serial &USB_dev);

    void set_cruise_state(bool state);
    void set_brake(bool brake);
    int read_acceleration();
};