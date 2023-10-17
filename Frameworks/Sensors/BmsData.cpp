//
// Created by harshk on 10/13/2023.
//

#include "BmsData.h"

BmsData::BmsData(float ccl, float dcl, float t, float sc, float cr, float pr, float cv, float pv, bool cf){
    chargeCurrentLimit = ccl;
    dischargeCurrentLimit = dcl;
    temperature = t;
    stateOfCharge = sc;
    cellResistance = cr;
    packResistance = pr;
    cellVoltage = cv;
    packVoltage = pv;
    criticalFaults = cf;
}