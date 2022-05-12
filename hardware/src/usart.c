#include "../inc/usart.h"

volatile eusart_status_t eusartRxLastError;

/**
  Section: EUSART APIs
  SPEN: Serial Port Enable bit 
*/

void (*EUSART_FramingErrorHandler)(void);
void (*EUSART_OverrunErrorHandler)(void);
void (*EUSART_ErrorHandler)(void);

void EUSART_DefaultFramingErrorHandler(void);
void EUSART_DefaultOverrunErrorHandler(void);
void EUSART_DefaultErrorHandler(void);

void EUSART_Initialize(void)
{
    
    
    BRGH = 1;	// high baud rate 
	SPBRG =25;  // 设置波特率9600 
	SYNC = 0;	// 1=同步接收方式 0=异步接收方式 
	SPEN = 1;	// 串口使能位 
	CREN = 1;	// 1=允许连续接收 0=禁止连续接收 
	SREN = 0;	// 异步方式：此位未用 
	TXIE = 0;	// 关闭发送 
	RCIE = 0;	// 关闭接收中断 
	TX9  = 0;	// 1：选择9位接收 0：选择8位接收 
	RX9  = 0;	// 1：选择9位接收 0：选择8位接收 
	TXEN = 1;	// 发送允许 
	TRISC6=1;   // 作为串口使用，RC6必须设置为输入
	TRISC7=1;   // 作为串口使用，RC7必须设置为输入	
   


    EUSART_SetFramingErrorHandler(EUSART_DefaultFramingErrorHandler);
    EUSART_SetOverrunErrorHandler(EUSART_DefaultOverrunErrorHandler);
    EUSART_SetErrorHandler(EUSART_DefaultErrorHandler);

    eusartRxLastError.status = 0;

    // enable receive interrupt
    PIE1bits.RCIE = 1;
    PIR1bits.RCIF = 0;

}

bool EUSART_is_tx_ready(void)
{
    return (bool)(PIR1bits.TXIF && TXSTAbits.TXEN);
}

bool EUSART_is_rx_ready(void)
{
    return (bool)(PIR1bits.RCIF);
}

bool EUSART_is_tx_done(void)
{
    return TXSTAbits.TRMT;
}

eusart_status_t EUSART_get_last_status(void){
    return eusartRxLastError;
}

uint8_t EUSART_Read(void)
{
    while(!PIR1bits.RCIF)
    {
    }

    eusartRxLastError.status = 0;
    
    if(1 == RCSTAbits.OERR)
    {
        // EUSART error - restart

        RCSTAbits.CREN = 0; 
        RCSTAbits.CREN = 1; 
    }

    return RCREG;
}

void EUSART_Write(uint8_t txData)
{
    while(0 == PIR1bits.TXIF)
    {
    }

    TXREG = txData;    // Write the data byte to the USART.
}

char getch(void)
{
    return EUSART_Read();
}

void putch(char txData)
{
    EUSART_Write(txData);
}



void EUSART_DefaultFramingErrorHandler(void){}

void EUSART_DefaultOverrunErrorHandler(void){
    // EUSART error - restart

    RCSTAbits.CREN = 0;
    RCSTAbits.CREN = 1;

}

void EUSART_DefaultErrorHandler(void){
}

void EUSART_SetFramingErrorHandler(void (* interruptHandler)(void)){
    EUSART_FramingErrorHandler = interruptHandler;
}

void EUSART_SetOverrunErrorHandler(void (* interruptHandler)(void)){
    EUSART_OverrunErrorHandler = interruptHandler;
}

void EUSART_SetErrorHandler(void (* interruptHandler)(void)){
    EUSART_ErrorHandler = interruptHandler;
}


/**
  End of File
*/
