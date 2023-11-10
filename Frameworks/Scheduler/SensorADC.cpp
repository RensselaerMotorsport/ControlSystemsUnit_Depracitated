//Adapted from Waveshare's example "main" file
#include "SensorADC.h"

void Handler(int signo)
{
    //System Exit
    printf("\r\n END \r\n");
    DEV_Module_Exit();
    exit(0);
}

//Start up the ADC
void InitADC(void)
{
    // Exception handling:ctrl + c
    signal(SIGINT, Handler);

    printf("Initializing ADS1263... \r\n");
    //sets up Jetson Nano GPIO
    DEV_Module_Init();

    // 0 is singleChannel, 1 is diffChannel
    ADS1263_SetMode(0);

    // The faster the rate, the worse the stability
    // and the need to choose a suitable digital filter(REG_MODE1)
    //contains reset, check chip id, config
    try {
        // Initializing ADC's in Samples Per Second (SPS)
        if (ADS1263_init_ADC1(ADS1263_4800SPS) != 0)
            throw "ADC1 Initialization failed.";
        if (ADS1263_init_ADC2(ADS1263_ADC2_800SPS) != 0)
            throw "ADC2 Initialization failed.";
    } catch (const char* errorMsg) {
        printf("\r\n END \r\n");
        DEV_Module_Exit();
        std::cerr << errorMsg << std::endl;
        exit(0);
    }
}

//Sets the correct channel group on the multiplexer
void SetChannelGroup(int channelGroup){
    //FIXME Not sure if this is the correct format for the Jetson Nano
    UWORD LSB = GPIO_MUX_LSB;
    UWORD MSB = GPIO_MUX_MSB;

    if(channelGroup == 1){
        DEV_Digital_Write(MSB, 0);
        DEV_Digital_Write(LSB, 0);
    }
    else if(channelGroup == 2){
        DEV_Digital_Write(MSB, 0);
        DEV_Digital_Write(LSB, 1);
    }
    else if(channelGroup == 3){
        DEV_Digital_Write(MSB, 1);
        DEV_Digital_Write(LSB, 0);
    }
    else if(channelGroup == 4){
        DEV_Digital_Write(MSB, 1);
        DEV_Digital_Write(LSB, 1);
    }
    //channel 0 is the "fake" channel, don't do anything


    //Waiting for data is already in GetChannalValue, but in case that doesn't work:
    //struct timespec remaining, request = { 0, 30000 };
    //nanosleep(&request, &remaining);
}

//Returns voltage of port
UDOUBLE FetchSensor(int muxChannel, int port){
    SetChannelGroup(muxChannel);

    //This function includes waiting for the data to be ready
    //also sets pin mode, etc
    UDOUBLE rawData = ADS1263_GetChannalValue(port);
    if((rawData>>31) == 1)
        return (REF*2 - rawData/2147483648.0 * REF);      //7fffffff + 1
    else
        return (rawData/2147483647.0 * REF);       //7fffffff


}