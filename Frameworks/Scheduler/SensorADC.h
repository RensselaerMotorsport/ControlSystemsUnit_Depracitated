#ifndef ADC_CONTROL_H
#define ADC_CONTROL_H

#include <stdlib.h>     // For exit()
#include <signal.h>     // For signal()
#include <time.h>       // For timespec, nanosleep
#include <stdio.h>      // For printf, fprintf
#include <string.h>     // For string operations
#include <iostream>     // For std::cout, std::cerr
#include <JetsonGPIO.h> // For GPIO pin operations

// Include the ADS1263 driver header -- For Analog Sensor Read
extern "C" {
#include "../../High-Precision_AD_HAT/c/lib/Driver/ADS1263.h"
}

// GPIO pin definitions
#define GPIO_MUX_LSB 38 // 20 on the ADC, 38 on the Jetson Nano
#define GPIO_MUX_MSB 40 // 21 on the ADC, 40 on the Jetson Nano

// ADC test parts
#define TEST_ADC1       1
#define TEST_ADC1_RATE  1
#define TEST_ADC2       1
#define TEST_RTD        1

#define REF         5.08        // Modify according to actual voltage

// Function declarations
void Handler(int signo);
void InitADC(void);
void SetChannelGroup(int channelGroup);
UDOUBLE FetchSensor(int muxChannel, int port);

#endif // ADC_CONTROL_H
