//
// Created by harshk on 6/13/2023.
//

#ifndef CONTROLSYSTEMSUNIT_TEMPERATURE_H
#define CONTROLSYSTEMSUNIT_TEMPERATURE_H


class Temperature {
public:
    Temperature(float t){ temp = t; }
    float getCelsius();
    float getFahrenheit();
private:
    //Member Variables:

    //Stored in Celsius:
    float temp;
};


#endif //CONTROLSYSTEMSUNIT_TEMPERATURE_H
