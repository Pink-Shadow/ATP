# ATP
This repository is used for the final assesment of the ATP course.

# Requirements
- Linux 64bit build environment
- Python 3.8
- 64bit c++ compiler
- pybind11

# Execution
To run the program, run `make` on the given makefile.
To clean-up the build files, run `make clean`.

# Exercise goals
## Implementation
The control system has to contain 2 sensors and 2 actuators. These are listed below:

* Sensors
    * Controller device with brake button: [set_brake](./ControllerDevice.cpp)
    * Controller device with cruise control button: [set_cruise_state](./ControllerDevice.cpp)
* actuators
    * [Brake system](./BrakeSystem.cpp)
    * [PID system](./PIDSystem.cpp)

The 2 buttons are the sensors for the system. The 2 systems are used to as an actuator on the device.

## Aspect-oriented decorator
The Functional programmed decorator is implemented and demonstrated in the [main python code](./ATP.py). These functions are called: 

* timer(function)
* exec_pid(f)

These functions are used as decorator on the following functions:

* execute_func(f)
* execute_func2(f)

Source: [ATP.py](./ATP.py)

## Python-C++ binding
[Pybind11](https://realpython.com/python-bindings-overview/#pybind11) has been used to create the Python-C++ binding. The binding functions are programmed [here](./sharedPybind.cpp). These functions are implemented in their own seperate .hpp and .cpp files and used in [ATP.py](./ATP.py) as an imported module.

## Test uitvoer en reflectie
The testcases are programmed in [ATP.py](./ATP.py) from line 27 until line 72. 

* Unit-test:        Line 27-36
* Integration test: Line 38-42
* System test:      Line 45-72

## Simulator
The simulator for the System test is implemented as a Command Line Interface. You can enter a desired speed as a setpoint for the PID controller. Afterwards, you can enter the amount of iterations the PID controller is allowed to use for it's calculations to regulate the speed.

The simluator is programmed on line 69-70 in file [ATP.py](./ATP.py)