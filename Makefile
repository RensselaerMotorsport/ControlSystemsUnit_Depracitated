# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -g -O0 -lpthread -lm -IIncludes

# Source files
SOURCES = Frameworks/Sensor.cpp \
          Frameworks/DataLogger.cpp \
          Frameworks/Sensors/AnalogSensors/Accelerometer.cpp \
          Frameworks/Sensors/AnalogSensors/BrakePressure.cpp \
          Frameworks/Sensors/AnalogSensors/ShockPot.cpp \
          Frameworks/Sensors/AnalogSensors/Temperature.cpp \
          Frameworks/Sensors/AnalogSensors/WheelSpeed.cpp \
          Frameworks/Sensors/CANSensors/Imd.cpp \
          Frameworks/Scheduler/Scheduler.cpp \
          Tests/SchedulerTest.cpp \
          Frameworks/Scheduler/ThreadPool.cpp

# Output binary
OUTPUT = SchedulerTest.out

# Build rule
all: $(SOURCES) waveshare
	$(CXX) $(SOURCES) -o $(OUTPUT) $(CXXFLAGS)

waveshare:
	make -C High-Pricision_AD_HAT/c

# Clean rule
clean:
	rm -f $(OUTPUT)
