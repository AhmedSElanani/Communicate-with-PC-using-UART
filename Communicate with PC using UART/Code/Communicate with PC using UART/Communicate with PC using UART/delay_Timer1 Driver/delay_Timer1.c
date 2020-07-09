//****************************************************************************
#include "delay_Timer1.h"



/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/
 void delay_us_Timer1(u16 microseconds)
 {
	//Initialize Timer_1
		
	//CTC Mode	
	//Select the Compare Output Mode
	//Normal Port Operation
	CLR_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);
	CLR_BIT(TCCR1A,COM1B0);
	CLR_BIT(TCCR1A,COM1B1);

	//Select the CTC Top Value
	//OCR1A
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
	
	//Set the Value of OCR1A
	//The HIGH Byte must be written before the LOW Byte
	OCR1AH = (((F_CPU/1000000UL) * microseconds) >> 8);
	OCR1AL = (((F_CPU/1000000UL) * microseconds) & 0xFF);

	//No Prescaling
	CLR_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
			
	//Poll the flag for Compare Match
	while(!GET_BIT(TIFR,OCF1A));
	
	//Clear the Flag
	SET_BIT(TIFR,OCF1A); 
 }
 
 
 void delay_ms_Timer1(u16 milliseconds)
 {
	 //Initialize Timer_1
	 
	 //CTC Mode
	 //Select the Compare Output Mode
	 //Normal Port Operation
	 CLR_BIT(TCCR1A,COM1A0);
	 CLR_BIT(TCCR1A,COM1A1);
	 CLR_BIT(TCCR1A,COM1B0);
	 CLR_BIT(TCCR1A,COM1B1);

	 //Select the CTC Top Value
	 //OCR1A
	 CLR_BIT(TCCR1A,WGM10);
	 CLR_BIT(TCCR1A,WGM11);
	 SET_BIT(TCCR1B,WGM12);
	 CLR_BIT(TCCR1B,WGM13);
	 
	 //Set the Value of OCR1A
	 //The HIGH Byte must be written before the LOW Byte
	 OCR1AH = ((((F_CPU/1000UL)/256) * milliseconds) >> 8);
	 OCR1AL = ((((F_CPU/1000UL)/256) * milliseconds) & 0xFF);

	 //256 Prescaler
	 CLR_BIT(TCCR1B,CS10);
	 CLR_BIT(TCCR1B,CS11);
	 SET_BIT(TCCR1B,CS12);
	 
	 //Poll the flag for Compare Match
	 while(!GET_BIT(TIFR,OCF1A));
	 
	 //Clear the Flag
	 SET_BIT(TIFR,OCF1A);
 }
 
 
 void delay_s_Timer1(u8 seconds)
 {
	 //Initialize Timer_1
	 
	 //CTC Mode
	 //Select the Compare Output Mode
	 //Normal Port Operation
	 CLR_BIT(TCCR1A,COM1A0);
	 CLR_BIT(TCCR1A,COM1A1);
	 CLR_BIT(TCCR1A,COM1B0);
	 CLR_BIT(TCCR1A,COM1B1);

	 //Select the CTC Top Value
	 //OCR1A
	 CLR_BIT(TCCR1A,WGM10);
	 CLR_BIT(TCCR1A,WGM11);
	 SET_BIT(TCCR1B,WGM12);
	 CLR_BIT(TCCR1B,WGM13);
	 
	 //Set the Value of OCR1A
	 //The HIGH Byte must be written before the LOW Byte
	 OCR1AH = (((F_CPU/1024UL) * seconds) >> 8);
	 OCR1AL = (((F_CPU/1024UL) * seconds) & 0xFF);

	 //1024 Prescaler
	 SET_BIT(TCCR1B,CS10);
	 CLR_BIT(TCCR1B,CS11);
	 SET_BIT(TCCR1B,CS12);
	 
	 //Poll the flag for Compare Match
	 while(!GET_BIT(TIFR,OCF1A));
	 
	 //Clear the Flag
	 SET_BIT(TIFR,OCF1A);
 }
 
 
 
 
 
 //****************************************************************************