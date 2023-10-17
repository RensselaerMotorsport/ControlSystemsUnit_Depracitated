# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -g -O0 -lpthread -lm -IIncludes

# Source files
SOURCES = Frameworks/Sensor.cpp \
          Frameworks/DataLogger.cpp \
          Frameworks/Sensors/Accelerometer.cpp \
          Frameworks/Sensors/BrakePressure.cpp \
          Frameworks/Sensors/ShockPot.cpp \
          Frameworks/Sensors/Temperature.cpp \
          Frameworks/Sensors/WheelSpeed.cpp \
          Frameworks/Sensors/Imd.cpp \
          Frameworks/Scheduler.cpp \
          Tests/SchedulerTest.cpp \
          Frameworks/ThreadPool.cpp

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
