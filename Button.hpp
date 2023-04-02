#ifndef BUTTON
#define BUTTON
#include <iostream>

class Button{
    public:
        Button(){
            
        }

        bool get_button_state(){
            std::cout << "hii" << std::endl;
            return this->button_state;

        }
        void set_button_state(const int & state){
            this->button_state = state;
        }

    private:
        bool button_state = false;
};

#endif // BUTTON