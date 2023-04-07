#include "ControllerInputData.hpp"

ControllerInputData::ControllerInputData(DriveControl & drive):
    drive(drive)
{}

void ControllerInputData::set_cruise_state(bool state){
    cruise_control_button_state = state;
}

void ControllerInputData::set_acceleration_percentage(float perc){
    acceleration_percentage = perc;
}

void ControllerInputData::change_brakes(bool brake){
    std::cout << "(called from ControllerInputData)\t" << " called DriveControl.change_brakes() to: " << brake << std::endl;
    drive.change_brakes(brake);
}

bool ControllerInputData::get_cruise_state(){
    std::cout << "(called from ControllerInputData)\t" << " Cruise state is: " << cruise_control_button_state << std::endl;
    return cruise_control_button_state;
}

float ControllerInputData::get_acceleration_percentage(){
    return acceleration_percentage;
}