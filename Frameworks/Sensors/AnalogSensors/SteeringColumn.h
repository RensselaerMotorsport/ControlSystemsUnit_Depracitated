/*
 *   _____ _                 _              _____      _
 *  / ____| |               (_)            / ____|    | |
 * | (___ | |_ ___  ___ _ __ _ _ __   __ _| |     ___ | |_   _ _ __ ___  _ __
 *  \___ \| __/ _ \/ _ \ '__| | '_ \ / _` | |    / _ \| | | | | '_ ` _ \| '_ \
 *  ____) | ||  __/  __/ |  | | | | | (_| | |___| (_) | | |_| | | | | | | | | |
 * |_____/ \__\___|\___|_|  |_|_| |_|\__, |\_____\___/|_|\__,_|_| |_| |_|_| |_|
 *                                    __/ |
 *                                   |___/
 *
 * Measures the rotation angle of the steering wheel.
 */

#ifndef CONTROLSYSTEMSUNIT_STEERINGCOLUMN_H
#define CONTROLSYSTEMSUNIT_STEERINGCOLUMN_H

#include "../AnalogSensor.h"

class SteeringColumn : public AnalogSensor<float>{
public:
    SteeringColumn(int channel, int hZ, int muxChannel,float off)
            : AnalogSensor<float>("SteeringColumn", DataLogger<float>(), channel, hZ, muxChannel)
    { rotation_angle = -1; zero_offset = off; }

    float get_rotation_angle() { return rotation_angle; }

    void update() override;

private:
    float rotation_angle;
    float zero_offset;

    float transfer_function(UDOUBLE rawVal);
    std::string toString(float v) override { return std::to_string(v); }
};


#endif //CONTROLSYSTEMSUNIT_STEERINGCOLUMN_H
