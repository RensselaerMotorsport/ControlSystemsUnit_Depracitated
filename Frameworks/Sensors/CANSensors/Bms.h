/*
 *  ____  __  __  _____
 * |  _ \|  \/  |/ ____|
 * | |_) | \  / | (___
 * |  _ <| |\/| |\___ \
 * | |_) | |  | |____) |
 * |____/|_|  |_|_____/
 *
 * Batter Management System
 */

#ifndef CONTROLSYSTEMSUNIT_BMS_H
#define CONTROLSYSTEMSUNIT_BMS_H

#include "../CANSensor.h"
#include "BmsData.h"
#include <vector>

class Bms: public CANSensor<BmsData, std::vector<float>> {

public:
    Bms(int hz, int id)
            : CANSensor<BmsData, std::vector<float>>("Bms", DataLogger<BmsData>(), hz, id)
    { data = BmsData(); }

    void update() override;

private:

    std::string toString(BmsData v) override { return v.toString(); }

    //This is going to have to construct a new BmsData object using the non-default constructor.
    BmsData transfer_function(std::vector<float> rawVal);

    BmsData data;
};


#endif //CONTROLSYSTEMSUNIT_BMS_H
