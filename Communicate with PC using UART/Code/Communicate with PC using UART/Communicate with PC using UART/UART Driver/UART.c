//****************************************************************************
#include "UART.h"



/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
static void (*volatile G_USART_RXC)(void) ='\0' ;



/*******************************************************************************
 *									ISRs	    	                           *
 *******************************************************************************/
ISR(USART_RXC_vect)
{
	if (G_USART_RXC!='\0')
	{
		(*G_USART_RXC)();
	}
}




/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/
 void UART_Init(void)
 {
	//Check for any kind of Interrupts are Enabled
	#if (UART_ReceiveInterrupt_Enable == 1)
		asm volatile ("CLI");	//cli();
	#endif
	
	//Begin initialization
	
	//all flags must be set to zero when the UCSRA is written
	//always write bit UDRE to zero when writing the UCSRA Register
	//The TXC Flag can be cleared by writing a one to its bit location.
	UCSRA =  0x40;

	//If URSEL is zero during a write operation, the UBRRH value will be updated.
	//If URSEL is one, the UCSRC setting will be updated.
	
	//Reading the I/O location once returns the UBRRH Register contents.
	//If the register location was read in previous system clock cycle, reading the register in the current clock cycle will return the UCSRC contents.	
	__attribute__((unused)) u8 dummy;
	
	//Check for Selected mode
	#if (Asynchronous_Enable == 1)
		//Enable Asynchronous Operation
		dummy = UCSRC;
		CLR_BIT(UCSRC,UMSEL);
		
		//Disable Synchronous Clock
		dummy = UCSRC;
		CLR_BIT(UCSRC,UCPOL);

		#if (DoubleSpeed_Enable == 1)
			dummy = UCSRC;
			SET_BIT(UCSRA,U2X);
		#endif
	
	#elif (Asynchronous_Enable == 0)
		//Enable Synchronous Operation
		dummy = UCSRC;
		SET_BIT(UCSRC,UMSEL);		
		//Set the Clock Settings
		// ..

	#endif
	
	//Select the Parity Mode
	#if (Parity_Mode == 0)
		//Disable Parity Mode
		dummy = UCSRC;		
		CLR_BIT(UCSRC,UPM0);
		CLR_BIT(UCSRC,UPM1);
		
	#elif (Parity_Mode == 1)
	#elif (Parity_Mode == 2)
	
	#endif
	
	//Select the number of Stop Bits
	#if (StopBits_Select == 1)
		dummy = UCSRC;
		CLR_BIT(UCSRC,USBS);
		
	#elif (StopBits_Select == 2)
		dummy = UCSRC;
		SET_BIT(UCSRC,USBS);
	
	#endif
	
	//Select the Data size
	#if (DataSize == 5)
	#elif (DataSize == 6)
	#elif (DataSize == 7)
	#elif (DataSize == 8)
		dummy = UCSRC;
		SET_BIT(UCSRC,UCSZ0);
		SET_BIT(UCSRC,UCSZ1);
		CLR_BIT(UCSRB,UCSZ2);
	
	#elif (DataSize == 9)
	
	#endif

	//If URSEL is zero during a write operation, the UBRRH value will be updated.
	//If URSEL is one, the UCSRC setting will be updated.
											
	//Reading the I/O location once returns the UBRRH Register contents.
	//If the register location was read in previous system clock cycle, reading the register in the current clock cycle will return the UCSRC contents.									
	CLR_BIT(UBRRH,URSEL);
	
	//Set the Baud Rate
	#if (DoubleSpeed_Enable == 1)
		UBRRH =	(UBRRH & 0xF0) | (((((F_CPU/8)/BaudRate)-1)>>8) & 0xF);
		UBRRL = (((F_CPU/8)/BaudRate)-1) & 0xFF;

	#elif (DoubleSpeed_Enable == 0)
		UBRRH =	(UBRRH & 0xF0) | (((((F_CPU/16)/BaudRate)-1)>>8) & 0xF);
		UBRRL = (((F_CPU/16)/BaudRate)-1) & 0xFF;

	#endif
	
	//Handle Receiver
	#if (UART_Receive_Enable == 1)
		dummy = UCSRC;
		SET_BIT(UCSRB,RXEN);
	#endif
	
	//Handle Transmitter
	#if (UART_Transmit_Enable == 1)
		dummy = UCSRC;
		SET_BIT(UCSRB,TXEN);
	#endif
	
	
	//Handle Receiver Interrupt
	#if (UART_ReceiveInterrupt_Enable == 1)
	SET_BIT(UCSRB,RXCIE);
	asm volatile ("SEI");	//sei();
	#endif
	
 }


void UART_Transmit_Char(u8 data)
{	
	/* Wait for empty transmit buffer */
	while (!GET_BIT(UCSRA,UDRE));
	
	/* Clear the TXC flag */
	SET_BIT(UCSRA,TXC);
	
	/* Put data into buffer, sends the data */
	UDR = data;
}


void UART_Transmit_String(u8 *str)
{
	//Check the end of string
	while(*str != '\0')
	{
		UART_Transmit_Char(*(str++));
	}
}


u8 UART_Receive(void)
{
	//Check whether Interrupt is disabled	
	#if (UART_ReceiveInterrupt_Enable == 0)
		/* Wait for data to be received */
		while (!GET_BIT(UCSRA,RXC));
	#endif
	
	/* Get and return received data from buffer */
	return UDR;
}
 
/*
 * calling back function enable you to use UART_Receive_ISR
 * Any function passed to callback function will be
 * called in ISR
 */
void USART_RXC_Callback(void(*function_ptr) (void))
{
	G_USART_RXC = function_ptr ;
}

 //****************************************************************************