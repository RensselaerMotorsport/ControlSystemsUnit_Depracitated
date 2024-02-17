//
// Created by harshk on 10/13/2023.
//

#include "Bms.h"

void update() {
    std::vector<float> var = this.getData();
    highResTime callTime = std::chrono::system_clock::now();
    this->data = transfer_function(var);
    this->dataLog.addValue(callTime, data);
}
