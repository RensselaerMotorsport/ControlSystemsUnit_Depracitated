//Integrates ADC, CANbus, and Data Logger into one program, running concurrently

//Note to whoever finishes the Sensor class: Every sensor needs the following:
//void sensor.update(unsigned double data);
//int sensor.get_poll_rate(); (How many milliseconds should we wait before each read?)
//int sensor.get_channel(); 
//int sensor.get_port();


#include "SensorADC.c"
#include "canbus.cpp"
#include "DataLogger.cpp" //this is in Frameworks, someone needs to make this work using Makefile


std::vector<Sensor> sensors; //This needs to be filled in with all of the Sensors you want to read



void ADCRead(){
    InitADC();
    std::vector<std::int> waitTime; //store how much longer each sensor should wait
    for(int i=0; i<sensors.size(); i++){
        waitTime.push_back(sensor.get_poll_rate());
    }


    unsigned double SensorData;
    int channel;
    int port;

    while(1){
        for(int i=0;i<sensors.size(); i++){
            waitTime[i]--; //deduct 1 ms from the sensor's wait time
            if(waitTime == 0){ //sensor is done waiting

                //update data
                channel = sensors[i].get_channel();
                port = sensors[i].get_port();
                SensorData = FetchSensor(channel, port);
                sensor.update(SensorData);

                waitTime[i] = sensor.get_poll_rate(); //reset timer;
            }
        }
        nanosleep(1000000); //once sensors are done, wait 1ms
    }
}

//These are processes/threads for reading and writing to the CANbus.
//I don't know what will be on each CAN bus yet so I can't put anything here.
//If you only need one thread then just leave the other blank. 
void CANRead(){

}

void CANWrite(){

}




void main(){
    std::vector<std::string> CANBUSids = defaultStartCanbus();
    
    //Parent process: analog read
    //Child 1: CANbus read
    //Child 2: CANbus write

    int pid = fork();
    if(pid==0){
        CANRead();
    }
    else{
        pid = fork();
        if(pid==0){
            CANWrite();
        }
        else{
            ADCRead();
        }
    }
}