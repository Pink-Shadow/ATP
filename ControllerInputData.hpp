#ifndef CONTROLLER_INPUT_DATA_HPP
#define CONTROLLER_INPUT_DATA_HPP

#include <iostream>
#include "DriveControl.hpp"

class ControllerInputData {
private:
    bool cruise_control_button_state = false;
    float acceleration_percentage;
    DriveControl & drive;

public:
    ControllerInputData(DriveControl & drive);

    void set_cruise_state(bool state);
    void set_acceleration_percentage(float perc);
    void change_brakes(bool brake);
    
    bool get_cruise_state();
    float get_acceleration_percentage();

};

#endif // CONTROLLER_INPUT_DATA_HPP