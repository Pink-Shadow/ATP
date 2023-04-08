import ATP
import time
from unittest import *


def timer(function):
    def inner(a, runs):
        t1 = time.perf_counter()
        function(a, runs)
        t2 = time.perf_counter()

        print(f"Execution time: {t2-t1}")
    return inner

@timer
def execute_func(f):
    def ins(a):
        f(a)
    return ins

pid = ATP.PIDSystem()
Brakes = ATP.BrakeSystem()
Drive = ATP.DriveControl(Brakes, pid)
ControllerInput = ATP.ControllerInputData(Drive)
ControllerDevice = ATP.ControllerDevice(ControllerInput)

## UNIT TEST 1

print("\n ------ UNIT TEST ------ \n")

ControllerDevice.set_cruise_state(True)
assert ControllerInput.get_cruise_state() == 1, "Cruise_state is not equal to 1. Must be set to 1 in ControllerInput"
print("set cruise state to [True] succeded!\n")

ControllerDevice.set_cruise_state(False)
assert ControllerInput.get_cruise_state() == 0, "Cruise_state is not equal to 0. Must be set to 0 in ControllerInput"
print("set cruise state to [False] succeded!\n")

## INTEGRATION TEST 1 
print("\n ------ INTEGRATION TEST ------ \n")

ControllerDevice.set_brake(1)
ControllerDevice.set_brake(0)


## SYSTEM TEST 1
print("\n ------ SYSTEM TEST ------ \n")
setpoint = 100
runs = 30

def exec_pid(f):
    def inner(a, runs, dt=0.000001):
        if runs <= 0:
            return
        t1 = time.perf_counter()
        f(a(setpoint,dt))
        dt = time.perf_counter() - t1
        inner(a, runs-1, dt)
    return inner

@timer
@exec_pid
def execute_func2(f):
    print(f"Motor power = : {round(f, 2)} {'%': <15}\tCurrent speed: {round(Drive.get_current_speed(), 2)}")


print(f"Setpoint is set to: {setpoint}")
print(f"Start speed is set to: {Drive.get_current_speed()}\n\n")
execute_func2(Drive.calculate_appropriate_accel, runs)