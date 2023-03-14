# Cheat sheet: https://bytes.usc.edu/cs104/wiki/makefile/

#######################################################
# For example, consider the following declaration:

# "all: library.cpp main.cpp"

# In this case:
# $@ evaluates to "all"
# $< evaluates to "library.cpp"
# $^ evaluates to "library.cpp main.cpp"
#SOURCE: https://stackoverflow.com/questions/3220277/what-do-the-makefile-symbols-and-mean
#SOURCE: https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html#Automatic-Variables
#######################################################

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings



# the compiler: gcc for C program, define as g++ for C++
COMPILER = g++
RM = del

# Specify include dir, so g++ knows where to look for file that you #include
INC_DIR = serial/include
CFLAGS= -g -Wall -I $(INC_DIR) 

TARGET = main

# execute binary after its been build
run: $(TARGET).exe
	./$(TARGET).exe

# link *.o files to target .exe binary
$(TARGET).exe: $(TARGET).o ControllerDevice.o ControllerInput.o
	$(COMPILER) $(CFLAGS) $^ -o $@

# build *.o files
$(TARGET).o : $(TARGET).cpp
	$(COMPILER) $(CFLAGS) -c $< -o $@

ControllerDevice.o: ControllerDevice.cpp ControllerDevice.hpp
	$(COMPILER) $(CFLAGS) -c $< -o $@

ControllerInput.o: ControllerInput.cpp ControllerInput.hpp
	$(COMPILER) $(CFLAGS) -c $< -o $@

# cleanup all *.o files
clean:
	$(RM) *.o