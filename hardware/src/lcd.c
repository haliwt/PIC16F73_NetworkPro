#include "../inc/lcd.h"



const unsigned char segNumber[]={
	
     
         seg_a+seg_b+seg_c+seg_d+seg_e+seg_f,        				// char "0"  0x00
         seg_b+seg_c,                           					// char "1"  0x01
         seg_a+seg_b+seg_d+seg_e+seg_g,              				// char "2"  0x02
         seg_a+seg_b+seg_c+seg_d+seg_g,               				// char "3"  0x03
         seg_b+seg_c+seg_f+seg_g,                   	    		// char "4"  0x04
         seg_a+seg_c+seg_d+seg_f+seg_g,              				// char "5"  0x05
         seg_a+seg_c+seg_d+seg_e+seg_f+seg_g,              			// char "6"  0x06
         seg_a+seg_b+seg_c+seg_f,                    				// char "7"  0x07
         seg_a+seg_b+seg_c+seg_d+seg_e+seg_f+seg_g,  				// char "8"  0x08
         seg_a+seg_b+seg_c+seg_d+seg_f+seg_g,        				// char "9"  0x09
		 seg_h,                         							// char "T"  0x0A
};


		 



/****************************************************************************************************
 * 	*
	*函数名称：void LCDDisplay_Humidity(uint8_t addr,uint8_t dat);
	*函数功能：
	*入口参数：addr ->display of address ,dat -> diplay of data
	*出口参数：NO
	*
*******************************************************************************************************/
void LCDDisplay_Humidity(uint8_t dat)
{
    uint8_t temp0,temp1;
	temp0 = dat /10;
	temp1 = dat%10;
	TM1723_WriteCmd(0x00) ;
	TM1723_WriteCmd(0x44);
	TM1723_WriteData(0xc0, 0x00);		//无
	TM1723_WriteData(0xc1, 0x00);		//无
	TM1723_WriteData(0xc3, 0x80);		//display humidity icon
	TM1723_WriteData(0xc4, segNumber[temp0]);//first to write low bit
	TM1723_WriteData(0xc5, segNumber[temp1]);	
	TM1723_WriteDat(0xc6, 0x00);		//无
	TM1723_WriteDat(0xc7, 0x00);  	//无
	TM1723_WriteDat(0xc8, 0x00);  	//无

	TM1723_WriteCmd(OpenDisp);
}


void LCDDisplay_Temperature(uint8_t dat)
{
    uint8_t temp0,temp1;
	temp0 = dat /10;
	temp1 = dat%10;
	TM1723_WriteCmd(0x00) ;
	TM1723_WriteCmd(0x44);
	TM1723_WriteData(0xc0, 0x00);		//无
	TM1723_WriteData(0xc1, 0x00);		//无
	TM1723_WriteData(0xc2, 0x80);		//display temperature icon
	TM1723_WriteData(0xc2, segNumber[temp0]);//first to write low bit
	TM1723_WriteData(0xc3, segNumber[temp1]);

	TM1723_WriteDat(0xc6, 0x00);		//无
	TM1723_WriteDat(0xc7, 0x00);  	//无
	TM1723_WriteDat(0xc8, 0x00);  	//无	

	TM1723_WriteCmd(OpenDisp);

}
/**********************************************************
 * 
 * Function Name:
 * Function: display hours and minute, second
 * 
 * 
***********************************************************/
void LCDDispaly_Time(uint8_t tdata)
{

    uint8_t temp0,temp1;
	temp0 = tdata /10;
	temp1 = tdata %10;
	TM1723_WriteCmd(0x00) ;
	TM1723_WriteCmd(0x44);
	TM1723_WriteData(0xc0, 0x00);		//无
	TM1723_WriteData(0xc1, 0x00);		//无

	TM1723_WriteData(0xc6, 0x00);		//无
	TM1723_WriteData(0xc7, 0x00);  	//无
	TM1723_WriteData(0xc8, 0x00);  	//无
	TM1723_WriteData(0xc9, segNumber[temp0]);//first to write low bit
	TM1723_WriteData(0xca, segNumber[temp1]);

	TM1723_WriteData(0xcb, 0x80);//display '..' icon
	TM1723_WriteData(0xcb, segNumber[temp0]);//first to write low bit
	
	TM1723_WriteData(0xcc, segNumber[temp1]);
	TM1723_WriteData(0xcd, 0x00);  	//无
	
    TM1723_WriteCmd(OpenDisp); 

}
/*************************************************************
 * 
 * Function Name: void Blowing_Rate(uint8_t bdat)
 * Function :wind flow rate
 * Input Ref: blowing rate number max 3
 * Return Ref: NO
 * 
*************************************************************/
void Blowing_Rate(uint8_t bdat)
{
	static uint8_t count;

	        TM1723_WriteCmd(0x00) ;
			TM1723_WriteCmd(0x44);
			TM1723_WriteData(0xc0, 0x00);		//无
			TM1723_WriteData(0xc1, 0x00);		//无
			TM1723_WriteData(0xc6, 0x00);		//无
			TM1723_WriteData(0xc7, 0x00);  		//无
			TM1723_WriteData(0xc8, 0x00);  		//无
	switch(count){

		case 0:
		     if(bdat !=2){
				TM1723_WriteData(0xce, 0x00 | bdat);//first to write low bit	
				TM1723_WriteData(0xce, 0x00);
			 }
			 else{
				TM1723_WriteData(0xce, 0x00);//first to write low bit	
				TM1723_WriteData(0xce, 0x00|bdat);

			 }
			
			
            TM1723_WriteCmd(OpenDisp);
	   break;

	   case 1:
	       if(bdat !=2){
				TM1723_WriteData(0xce, 0x80 |bdat);//"T9"
				TM1723_WriteData(0xcf, 0x00);//first to write low bit	
		   }
		   else{

			  TM1723_WriteData(0xce, 0x80 );//"T9"
			  TM1723_WriteData(0xcf, 0x00| bdat);//first to write low bit	 
		   }
		  TM1723_WriteCmd(OpenDisp);

	   break;


	   case 2:
	      if(bdat !=2){
	      TM1723_WriteData(0xce, 0x01|bdat);//"T10"
		  TM1723_WriteData(0xcf, 0x00);//first to write low bit	
		  }
		  else{
			TM1723_WriteData(0xce, 0x01);//"T10"
			TM1723_WriteData(0xcf, 0x00|bdat);//first to write low bit	
			}
		  TM1723_WriteCmd(OpenDisp);
        break;

		case 3:
		  if(bdat !=2){
	        TM1723_WriteData(0xce, 0x00|bdat);//"T11"
			TM1723_WriteData(0xcf, 0x80);//first to write low bit	
		  }
		  else{
			TM1723_WriteData(0xce, 0x00);//"T11"
			TM1723_WriteData(0xcf, 0x80|bdat);//first to write low bit
          
		  }
		 
		  TM1723_WriteCmd(OpenDisp);
        break;

		case 4:
		if(bdat !=2){
	       TM1723_WriteData(0xce, 0x04|bdat);//"T12"
			TM1723_WriteData(0xcf, 0x00);//first to write low bit	
		}
		else{
			TM1723_WriteData(0xce, 0x04);//"T12"
			TM1723_WriteData(0xcf, 0x00|bdat);//first to write low bit	
		}
		  TM1723_WriteCmd(OpenDisp);
        break;

		case 5:
		if(bdat !=2){
	       TM1723_WriteData(0xce, 0x40|bdat);//"T13"
		   TM1723_WriteData(0xcf, 0x00);//first to write low bit	
		}
		else{
          TM1723_WriteData(0xce, 0x40);//"T13"
		  TM1723_WriteData(0xcf, 0x00|bdat);//first to write low bit	
		}
		  TM1723_WriteCmd(OpenDisp);
        break;

		case 6:
		if(bdat !=2){
	       TM1723_WriteData(0xce, 0x20|bdat);//"T14"
			TM1723_WriteData(0xcf, 0x00);//first to write low bit
		}
		else{
			 TM1723_WriteData(0xce, 0x20);//"T14"
			TM1723_WriteData(0xcf, 0x00|bdat);//first to write low bit
		}	
		  TM1723_WriteCmd(OpenDisp);
        break;

		case 7:
		if(bdat !=2){
	       TM1723_WriteData(0xce, 0x02|bdat);//"T15"
		  TM1723_WriteData(0xcf, 0x00);//first to write low bit	
		}
		else{
		  TM1723_WriteData(0xce, 0x02);//"T15"
		  TM1723_WriteData(0xcf, 0x00 | bdat);//first to write low bit	
		}
		  TM1723_WriteCmd(OpenDisp);
        break;

		case 8: //T1~T15 ALL ON
		if(bdat !=2){
	       TM1723_WriteData(0xce, 0x7F | bdat);//"N"
		  TM1723_WriteData(0xcf, 0x80);//first to write low bit
		}
		else{
		  TM1723_WriteData(0xce, 0x7F);//"N"
		  TM1723_WriteData(0xcf, 0x80 | bdat);//first to write low bit
		}	
		  TM1723_WriteCmd(OpenDisp);
        break;

      default:

	   break;
   
	}
	if(bdat ==0){
	    bdat = 0x10;
    }
	else if(bdat==1){
	  bdat = 0x08;
	}
	else{
        bdat =0x20;
    }
	count++;
	if(count ==8 )count=0;

}

void LCDDisplay_Icon(void)
{
    TM1723_WriteCmd(0x00) ;
	TM1723_WriteCmd(0x44);
	TM1723_WriteData(0xc0, 0x00);		//无
	TM1723_WriteData(0xc1, 0x00);		//无

	TM1723_WriteData(0xc6, 0x00);		//无
	TM1723_WriteData(0xc7, 0x00);  	//无
	

	TM1723_WriteData(0xc4, 0x80);  	//display "T1"
	TM1723_WriteData(0xc5, 0x80);  	//display "T2"
	TM1723_WriteData(0xc8, 0x00);  	//无
	TM1723_WriteData(0xc9, 0x80);  	//display "T3"
	TM1723_WriteData(0xcA, 0x80);  	//display "T4"
	TM1723_WriteData(0xcC, 0x80);  	//display "T5"

	TM1723_WriteData(0xcd, 0x00);  	//无
	TM1723_WriteCmd(OpenDisp);
}









