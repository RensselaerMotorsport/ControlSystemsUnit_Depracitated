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

friend ostream& BmsData::operator<<(ostream& os, const BmsData& bd){
    os << bd.chargeCurrentLimit << ","
            << bd.dischargeCurrentLimit << ","
            << bd.temperature << ","
            << bd.stateOfCharge << ","
            << bd.cellResistance << ","
            << bd.packResistance << ","
            << bd.cellVoltage << ","
            << bd.packVoltage << ","
            << bd.criticalFaults;
    return os;
}