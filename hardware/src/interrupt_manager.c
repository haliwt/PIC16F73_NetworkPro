#include "../inc/interrupt_manager.h"


void __interrupt() INTERRUPT_InterruptManager (void)
{
    // interrupt handler
   if(PIE1bits.TMR1IE == 1 && PIR1bits.TMR1IF == 1)
     {
            TMR1_ISR();
     } 
	else if(INTCONbits.PEIE == 1)
    {
        
        if(INTCONbits.TMR0IE == 1 && INTCONbits.TMR0IF == 1)
	    {
	        TMR0_ISR();
	    }
        else if(PIE1bits.TMR2IE == 1 && PIR1bits.TMR2IF == 1)
        {
            TMR2_ISR();
        }
        else if(PIE1bits.RCIE == 1 && PIR1bits.RCIF == 1)
       {
          // EUSART_RxDefaultInterruptHandler();
       } 
       else{
         
         
         }
       

    }      
    else
    {
        //Unhandled Interrupt
    }
}