#include <iostream>

class ControllerInput {
private:
    bool cruise_control_button_state;
    float acceleration_percentage;

public:
    ControllerInput();

    void set_cruise_state(bool state);
    void set_acceleration_percentage(float perc);
    void change_brakes(bool brake);
    
    bool get_cruise_state();
    float get_acceleration_percentage();

};