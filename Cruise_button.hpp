#ifndef CRUISE
#define CRUISE

#include <Button.hpp>

class CruiseButton : public Button{
    public:
        CruiseButton();
        bool get_cruise_state();
        void set_cruise_state(const bool & state);
        int getblabla();
        void setblabla(int val);

    private:
        int blabla;
};

#endif // CRUISE