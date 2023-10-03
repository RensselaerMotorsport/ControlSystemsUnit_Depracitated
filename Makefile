# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -g -O0 -lpthread -IIncludes

# Source files
SOURCES = Frameworks/Sensor.cpp \
          Frameworks/DataLogger.cpp \
          Frameworks/Sensors/Accelerometer.cpp \
          Frameworks/Sensors/Temperature.cpp \
          Frameworks/Sensors/WheelSpeed.cpp \
          Frameworks/Scheduler.cpp \
          Tests/SchedulerTest.cpp \
          Frameworks/ThreadPool.cpp

# Output binary
OUTPUT = SchedulerTest.out

# Build rule
all: $(SOURCES)
	$(CXX) $(SOURCES) -o $(OUTPUT) $(CXXFLAGS)

# Clean rule
clean:
	rm -f $(OUTPUT)
