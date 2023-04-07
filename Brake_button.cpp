#include "Brake_button.hpp"


BrakeButton::BrakeButton():
    Button()
{
}

bool BrakeButton::get_brake_state(){
    return get_button_state();
}

void BrakeButton::set_brake_state(const bool & state){
    set_button_state(state);
}