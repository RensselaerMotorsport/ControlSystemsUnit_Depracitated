//
// Created by harshk on 10/13/2023.
//

#include "Bms.h"

void Bms::update() {
    std::vector<float> var = this->getData();
    highResTime callTime = std::chrono::system_clock::now();
    this->data = transfer_function(var);
    this->dataLog.addValue(callTime, data);
}

BmsData Bms::transfer_function(std::vector<float> rawVal) {
    // This is a placeholder for the actual transfer function
    return BmsData();
}
