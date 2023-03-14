#include "ControllerInput.hpp"

ControllerInput::ControllerInput(){}

void ControllerInput::set_cruise_state(bool state){
    cruise_control_button_state = state;
}

void ControllerInput::set_acceleration_percentage(float perc){
    acceleration_percentage = perc;
}

void ControllerInput::change_brakes(bool brake){
    // Function call to Drive controll: "DriveControl.change_brakes(brake);"
    std::cout << "called to Drive controll DriveControl.change_brakes(brake);" << "brake: " << brake << std::endl;
}

bool ControllerInput::get_cruise_state(){
    return cruise_control_button_state;
}

float ControllerInput::get_acceleration_percentage(){
    return acceleration_percentage;
}