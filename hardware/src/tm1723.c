#include "../inc/tm1723.h"




void TM1723_GPIO_Iint(void)
{
  
   TRISBbits.TRISB2 = 0;
   TRISBbits.TRISB4 =0 ;
   TRISBbits.TRISB3 = 0;
   
  
 
}

void TM1723_WriteByte(uint8_t onebyte)
{
   uint8_t i;

   for(i=0;i<8;i++){

      TM1723_SCL =0 ;

      if(onebyte & (1<<i)){

		TM1723_SDA =1;

	  }
	  else{

		 TM1723_SDA =0;
	  }

	  TM1723_SCL =1;
   }
}

/*****************************************************
 * 
 * Function Name: void TM1723_WriteCmd(uint8_t cmd)
 * Funciton : to write command 
 * 
 * 
*****************************************************/
void TM1723_WriteCmd(uint8_t cmd)
{
   TM1723_SCL = 1;
   TM1723_STB = 0;

  TM1723_WriteByte(cmd);

  TM1723_STB = 1;

  __delay_us(10);
   
}
/*****************************************************
 * 
 * Function Name: void TM1723_WriteData(uint8_t addr,uint8_t dat)
 * Funciton : to write command 
 * 
 * 
*****************************************************/
void TM1723_WriteData(uint8_t addr,uint8_t dat)
{
   TM1723_SCL =1;
   TM1723_STB = 0;

   TM1723_WriteByte(addr);
   __delay_us(5);

   TM1723_WriteByte(dat);

   TM1723_STB=1;

}





