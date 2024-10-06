#22567659
# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -std=c++11 -Wall -Wextra

# Name of the output executable
OUTPUT = prac5_simulator

# Source Files
SRCS =  TestingMain.cpp Room.cpp Light.cpp Section.cpp SmartDevice.cpp Thermostat.cpp DoorLock.cpp  OldThermostat.cpp SmartThermostatIntegrator.cpp Command.cpp MacroRoutine.cpp LockAllDoors.cpp TurnOffAllLights.cpp TurnOnAllAlarms.cpp Sensor.cpp Alarm.cpp
# Object Files (from Source Files)
OBJS = $(SRCS:.cpp=.o)

# Default Target
all: $(OUTPUT)

# Link the Object Files to create the Executable
$(OUTPUT): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(OUTPUT)

# Build the Object Files from the Source Files
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean Target
clean:
	rm -f *.o $(OUTPUT)

# Run Target
run: $(OUTPUT)
	./$(OUTPUT)

# Phony Targets
.PHONY: all clean run