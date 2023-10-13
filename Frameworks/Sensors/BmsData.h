//
// Created by harshk on 10/13/2023.
//

#ifndef CONTROLSYSTEMSUNIT_BMSDATA_H
#define CONTROLSYSTEMSUNIT_BMSDATA_H


class BmsData {
public:
    BmsData();
    BmsData(float ccl, float dcl, float t, float sc, float cr, float pr, float cv, float pv, bool cf);

    float getChargeCurrentLimit() { return chargeCurrentLimit; }
    float getDischargeCurrentLimit() { return dischargeCurrentLimit; }
    float getTemperature() { return temperature; }
    float getStateOfCharge() { return stateOfCharge; }
    float getCellResistance() { return cellResistance; }
    float getPackResistance() { return packResistance; }
    float getCellVoltage() { return cellVoltage; }
    float getPackVoltage() { return packVoltage; }
    bool getCriticalFaults() { return criticalFaults; }
private:
    float chargeCurrentLimit;
    float dischargeCurrentLimit;
    float temperature;
    float stateOfCharge;
    float cellResistance;
    float packResistance;
    float cellVoltage;
    float packVoltage;
    bool criticalFaults;
};


#endif //CONTROLSYSTEMSUNIT_BMSDATA_H
