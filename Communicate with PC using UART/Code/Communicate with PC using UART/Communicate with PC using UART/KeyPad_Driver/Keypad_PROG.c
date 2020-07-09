//****************************************************************************
#include "Keypad_INIT.h"


void Vid_Keypad_INIT(void)
{
	//	Set Pins Direction
	DIO_VidSetPinDirection(R1,KeypadPORT,OUTPUT);
	DIO_VidSetPinDirection(R2,KeypadPORT,OUTPUT);
	DIO_VidSetPinDirection(R3,KeypadPORT,OUTPUT);
	DIO_VidSetPinDirection(R4,KeypadPORT,OUTPUT);
	
	DIO_VidSetPinDirection(C1,KeypadPORT,INPUT);
	DIO_VidSetPinDirection(C2,KeypadPORT,INPUT);
	DIO_VidSetPinDirection(C3,KeypadPORT,INPUT);
	DIO_VidSetPinDirection(C4,KeypadPORT,INPUT);
	
											
	//	Enable Pull_Up Resistors and Output High at the Beginning 
	DIO_VidSetPortValue(KeypadPORT,HIGH);
}
	
	
u8 Keypad_GetPressed(void)
{
	volatile u8 Pressed_Key = 0;
	Keypad_VidDelay_mS(10);										//delay	for debouncing

	for (u8 i=0 ; i<ROW ; i++)
	{
		DIO_VidSetPinValue(Rows[i] ,KeypadPORT,LOW);
		
		for (u8 j=0 ; j<COL ; j++)
		{
			if (!(DIO_U8GetPinValue(Columns[j],KeypadPORT)))
			{
				Pressed_Key = Keypad_Buttons[i][j];
				//Keypad_VidDelay_mS(10);										//delay	for debouncing
				while (!(DIO_U8GetPinValue(Columns[j],KeypadPORT)));		//Wait until the User lifts his Finger
				
				DIO_VidSetPinValue(Rows[i] ,KeypadPORT,HIGH);
				return	Pressed_Key;
			}
		}
		
		DIO_VidSetPinValue(Rows[i] ,KeypadPORT,HIGH);
	}
	
	return Pressed_Key;
}


void Keypad_VidDelay_mS(u16 ms)
{
	for (u16 i = 0; i < ms; i++)
	{
		_delay_ms(1);
	}
	//Modify this Function after making timer module
}
//****************************************************************************
