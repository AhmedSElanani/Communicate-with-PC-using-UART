//****************************************************************************
#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_


//	Clock	Frequency
#ifndef F_CPU
#define F_CPU									16000000UL						 // 16 MHz clock speed
#endif

#define		Asynchronous_Enable					1					// (0) for Synchronous mode, (1) for Asynchronous mode

//For asynchronous operations only
#define		DoubleSpeed_Enable					0					// (0) to Disable, (1) to Enable

#define		Parity_Mode							0					// (0) to Disable, (1) Even Parity, (2) Odd Parity
#define		StopBits_Select						2					// (1) for 1 Stop Bit, (2) for 2 Stop Bits
#define		DataSize							8					// Choose from (5) to (9)
#define		BaudRate							9600UL				// Choose from DataSheet the Suitable Value
#define		UART_Receive_Enable					1					// (0) to Disable, (1) to Enable
#define		UART_Transmit_Enable				1					// (0) to Disable, (1) to Enable
#define		UART_ReceiveInterrupt_Enable		1					// (0) to Disable, (1) to Enable


#endif
//****************************************************************************
