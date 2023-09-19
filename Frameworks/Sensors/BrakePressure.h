/*
 *
 *   ____            _          _____
 *  |  _ \          | |        |  __ \
 *  | |_) |_ __ __ _| | _____  | |__) | __ ___  ___ ___ _   _ _ __ ___
 *  |  _ <| '__/ _` | |/ / _ \ |  ___/ '__/ _ \/ __/ __| | | | '__/ _ \
 *  | |_) | | | (_| |   <  __/ | |   | | |  __/\__ \__ \ |_| | | |  __/
 *  |____/|_|  \__,_|_|\_\___| |_|   |_|  \___||___/___/\__,_|_|  \___|
 *
 *
 */

#ifndef RENNSMOTORSPORT_BRAKEPRESSURE_H
#define RENNSMOTORSPORT_BRAKEPRESSURE_H

#include "../AnalogSensor.h"

class BrakePressure : AnalogSensor<float>{
public:

    BrakePressure() : AnalogSensor<float>() { raw_signal =-1; pressure =-1; }
    BrakePressure(int port, int channel, int hZ) : AnalogSensor<float>("BrakePressure", DataLogger<std::vector<double>>(), port, channel, hZ) { raw_signal =-1; pressure =-1; }
    void transfer_function();
    float get_pressure();

    //TODO: Implement update()
private:

    float raw_signal;
    float pressure;

};


#endif //RENNSMOTORSPORT_BRAKEPRESSURE_H
