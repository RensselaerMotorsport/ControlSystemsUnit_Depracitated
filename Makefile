# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -g -O0 -lpthread -I../Includes

# Source files
SOURCES = Frameworks/Sensor.cpp \
          Frameworks/DataLogger.cpp \
          Frameworks/Sensors/Temperature.cpp \
          Frameworks/Scheduler.cpp \
          Tests/SchedulerTest.cpp \
          Frameworks/ThreadPool.cpp

# Output binary
OUTPUT = SchedulerTest.out

# Build rule
all: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(OUTPUT)

# Clean rule
clean:
	rm -f $(OUTPUT)
