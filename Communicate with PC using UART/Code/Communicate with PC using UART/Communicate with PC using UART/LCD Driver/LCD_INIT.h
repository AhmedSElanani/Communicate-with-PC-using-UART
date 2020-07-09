 //****************************************************************************
 #ifndef	LCD_INIT_H_
 #define	LCD_INIT_H_
 

#include "../DIO Driver/DIO_INIT.h"
 #include "LCD_CONFIG.h"
 #include <util/delay.h>

 
 //	Instructions
 #define	FUNCTION_SET_8BIT		0x38
 #define	FUNCTION_SET_4BIT		0x28
 #define	INTERFACE_8BIT_1		0x33				//	Used with 4_BIT
 #define	INTERFACE_8BIT_2		0x32				//	Used with 4_BIT
 #define	DISPLAY_CONTROL			0x0C
 #define	CLEAR_DISPLAY			0x01
 #define	ENTRY_MODE				0x06
 #define	RETURN_HOME				0x02 
 #define	FIRST_LINE				0x80
 #define	SECOND_LINE				0xC0
 #define	SHIFT_CURSOR_RIGHT		0x14



//	Used for both Modes
#if (CONTROL_PORT == portA)
#define  	CONTROL_PORT_DIR_REG		DDRA_REG

#elif (CONTROL_PORT == portB)
#define  	CONTROL_PORT_DIR_REG		DDRB_REG

#elif (CONTROL_PORT == portC)
#define  	CONTROL_PORT_DIR_REG		DDRC_REG

#elif (CONTROL_PORT == portD)
#define  	CONTROL_PORT_DIR_REG		DDRD_REG

#endif



//	Used for 4_Bit Mode
#if (DATA_PORT == portA)
#define		DATA_PORT_REG			PORTA_REG
#define  	DATA_PORT_DIR_REG		DDRA_REG

#elif (DATA_PORT == portB)
#define		DATA_PORT_REG			PORTB_REG
#define  	DATA_PORT_DIR_REG		DDRB_REG

#elif (DATA_PORT == portC)
#define		DATA_PORT_REG			PORTC_REG
#define  	DATA_PORT_DIR_REG		DDRC_REG

#elif (DATA_PORT == portD)
#define		DATA_PORT_REG			PORTD_REG
#define  	DATA_PORT_DIR_REG		DDRD_REG

#endif



//	Functions Prototypes
void LCD_Vid_4BitInit(void);
void LCD_Vid_4BitSendChar(u8 Data);
void LCD_Vid_4BitSendCommand(u8 Command);
void LCD_Vid4BitSendString(u8 *PtrToString);
void LCD_Vid_8BitInit(void);
void LCD_Vid_8BitSendChar(u8 Data);
void LCD_Vid_8BitSendCommand(u8 Command);
void LCD_Vid8BitSendString(u8 *PtrToString);
void LCD_Vid_GoToXY(u8 X,u8 Y);
void LCD_VidClrLCD(void);
void LCD_VidDelay_uS(u16 us);
void LCD_VidDelay_mS(u16 ms);

 
#endif
//****************************************************************************
