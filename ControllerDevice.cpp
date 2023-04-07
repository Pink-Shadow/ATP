#include "ControllerDevice.hpp"

ControllerDevice::ControllerDevice(ControllerInputData & input_data):
    input_data(input_data)
{}

void ControllerDevice::set_cruise_state(bool state){
    cruise_state = state;
    input_data.set_cruise_state(state);
}

void ControllerDevice::set_brake(bool brake){
    std::cout << "(called from ControllerDevice) " << " brake changed to: " << brake << std::endl;
    input_data.change_brakes(brake);
}

int ControllerDevice::read_acceleration(){
    return speed_throttle; // maybe, later add class function call speed_throttle.read()
}

