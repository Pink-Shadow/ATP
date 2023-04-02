#include <pybind11/pybind11.h>

#include "Button.hpp"
#include "Cruise_button.hpp"
#include "Brake_button.hpp"

PYBIND11_MODULE(ATP, m){
    pybind11::class_<Button> btn(m, "Button");
        btn.def(pybind11::init<>());
        btn.def("get_button_state", &Button::get_button_state);
        btn.def("set_button_state", &Button::set_button_state);

    pybind11::class_<CruiseButton, Button> cruise(m, "Cruise_button");
        cruise.def(pybind11::init<>());
        cruise.def("get_cruise_state", &CruiseButton::get_cruise_state);
        cruise.def("set_cruise_state", &CruiseButton::set_cruise_state, pybind11::arg("state"));
        cruise.def("setblabla", &CruiseButton::setblabla, pybind11::arg("val")); // testing
        cruise.def("getblabla", &CruiseButton::getblabla); // testing




    pybind11::class_<BrakeButton, Button> brake(m, "Brake_button");
        brake.def(pybind11::init<>());
        brake.def("get_brake_state", &BrakeButton::get_brake_state);
        brake.def("set_brake_state", &BrakeButton::set_brake_state, pybind11::arg("state"));
}

