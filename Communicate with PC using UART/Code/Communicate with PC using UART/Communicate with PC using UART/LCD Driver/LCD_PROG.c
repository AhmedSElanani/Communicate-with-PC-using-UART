//****************************************************************************
#include "LCD_INIT.h"



 void LCD_Vid_4BitInit(void)
{
	CONTROL_PORT_DIR_REG |= (1<<RS) | (1<<RW) | (1<<EN);
	DATA_PORT_DIR_REG	 |= (0xf0);		
	LCD_VidDelay_mS(20);
	DIO_VidSetPinValue(EN,CONTROL_PORT,LOW);
	LCD_Vid_4BitSendCommand(INTERFACE_8BIT_1);	
	LCD_Vid_4BitSendCommand(INTERFACE_8BIT_2);
	LCD_Vid_4BitSendCommand(FUNCTION_SET_4BIT);
	LCD_Vid_4BitSendCommand(DISPLAY_CONTROL);
	LCD_VidClrLCD();
	LCD_Vid_4BitSendCommand(ENTRY_MODE);
	LCD_VidDelay_uS(200); 
}


 void LCD_Vid_4BitSendChar(u8 Data)
 {
	 DATA_PORT_REG = (DATA_PORT_REG & 0x0f) | (Data & 0xf0);
	 DIO_VidSetPinValue(RS,CONTROL_PORT,HIGH);
	 DIO_VidSetPinValue(RW,CONTROL_PORT,LOW);
	 DIO_VidSetPinValue(EN,CONTROL_PORT,HIGH);
	 LCD_VidDelay_uS(1);
	 DIO_VidSetPinValue(EN,CONTROL_PORT,LOW);
	 LCD_VidDelay_uS(20);
	 DATA_PORT_REG = (DATA_PORT_REG & 0x0f) | (Data<<4);
	 DIO_VidSetPinValue(EN,CONTROL_PORT,HIGH);
     LCD_VidDelay_uS(1);
     DIO_VidSetPinValue(EN,CONTROL_PORT,LOW);
     LCD_VidDelay_uS(200);			 
 }
 
 
 void LCD_Vid_4BitSendCommand(u8 Command)
 {
	 DATA_PORT_REG = (DATA_PORT_REG & 0x0f) | (Command & 0xf0);
	 DIO_VidSetPinValue(RS,CONTROL_PORT,LOW);
	 DIO_VidSetPinValue(RW,CONTROL_PORT,LOW);
	 DIO_VidSetPinValue(EN,CONTROL_PORT,HIGH);
	 LCD_VidDelay_uS(1);
	 DIO_VidSetPinValue(EN,CONTROL_PORT,LOW);
	 LCD_VidDelay_uS(20);
	 DATA_PORT_REG = (DATA_PORT_REG & 0x0f) | (Command << 4);
	 DIO_VidSetPinValue(EN,CONTROL_PORT,HIGH);
	 LCD_VidDelay_uS(1);
	 DIO_VidSetPinValue(EN,CONTROL_PORT,LOW);
	 LCD_VidDelay_uS(200); 
 }
 
 
 void LCD_Vid4BitSendString(u8 *PtrToString)
 {
	 while((*PtrToString) != '\0')
	 {
		 LCD_Vid_4BitSendChar(*PtrToString);
		 PtrToString++ ;
	 }
 }


 void LCD_Vid_8BitInit(void)
 {
	CONTROL_PORT_DIR_REG |= (1<<RS) | (1<<RW) | (1<<EN);
	DIO_VidSetPortDirection(DATA_PORT,OUTPUT);
	LCD_VidDelay_mS(20);
	DIO_VidSetPinValue(EN,CONTROL_PORT,LOW);
	LCD_Vid_8BitSendCommand(FUNCTION_SET_8BIT);
	LCD_Vid_8BitSendCommand(DISPLAY_CONTROL);
	LCD_VidClrLCD();
	LCD_Vid_8BitSendCommand(ENTRY_MODE);
 }
 
 
 void LCD_Vid_8BitSendChar(u8 Data)
 {
	DIO_VidSetPortValue(DATA_PORT,Data);		
	DIO_VidSetPinValue(RS,CONTROL_PORT,HIGH);
	DIO_VidSetPinValue(RW,CONTROL_PORT,LOW);
	DIO_VidSetPinValue(EN,CONTROL_PORT,HIGH);
	LCD_VidDelay_uS(1);
	DIO_VidSetPinValue(EN,CONTROL_PORT,LOW);
	LCD_VidDelay_uS(200); 
 }
 
 
 void LCD_Vid_8BitSendCommand(u8 Command)
 {
	DIO_VidSetPortValue(DATA_PORT,Command);		
	DIO_VidSetPinValue(RS,CONTROL_PORT,LOW);	 
	DIO_VidSetPinValue(RW,CONTROL_PORT,LOW);
	DIO_VidSetPinValue(EN,CONTROL_PORT,HIGH);
	LCD_VidDelay_uS(1);
	DIO_VidSetPinValue(EN,CONTROL_PORT,LOW);
	LCD_VidDelay_uS(200);
 }
 
 
void LCD_Vid8BitSendString(u8 *PtrToString)
{
	while((*PtrToString) != '\0')
	{
		LCD_Vid_8BitSendChar(*PtrToString);
		PtrToString++ ;
	}	
}


void LCD_Vid_GoToXY(u8 X,u8 Y)
{
	#if (MODE == 4)
	if (Y==1)
	{
		LCD_Vid_4BitSendCommand(FIRST_LINE + X - 1);
	}
	else
	{
		if (Y==2)
		{
			LCD_Vid_4BitSendCommand(SECOND_LINE + X - 1);
		}
	}
	
	
	#elif (MODE == 8 )
	if (Y==1)
	{
		LCD_Vid_8BitSendCommand(FIRST_LINE + X - 1);
	}
	else
	{
		if (Y==2)
		{
			LCD_Vid_8BitSendCommand(SECOND_LINE + X - 1);
		}
	}


	#endif
}


void LCD_VidClrLCD(void)
{
	#if (MODE == 4)
	LCD_Vid_4BitSendCommand(CLEAR_DISPLAY);
					LCD_VidDelay_mS(5);

	#elif (MODE == 8)
	LCD_Vid_8BitSendCommand(CLEAR_DISPLAY);	
	LCD_VidDelay_uS(200); 
				
	#endif	
}


void LCD_VidDelay_uS(u16 us)
 {
	for (u16 i = 0; i < us; i++)
	{
		_delay_us(1);
	}
	//Modify this Function after making timer module
 }



void LCD_VidDelay_mS(u16 ms)
{
	for (u16 i = 0; i < ms; i++)
	{
		_delay_ms(1);
	}
	//Modify this Function after making timer module
}
 //****************************************************************************
