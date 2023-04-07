#ifndef BUTTON
#define BUTTON
#include <iostream>

class Button{
    public:
        Button(){
            
        }

        bool get_button_state(){
            std::cout << "get_button_state from class Button called" << std::endl;
            return button_state;

        }
        void set_button_state(const int & state){
            button_state = state;
        }

    private:
        bool button_state = false;
};

#endif // BUTTON