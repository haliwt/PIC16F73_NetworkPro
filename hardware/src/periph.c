#include "../inc/periph.h"static void PTC_OnFun(void);static void PTC_OffFun(void);void Peripheral_Init(void){	TRISCbits.TRISC1 = 0; //as gpio output I/O	TRISCbits.TRISC5 = 0;	TRISCbits.TRISC4 = 0;	Beep_RC1_Out=0;	Fan_RC5_Out=0;	PTC_RC4_Out=0;}void Beep_Fun(void){	if(cmd_t.gCmd_beepTimer ==0 ){		Beep_RC1_Out=1;	}	else{		Beep_RC1_Out=0;	}}void PTC_OnFun(void){      PTC_RA2_LED  =1;  	  PTC_RC4_Out=1;}void PTC_OffFun(void){	PTC_RA2_LED  =0;      PTC_RC4_Out=0;}void FAN_OnFun(void){	Fan_RC5_Out=1;}void FAN_OffFun(void){	Fan_RC5_Out=0;}void PTC_ControlFun(void){     if(cmd_t.tempTotal >  (dht11_t->Temperature_high = DHT11ReadBuyte())){	     FAN_OnFun();      }	 else{	     FAN_OffFun();     } 	}