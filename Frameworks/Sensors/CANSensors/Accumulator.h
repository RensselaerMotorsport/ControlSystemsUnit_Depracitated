//
// Created by harshk on 11/3/2023.
//

#ifndef CONTROLSYSTEMSUNIT_ACCUMULATOR_H
#define CONTROLSYSTEMSUNIT_ACCUMULATOR_H

#include "Bms.h"
#include "Imd.h"

enum CHARGE_STATE{ charge , discharge , standby };

class Accumulator {
public:
    Accumulator(Bms* b, Imd* i) { bms = b; imd = i; }

private:
    Bms* bms;
    Imd* imd;
    CHARGE_STATE state = standby;
};


#endif //CONTROLSYSTEMSUNIT_ACCUMULATOR_H
