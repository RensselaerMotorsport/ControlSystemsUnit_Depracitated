# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -g -O0 -lJetsonGPIO -lpthread -lm -IIncludes

# Source files
SOURCES = Frameworks/Sensors/Sensor.cpp \
          Frameworks/Sensors/DataLogger.cpp \
          Frameworks/Sensors/AnalogSensors/Accelerometer.cpp \
          Frameworks/Sensors/AnalogSensors/BrakePressure.cpp \
          Frameworks/Sensors/AnalogSensors/ShockPot.cpp \
          Frameworks/Sensors/AnalogSensors/Temperature.cpp \
          Frameworks/Sensors/AnalogSensors/WheelFlux.cpp \
          Frameworks/Sensors/CANSensors/Imd.cpp \
          Frameworks/Scheduler/Scheduler.cpp \
          Tests/SchedulerTest.cpp \
          Frameworks/Scheduler/ThreadPool.cpp \
          Frameworks/Scheduler/SensorADC.cpp \

# Output binary
OUTPUT = SchedulerTest.out
C_OBJECTS = High-Pricision_AD_HAT/c/bin/*.o

# Build rule
all: $(SOURCES) waveshare
	$(CXX) $(SOURCES) $(C_OBJECTS) -o $(OUTPUT) $(CXXFLAGS) -lbcm2835

waveshare:
	make -C High-Pricision_AD_HAT/c JETSON

# Clean rule
clean:
	rm -f $(OUTPUT)
	make -C High-Pricision_AD_HAT/c clean