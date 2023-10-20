#include "AnalogSensor.h"
#include "../High-Pricision_AD_HAT/c/lib/Driver/ADS1263.h" // For Analog Sensor Read

auto AnalogSensor::getData() -> T {
    UDOUBLE data = ADS1263_GetChannalValue(channel);
    return data
}