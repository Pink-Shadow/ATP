#include "Cruise_button.hpp"


CruiseButton::CruiseButton():
    Button()
{
    
}

int CruiseButton::getblabla(){
    return blabla;
}

void CruiseButton::setblabla(int val){
    blabla = val;
}

bool CruiseButton::get_cruise_state(){
    return get_button_state();
}

void CruiseButton::set_cruise_state(const bool & state){
    set_button_state(state);
}