/*
 *
 *   ____            _          _____
 *  |  _ \          | |        |  __ \
 *  | |_) |_ __ __ _| | _____  | |__) | __ ___  ___ ___ _   _ _ __ ___
 *  |  _ <| '__/ _` | |/ / _ \ |  ___/ '__/ _ \/ __/ __| | | | '__/ _ \
 *  | |_) | | | (_| |   <  __/ | |   | | |  __/\__ \__ \ |_| | | |  __/
 *  |____/|_|  \__,_|_|\_\___| |_|   |_|  \___||___/___/\__,_|_|  \___|
 *
 * The pressure on the breaks.
 */

#ifndef RENNSMOTORSPORT_BRAKEPRESSURE_H
#define RENNSMOTORSPORT_BRAKEPRESSURE_H

#include "../AnalogSensor.h"

class BrakePressure : public AnalogSensor<float>{
public:

    BrakePressure(int channel, int hZ, int muxChannel) :
        AnalogSensor<float>("BrakePressure", DataLogger<float>(),
            channel, hZ, muxChannel) {
        pressure = -1;
    }

    float get_pressure();

    void update(UDOUBLE var) override;

private:

    float pressure;

    float transfer_function(UDOUBLE rawVal);
    std::string toString(float v) override { return std::to_string(v); }
};


#endif //RENNSMOTORSPORT_BRAKEPRESSURE_H
