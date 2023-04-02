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
$(PYTHON_MODULEFILE): Brake_button.o Cruise_button.o sharedPybind.o
	$(COMPILER) $(CFLAGS_LINUX) $^ -o $@

sharedPybind.o: sharedPybind.cpp Brake_button.hpp Cruise_button.hpp Button.hpp
	$(COMPILER) $(CFLAGS_LINUX) -c $< -o $@

Brake_button.o: Brake_button.cpp Brake_button.hpp 
	$(COMPILER) $(CFLAGS_LINUX) -c $< -o $@

Cruise_button.o: Cruise_button.cpp Cruise_button.hpp
	$(COMPILER) $(CFLAGS_LINUX) -c $< -o $@


clean:
	@echo "Removing $(PYTHON_MODULEFILE)"
	@rm -f $(PYTHON_MODULEFILE)

	@echo "Removing *.o files"
	@rm -f *.o