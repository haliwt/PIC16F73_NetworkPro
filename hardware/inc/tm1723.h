#ifndef __TM1723_H_
#define __TM1723_H_
#include "../../main.h"

#define TM1723_SDA             PORTBbits.RB2/// P24   //OUTPUT
#define TM1723_SCL             PORTBbits.RB3//   P25 //OUTPUT 
#define TM1723_STB  	       PORTBbits.RB4// P26	 //片选信号




#define ModeDispTM1617      0x40 //写数据到显示寄存器
		
#define AddrAutoAdd		   0x40//写显示，自动累加地址  
#define AddrFixed 		   0x44//写显示，固定地址  
 

#define OpenDisp           	0x97//开显示
#define CloseDisp			0x80//关显示

 //display address 
#define Addr00H  			0xC0//地址00H
#define Addr01H  			0xC1//地址01H
#define Addr02H  			0xC2//地址02H
#define Addr03H  			0xC3//地址03H
#define Addr04H  			0xC4//地址04H
#define Addr05H  			0xC5//地址05H
#define Addr06H  			0xC6//地址06H
#define Addr07H  			0xC7//地址07H
#define Addr08H  			0xC8//地址08H
#define Addr09H  			0xC9//地址09H
#define Addr0AH  			0xCA//地址0AH
#define Addr0BH  			0xCB//地址0BH
#define Addr0CH             0xCC//地址0CH
#define Addr0DH             0xCD//地址0DH
#define Addr0EH             0xCE//地址0EH
#define Addr0FH             0xCD//地址0FH



 




void TM1723_GPIO_Iint(void);

void TM1723_WriteByte(uint8_t onebyte);

void TM1723_WriteCmd(uint8_t cmd);


void TM1723_WriteData(uint8_t addr,uint8_t dat);



#endif 
