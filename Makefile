PYTHON_INCLUDES := $(shell python3-config --includes)
PYTHON_MODULEFILE = ATP${shell python3-config --extension-suffix}

.DEFAULT_GOAL := all
.PHONY: all run build clean

all: run build

build: $(PYTHON_MODULEFILE)

run: build
	@echo "Executing ATP.py..."
	@python3 ATP.py

$(PYTHON_MODULEFILE): ControllerDevice.cpp ControllerDevice.hpp ControllerInput.cpp ControllerInput.hpp main.cpp
	@echo "Building $(PYTHON_MODULEFILE)..."
	@c++ -O3 -Wall -shared -std=c++11 -fPIC $(PYTHON_INCLUDES) -Ipybind11/include ControllerDevice.cpp ControllerInput.cpp main.cpp -o $(PYTHON_MODULEFILE)

clean:
	@echo "Removing $(PYTHON_MODULEFILE)"
	@rm -f $(PYTHON_MODULEFILE)