#include "AnalogSensor.h"

UDOUBLE AnalogSensor::getData() override {
        UDOUBLE data = ADS1263_GetChannalValue(channel);
        // Perhaps this to get data
        // UDOUBLE rawData = ADS1263_GetChannalValue(channel);
        // if((rawData>>31) == 1)
        //     return (REF*2 - rawData/2147483648.0 * REF);      //7fffffff + 1
        // else
        //     return (rawData/2147483647.0 * REF);       //7fffffff

        return data;
    }