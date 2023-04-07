#######################################################
# Cheat sheet: https://bytes.usc.edu/cs104/wiki/makefile/
# NOTES TO MYSELF:

# For example, consider the following declaration:

# "all: library.cpp main.cpp"

# In this case:
# $@ evaluates to "all"
# $< evaluates to "library.cpp"
# $^ evaluates to "library.cpp main.cpp"
#SOURCE: https://stackoverflow.com/questions/3220277/what-do-the-makefile-symbols-and-mean
#SOURCE: https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html#Automatic-Variables
#######################################################

INC_DIR = pybind11/include
TARGET = ATP
COMPILER = c++
CFLAGS_LINUX = -O3 -Wall -shared -std=c++11 -fPIC $(shell python3-config --includes) -I $(INC_DIR) -I ./
PYTHON_MODULEFILE = $(TARGET)${shell python3-config --extension-suffix}


.DEFAULT_GOAL := all
.PHONY: all run build clean

all: run build

build: $(PYTHON_MODULEFILE)

run: build
	@echo "Executing python file..."
	@python3 ATP.py

# link *.o files to target .so file
$(PYTHON_MODULEFILE): Brake_button.o Cruise_button.o sharedPybind.o ControllerDevice.o ControllerInputData.o BrakeSystem.o DriveControl.o PIDSystem.o
	$(COMPILER) $(CFLAGS_LINUX) $^ -o $@

sharedPybind.o: sharedPybind.cpp Brake_button.hpp Cruise_button.hpp Button.hpp
	$(COMPILER) $(CFLAGS_LINUX) -c $< -o $@

Brake_button.o: Brake_button.cpp Brake_button.hpp 
	$(COMPILER) $(CFLAGS_LINUX) -c $< -o $@

Cruise_button.o: Cruise_button.cpp Cruise_button.hpp
	$(COMPILER) $(CFLAGS_LINUX) -c $< -o $@

ControllerDevice.o: ControllerDevice.cpp ControllerDevice.hpp ControllerInputData.hpp
	$(COMPILER) $(CFLAGS_LINUX) -c $< -o $@

ControllerInputData.o: ControllerInputData.cpp ControllerInputData.hpp DriveControl.hpp
	$(COMPILER) $(CFLAGS_LINUX) -c $< -o $@

BrakeSystem.o: BrakeSystem.cpp BrakeSystem.hpp
	$(COMPILER) $(CFLAGS_LINUX) -c $< -o $@

DriveControl.o: DriveControl.cpp DriveControl.hpp BrakeSystem.hpp PIDSystem.hpp
	$(COMPILER) $(CFLAGS_LINUX) -c $< -o $@

PIDSystem.o: PIDSystem.cpp PIDSystem.hpp
	$(COMPILER) $(CFLAGS_LINUX) -c $< -o $@

clean:
	@echo "Removing $(PYTHON_MODULEFILE)"
	@rm -f $(PYTHON_MODULEFILE)

	@echo "Removing *.o files"
	@rm -f *.o