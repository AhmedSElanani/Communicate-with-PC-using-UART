/*
 * Communicate with PC using UART.c
 *
 * Created: 08-Jul-20 1:32:13 AM
 * Author : Ahmed Salah
 */ 

//	Define the Clock Frequency
#define			F_CPU					16000000UL

#include "UART Driver/UART.h"
#include "LCD Driver/LCD_INIT.h"
#include "KeyPad_Driver/Keypad_INIT.h"
#include "delay_Timer1 Driver/delay_Timer1.h"
//#include <util/delay.h>


//UART Messages
#define GreetingMessage					(u8*)"Welcome to UART Project!\r\n"
#define UserMessage						(u8*)"\r\nI just sent you: "


//LCD Messages

#define Message_1						(u8*)"UART Project"
#define Message_2						(u8*)"Press any"
#define Message_3						(u8*)"Key..  :) "
#define Message_4						(u8*)"You Sent :   "
#define Message_5						(u8*)"You Received :   "


//Global Variables
static volatile u8 Binary_Semaphore = 0;
static volatile u8 KeyBoard_Button;


//	Function Prototypes
void Receiver_Handler(void);

//Main Entry Point
int main(void)
{
	//Declare a variable to hold the value of pressed keypad button
	volatile u8  keyPad_Button;
	
	//Initialize LCD Display 
    LCD_Vid_4BitInit();
    
    //Send a Message to the User
    LCD_Vid4BitSendString(Message_1);
	delay_s_Timer1(2);	//_delay_ms(2000);
	LCD_VidClrLCD();
	
	//Initialize Keypad
	Vid_Keypad_INIT();
	
	//Prompt the User to press any Key
	LCD_Vid4BitSendString(Message_2);
    LCD_Vid_GoToXY(1,2);
    LCD_Vid4BitSendString(Message_3);
	delay_s_Timer1(3);

	/* Initialize UART */
	USART_RXC_Callback(Receiver_Handler);
	UART_Init();

	//Send greeting message to the User
	UART_Transmit_String(GreetingMessage);
	
	//Print the last two messages to the LCD
	LCD_VidClrLCD();
	LCD_Vid4BitSendString(Message_4);
	LCD_Vid_GoToXY(1,2);
	LCD_Vid4BitSendString(Message_5);
	
    while (1) 
    {
		if((keyPad_Button = Keypad_GetPressed()))
		{			
			//Send using UART
			UART_Transmit_String(UserMessage);
			UART_Transmit_Char(keyPad_Button);

			//Show to the LCD what you sent
			LCD_Vid_GoToXY(16,1);
			LCD_Vid_4BitSendChar(keyPad_Button);
		}
		
		if (Binary_Semaphore==1)
		{
			//Show to the LCD what you Received
			LCD_Vid_GoToXY(16,2);
			LCD_Vid_4BitSendChar(KeyBoard_Button);
			
			//Reset the Binary Semaphore 
			Binary_Semaphore =0;
		}
		
    }
}


//Functions definitions
void Receiver_Handler(void)
{	
	//Read the sent letter
	KeyBoard_Button = UART_Receive();

	//Set the Binary Semaphore
	Binary_Semaphore = 1;
}


