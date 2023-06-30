//RCOS: This file is currently being adapted from the original Waveshare demo. 


//The sample just provides a simple method of calling the so library for reference. The program receiving and sending functions are set in two threads, and the threads are not synchronized.
//In reality, in client programming, the sending and receiving functions cannot be called at the same time (multi-threading is not supported). If it is in multi-threading, it must be interlocked. Customers need to improve the code by themselves.


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include "waveshare-lib/Canbus/controlcan.h"

#include <ctime>
#include <cstdlib>
#include "unistd.h"



VCI_BOARD_INFO pInfo;//Used to obtain device information.
int count=0;//In the data list, it is used to store the serial number of the list.
VCI_BOARD_INFO pInfo1 [50];
int num=0;

//RCOS: This function hasn't been modified yet, come back to it
void *receive_func(void* param) //receiving thread.
{
	
    int reclen=0;
    VCI_CAN_OBJ rec[3000];//Receive buffer, it is better to set it to 3000.
    int i,j;

    int *run=(int*)param;//Thread starts and exits control.
    int ind=0;


	while((*run)&0x0f)
	{
		if((reclen=VCI_Receive(VCI_USBCAN2,0,ind,rec,3000,100))>0)//Call the receiving function, if there is data, perform data processing and display.
		{
			for(j=0;j<reclen;j++)
			{
			printf("Index:%04d ",count);count++;//The serial number is incremented
			printf("CAN%d RX ID:0x%08X", ind+1, rec[j].ID);//ID
			if(rec[j].ExternFlag==0) printf("Standard");//frame format: standard frame
			if(rec[j].ExternFlag==1) printf(" Extend ");//frame format: extended frame
			if(rec[j].RemoteFlag==0) printf(" Data ");//frame type: data frame
			if(rec[j].RemoteFlag==1) printf(" Remote ");//frame type: remote frame
			printf("DLC:0x%02X",rec[j].DataLen);//frame length
			printf("data:0x"); //data
			for(i = 0; i < rec[j].DataLen; i++)
			{
			printf(" %02X", rec[j].Data[i]);
			}
			printf("TimeStamp:0x%08X",rec[j].TimeStamp);//Time stamp.
			printf("\n");
			}
		}
		ind=!ind;//	Change the channel number so that another channel can be read next time and read alternately.
	}
	printf("run thread exit\n");//exit the receiving thread
	pthread_exit(0);
}

int startCanbus(int dataRateKbps) 
{
	printf("Starting Canbus...\r\n");//Indicates that the program has run

	num=VCI_FindUsbDevice2(pInfo1);

	printf(">>USBCAN DEVICE NUM:");printf("%d", num);printf(" PCS");printf("\n");

	for(int i=0;i<num;i++)
		{
		printf("Device:");printf("%d", i);printf("\n");
                printf(">>Get VCI_ReadBoardInfo success!\n");
		
		printf(">>Serial_Num:");


		for(int j=0; j<20; j++){
			printf("%c", pInfo1[i].str_Serial_Num[j]);
		}
		printf("\n");

		printf(">>hw_Type:");
		for(int j=0; j<10; j++){
			printf("%c", pInfo1[i].str_hw_Type[j]);
		}
		printf("\n");

		printf(">>Firmware Version:V");
		printf("%x", (pInfo1[i].fw_Version&0xF00)>>8);
		printf(".");
		printf("%x", (pInfo1[i].fw_Version&0xF0)>>4);
		printf("%x", pInfo1[i].fw_Version&0xF);
		printf("\n");
	}
	printf(">>\n");
	printf(">>\n");
	printf(">>\n");
	if(VCI_OpenDevice(VCI_USBCAN2,0,0)==1)//turn on the device
	{
		printf(">>open deivce success!\n");//Open the device successfully
	}else
	{
		printf(">>open deivce error!\n");
		exit(1);
	}
	if(VCI_ReadBoardInfo(VCI_USBCAN2,0,&pInfo)==1)//Read device serial number, version and other information.
	{
		printf(">>Obtained board info: \n");
		
		//printf(" %08X", pInfo.hw_Version);printf("\n");
		//printf(" %08X", pInfo.fw_Version);printf("\n");
		//printf(" %08X", pInfo.dr_Version);printf("\n");
		//printf(" %08X", pInfo.in_Version);printf("\n");
		//printf(" %08X", pInfo.irq_Num);printf("\n");
		//printf(" %08X", pInfo.can_Num);printf("\n");
		printf(">>Serial_Num:");

		for(int j=0; j<20; j++){
			printf("%c", pInfo.str_Serial_Num[j]);
		}
		printf("\n");

		printf(">>hw_Type:");
		for(int j=0; j<10; j++){
			printf("%c", pInfo.str_hw_Type[j]);
		}
		printf("\n");

		printf(">>Firmware Version:V");
		printf("%x", (pInfo.fw_Version&0xF00)>>8);
		printf(".");
		printf("%x", (pInfo.fw_Version&0xF0)>>4);
		printf("%x", pInfo.fw_Version&0xF);
		printf("\n");	
	}else
	{
		printf(">>Get VCI_ReadBoardInfo error!\n");
		exit(1);
	}

	
	//Initialization parameters, strict parameters secondary development function library instructions.
	VCI_INIT_CONFIG config;
	config.AccCode=0;
	config.AccMask=0xFFFFFFFF;
	config.Filter=1;//Receive all frames


	//RCOS new section for adjustable data rate
	//To add new data rates, see table on page 7 of https://www.waveshare.com/w/upload/7/7d/Interface_Function_Library_User_Instruction.pdf

	if(dataRateKbps == 250){
		config.Timing0=0x01;
		config.Timing1=0x1C;
	}
	else if(dataRateKbps == 500){
		config.Timing0=0x00;
		config.Timing1=0x1C;
	}
	else if(dataRateKbps == 1000){
		config.Timing0=0x00;
		config.Timing1=0x14;
	}
	else{
		printf("This data rate has not been configured. ");
		printf("Please choose 250, 500, or 1000 kpbs, or add your new speed to ");
		printf("the data rate section of canbus.cpp. \n");
		exit(1);
	}
	

	config.Mode=0;//normal mode	
	
	if(VCI_InitCAN(VCI_USBCAN2,0,0,&config)!=1)
	{
		printf(">>Init CAN1 error\n");
		VCI_CloseDevice(VCI_USBCAN2,0);
	}

	if(VCI_StartCAN(VCI_USBCAN2,0,0)!=1)
	{
		printf(">>Start CAN1 error\n");
		VCI_CloseDevice(VCI_USBCAN2,0);

	}

	if(VCI_InitCAN(VCI_USBCAN2,0,1,&config)!=1)
	{
		printf(">>Init can2 error\n");
		VCI_CloseDevice(VCI_USBCAN2,0);

	}
	if(VCI_StartCAN(VCI_USBCAN2,0,1)!=1)
	{
		printf(">>Start can2 error\n");
		VCI_CloseDevice(VCI_USBCAN2,0);

	}


	//RCOS: Seems like all of that was setup. Below is where we actually start sending data
	//I need to make that into a separate, customizable function. I will start on that next time
	

	printf("Setup complete\n")



	//Frames to be sent, structure settings
	VCI_CAN_OBJ send[1];
	send[0].ID=0;
	send[0].SendType=0;
	send[0].RemoteFlag=0;
	send[0].ExternFlag=1;
	send[0].DataLen=8;
	
	int i=0;
	for(i = 0; i < send[0].DataLen; i++)
	{
		send[0].Data[i] = i;
	}

	int m_run0=1;
	pthread_t threadid;
	int ret;
	ret=pthread_create(&threadid,NULL,receive_func,&m_run0);

	int times = 5;
	while(times--)
	{
		if(VCI_Transmit(VCI_USBCAN2, 0, 0, send, 1) == 1)
		{
			printf("Index:%04d  ",count);count++;
			printf("CAN1 TX ID:0x%08X",send[0].ID);
			if(send[0].ExternFlag==0) printf(" Standard ");
			if(send[0].ExternFlag==1) printf(" Extend   ");
			if(send[0].RemoteFlag==0) printf(" Data   ");
			if(send[0].RemoteFlag==1) printf(" Remote ");
			printf("DLC:0x%02X",send[0].DataLen);
			printf(" data:0x");

			for(i=0;i<send[0].DataLen;i++)
			{
				printf(" %02X",send[0].Data[i]);
			}

			printf("\n");
			send[0].ID+=1;
		}
		else
		{
			break;
		}
		
		if(VCI_Transmit(VCI_USBCAN2, 0, 1, send, 1) == 1)
		{
			printf("Index:%04d  ",count);count++;
			printf("CAN2 TX ID:0x%08X", send[0].ID);
			if(send[0].ExternFlag==0) printf(" Standard ");
			if(send[0].ExternFlag==1) printf(" Extend   ");
			if(send[0].RemoteFlag==0) printf(" Data   ");
			if(send[0].RemoteFlag==1) printf(" Remote ");
			printf("DLC:0x%02X",send[0].DataLen);
			printf(" data:0x");			
			for(i = 0; i < send[0].DataLen; i++)
			{
				printf(" %02X", send[0].Data[i]);
			}
			printf("\n");
			send[0].ID+=1;
		}
		else	break;
	}

	usleep(10000000);//Delay unit us, here set 10 000 000=10s After 10s, close the receiving thread and exit the main program.
	m_run0=0;//Thread shutdown instruction.
	pthread_join(threadid,NULL);//Wait for the thread to close.
	usleep(100000);//delay 100ms.
	VCI_ResetCAN(VCI_USBCAN2, 0, 0);//Reset CAN1 channel.
	usleep(100000);//delay 100ms.
	VCI_ResetCAN(VCI_USBCAN2, 0, 1);//Reset CAN2 channel.
	usleep(100000);//delay 100ms.
	VCI_CloseDevice(VCI_USBCAN2,0);//Close the device.
	//Besides the sending and receiving functions, it is better to add a millisecond-level delay before and after calling other functions, which will not affect the running of the program and allow the USBCAN device to have sufficient time to process instructions.
	//goto ext;

}


//RCOS
int main(){
	startCanbus(250)
}
