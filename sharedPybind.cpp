#include <pybind11/pybind11.h>

#include "Button.hpp"
#include "Cruise_button.hpp"
#include "Brake_button.hpp"
#include "ControllerDevice.hpp"
#include "ControllerInputData.hpp"
#include "BrakeSystem.hpp"
#include "DriveControl.hpp"
#include "PIDSystem.hpp"


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

    pybind11::class_<ControllerInputData> ctrlInputData(m, "ControllerInputData") ;
        ctrlInputData.def(pybind11::init<DriveControl&>());
        ctrlInputData.def("set_cruise_state", &ControllerInputData::set_cruise_state, pybind11::arg("state"));
        ctrlInputData.def("set_acceleration_percentage", &ControllerInputData::set_acceleration_percentage, pybind11::arg("perc"));
        ctrlInputData.def("change_brakes", &ControllerInputData::change_brakes, pybind11::arg("brake"));
        ctrlInputData.def("get_cruise_state", &ControllerInputData::get_cruise_state);
        ctrlInputData.def("get_acceleration_percentage", &ControllerInputData::get_acceleration_percentage);

    pybind11::class_<ControllerDevice> ctrlDevice(m, "ControllerDevice") ;
        ctrlDevice.def(pybind11::init<ControllerInputData&>());
        ctrlDevice.def("set_cruise_state", &ControllerDevice::set_cruise_state, pybind11::arg("state"));
        ctrlDevice.def("set_brake", &ControllerDevice::set_brake, pybind11::arg("brake"));
        ctrlDevice.def("read_acceleration", &ControllerDevice::read_acceleration);

    pybind11::class_<BrakeSystem> brkSys(m, "BrakeSystem");
        brkSys.def(pybind11::init<>());
        brkSys.def("brakes_enable", &BrakeSystem::brakes_enable);
        brkSys.def("brakes_disable", &BrakeSystem::brakes_disable);

    pybind11::class_<DriveControl> drivectl(m, "DriveControl") ;
        drivectl.def(pybind11::init<BrakeSystem&, PIDSystem&>());
        drivectl.def("change_brakes", &DriveControl::change_brakes, pybind11::arg("brake"));
        drivectl.def("calculate_appropriate_accel", &DriveControl::calculate_appropriate_accel);
        drivectl.def("get_current_speed", &DriveControl::get_current_speed);
    
    pybind11::class_<PIDSystem> pid(m, "PIDSystem");
        pid.def(pybind11::init<>());
        pid.def("get_new_acceleration", &PIDSystem::get_new_acceleration, pybind11::arg("setpoint_speed"), pybind11::arg("dt_"));
        pid.def("get_current_speed", &PIDSystem::get_current_speed);


}
