#ifndef BRAKE
#define BRAKE

#include <Button.hpp>

class BrakeButton : public Button{
    public:
        BrakeButton();
        bool get_brake_state();
        void set_brake_state(const bool & state);
};

#endif // BRAKE