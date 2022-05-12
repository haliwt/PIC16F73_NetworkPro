#ifndef  __LCD_H_
#define  __LCD_H_
#include "../../main.h"


#define		BitSET(x,y)		x|=(1<<y)				//置1
#define		BitCLR(x,y)		x&=~(1<<y)				//置0



/**************************************************
	//                a
        //            ---------
        //           |         |
        //         f |         | b
        //           |    g    |
        //            ---------
        //           |         |
        //         e |         | c
        //           |    d    |
        //            ---------   T <- h
        //
**************************************************/
//偶数地址，SEG1~SEG8
#define   seg_a  0x01       //seg_a   //seg_e = 0x10  
#define   seg_b  0x02      //seg_b , //seg_f = 0x20
#define   seg_c  0x04      //seg_c , //seg_g = 0x40
#define   seg_d  0x08      //seg_d , //seg_d = 0x08
#define   seg_e  0x10      //seg_e , //seg_c = 0x04
#define   seg_f  0x20      //seg_f   //seg_a = 0x01
#define   seg_g  0x40      //seg_g   //seg_b = 0x02 
#define   seg_h  0x80      //"T"






void LCD_Display_Off(void);


void LCDDisplay_Humidity(uint8_t dat);

void LCDDisplay_Temperature(uint8_t dat);

void LCDDispaly_Time(uint8_t tdata);

void Blowing_Rate(uint8_t bdata);


void LCDDisplay_Icon(void);




#endif 
