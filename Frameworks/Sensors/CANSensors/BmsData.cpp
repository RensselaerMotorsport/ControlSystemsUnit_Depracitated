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

std::string BmsData::toString() {
    return std::to_string(chargeCurrentLimit) + ","
         + std::to_string(dischargeCurrentLimit) + ","
         + std::to_string(temperature) + ","
         + std::to_string(stateOfCharge) + ","
         + std::to_string(cellResistance) + ","
         + std::to_string(packResistance) + ","
         + std::to_string(cellVoltage) + ","
         + std::to_string(packVoltage) + ","
         + std::to_string(criticalFaults);
}

std::ostream& operator<<(std::ostream& os, const BmsData& bd){
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
