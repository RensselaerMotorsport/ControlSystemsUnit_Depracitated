//
// Created by harshk on 10/13/2023.
//

#ifndef CONTROLSYSTEMSUNIT_BMS_H
#define CONTROLSYSTEMSUNIT_BMS_H

#include "../CANSensor.h"
#include "BmsData.h"

class Bms: public CANSensor<BmsData, std::vector<float>> {

public:
    Bms(int hz, int id)
            : CANSensor<BmsData>("Bms", DataLogger<BmsData>(), hz, id)
    { data = BmsData(); }
};

    void update(std::vector<float> var) override;

private:
    //This is going to have to construct a new BmsData object using the non-default constructor.
    BmsData transfer_function(std::vector<float> rawVal);

    BmsData data;


#endif //CONTROLSYSTEMSUNIT_BMS_H
