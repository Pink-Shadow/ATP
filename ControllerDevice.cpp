#include "ControllerDevice.hpp"

ControllerDevice::ControllerDevice(){//serial::Serial &USB_dev):
    // USB_Device(USB_dev)
}

void ControllerDevice::set_cruise_state(bool state){
    cruise_state = state;
}

void ControllerDevice::set_brake(bool brake){
    // TODO: add function call to Controller_input entitiy "Controller_input.change_brakes(brake)"
    std::cout << "brake changed to: " << brake << std::endl;
}

int ControllerDevice::read_acceleration(){
    return speed_throttle; // maybe, later add class function call speed_throttle.read()
}

