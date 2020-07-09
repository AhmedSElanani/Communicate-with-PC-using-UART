//****************************************************************************
#ifndef UART_REG_H_
#define UART_REG_H_


//	UART Registers
#ifndef	UDR
#define UDR							(*((volatile u8*)(0x2C)))
#endif

#ifndef	UCSRA
#define UCSRA						(*((volatile u8*)(0x2B)))
#endif

#ifndef	UCSRB
#define UCSRB						(*((volatile u8*)(0x2A)))
#endif

#ifndef	UCSRC
#define UCSRC						(*((volatile u8*)(0x40)))
#endif

#ifndef	UBRRH
#define UBRRH						(*((volatile u8*)(0x40)))
#endif

#ifndef	UBRRL
#define UBRRL						(*((volatile u8*)(0x29)))
#endif


//	UART Registers Bits
//UCSRA Register
#define			U2X 							1
#define			UDRE							5
#define			TXC								6
#define			RXC								7


//UCSRB Register
#define			UCSZ2							2
#define			TXEN							3
#define			RXEN							4
#define			RXCIE  							7


//UCSRC Register
#define			UCPOL							0
#define			UCSZ0							1
#define			UCSZ1							2
#define			USBS							3
#define			UPM0							4
#define			UPM1							5
#define			UMSEL							6
#define			URSEL							7

//UBRRH Register
#define			URSEL							7


#endif
//****************************************************************************
