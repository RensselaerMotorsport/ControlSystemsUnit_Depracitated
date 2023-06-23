//
// Created by harshk on 6/13/2023.
//

#ifndef CONTROLSYSTEMSUNIT_MOTORCONTROLLER_H
#define CONTROLSYSTEMSUNIT_MOTORCONTROLLER_H


class MotorController {
public:
    MotorController(float to, float te);
    float getSensorValue();
    Temperature getMotorTemp();
private:
    //Member Variables:
    //Motor torque in N/m
    float torque;

    //Motor Temperature stored in Celsius
    Temperature temp;
};


#endif //CONTROLSYSTEMSUNIT_MOTORCONTROLLER_H
