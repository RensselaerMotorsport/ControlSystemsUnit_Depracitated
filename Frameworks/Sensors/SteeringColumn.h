//
// Created by harshk on 9/29/2023.
//

#ifndef CONTROLSYSTEMSUNIT_STEERINGCOLUMN_H
#define CONTROLSYSTEMSUNIT_STEERINGCOLUMN_H


class SteeringColumn : AnalogSensor<float>{
public:
    SteeringColumn(int port, int channel, int hZ, float off)
            : AnalogSensor<float>("SteeringColumn", DataLogger<float>(), port, channel, hZ)
    { rotation_angle = -1; zero_offset = off; }

    float get_rotation_angle() { return rotation_angle; }

private:
    float rotation_angle;
    float zero_offset;

    float transfer_function(float rawVal);
};


#endif //CONTROLSYSTEMSUNIT_STEERINGCOLUMN_H
