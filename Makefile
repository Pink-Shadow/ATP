# the compiler: gcc for C program, define as g++ for C++
COMPILER = g++
RM = del
# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall
TARGET = main


run: $(TARGET).exe
	./$(TARGET).exe

$(TARGET).exe: $(TARGET).cpp
	$(COMPILER) $(CFLAGS) $(TARGET).cpp -o $(TARGET)


clean:
	$(RM) $(TARGET).exe