//****************************************************************************
#ifndef UART__H_
#define UART__H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "UART_REG.h"
#include "UART_Config.h"
#include <avr/interrupt.h>



/*******************************************************************************
 *                          Functions Prototypes                               *
 *******************************************************************************/
 void UART_Init(void);
 void UART_Transmit_Char(u8 data);
 void UART_Transmit_String(u8 *str);
 u8 UART_Receive(void);
 void USART_RXC_Callback(void(*function_ptr) (void));
 
 
#endif
//****************************************************************************
