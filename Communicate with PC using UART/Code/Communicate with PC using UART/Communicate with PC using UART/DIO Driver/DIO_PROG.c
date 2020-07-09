//****************************************************************************
#include "DIO_INIT.h"


void DIO_VidSetPinDirection(u8 PinNumber, u8 PortNumber, u8 Direction)
{
	switch(PortNumber)
	{
		case portA:
			if (Direction == OUTPUT)
			{
				SET_BIT(DDRA_REG,PinNumber);
			} 
			else
			{
				if (Direction == INPUT)
				{
					CLR_BIT(DDRA_REG,PinNumber);
				}
			}
			
		break;
		
		
		case portB:
		if (Direction == OUTPUT)
		{
			SET_BIT(DDRB_REG,PinNumber);
		}
		else
		{
			if (Direction == INPUT)
			{
				CLR_BIT(DDRB_REG,PinNumber);
			}
		}
		
		break;
		
		
		case portC:
		if (Direction == OUTPUT)
		{
			SET_BIT(DDRC_REG,PinNumber);
		}
		else
		{
			if (Direction == INPUT)
			{
				CLR_BIT(DDRC_REG,PinNumber);
			}
		}
		
		break;
		
		
		case portD:
		if (Direction == OUTPUT)
		{
			SET_BIT(DDRD_REG,PinNumber);
		}
		else
		{
			if (Direction == INPUT)
			{
				CLR_BIT(DDRD_REG,PinNumber);
			}
		}
		
		break;
		
	}	
}

	
void DIO_VidSetPinValue(u8 PinNumber, u8 PortNumber, u8 Value)
{
	switch(PortNumber)
	{
		case portA:
		if (Value == HIGH)
		{
			SET_BIT(PORTA_REG,PinNumber);
		}
		else
		{
			if (Value == LOW)
			{
				CLR_BIT(PORTA_REG,PinNumber);
			}
		}
		
		break;
		
		
		case portB:
		if (Value == HIGH)
		{
			SET_BIT(PORTB_REG,PinNumber);
		}
		else
		{
			if (Value == LOW)
			{
				CLR_BIT(PORTB_REG,PinNumber);
			}
		}
		
		break;
		
		
		case portC:
		if (Value == HIGH)
		{
			SET_BIT(PORTC_REG,PinNumber);
		}
		else
		{
			if (Value == LOW)
			{
				CLR_BIT(PORTC_REG,PinNumber);
			}
		}
		
		break;
		
		case portD:
		if (Value == HIGH)
		{
			SET_BIT(PORTD_REG,PinNumber);
		}
		else
		{
			if (Value == LOW)
			{
				CLR_BIT(PORTD_REG,PinNumber);
			}
		}
		
		break;
		
	}
}


void DIO_VidSetPortDirection( u8 PortNumber, u8 Direction)
{
	switch(PortNumber)
	{
		case portA:
		if (Direction == OUTPUT)
		{
			DDRA_REG = 0xff;
		}
		else
		{
			if (Direction == INPUT)
			{
				DDRA_REG = 0;
			}
		}
		
		break;
		
		
		case portB:
		if (Direction == OUTPUT)
		{
			DDRB_REG = 0xff;
		}
		else
		{
			if (Direction == INPUT)
			{
				DDRB_REG = 0;
			}
		}
		
		break;
		
		
		case portC:
		if (Direction == OUTPUT)
		{
			DDRC_REG = 0xff;
		}
		else
		{
			if (Direction == INPUT)
			{
				DDRC_REG = 0;
			}
		}
		
		break;
		
		case portD:
		if (Direction == OUTPUT)
		{
			DDRD_REG = 0xff;
		}
		else
		{
			if (Direction == INPUT)
			{
				DDRD_REG = 0;
			}
		}
		
		break;
		
	}
}


void DIO_VidSetPortValue( u8 PortNumber,u8 Value)
{
	switch(PortNumber)
	{
		case portA:
			if (Value == HIGH)
			{
				PORTA_REG = 0xff;
			} 
			else
			{
				PORTA_REG = 0;
			}
			
		break;
		
		
		case portB:
			if (Value == HIGH)
			{
				PORTB_REG = 0xff;
			}
			else
			{
				PORTB_REG = 0;
			}
				
		break;
		
		
		case portC:
			if (Value == HIGH)
			{
				PORTC_REG = 0xff;
			}
			else
			{
				PORTC_REG = 0;
			}

		break;

		
		case portD:
			if (Value == HIGH)
			{
				PORTD_REG = 0xff;
			}
			else
			{
				PORTD_REG = 0;
			}

		break;
		
	}	
}


u8 DIO_U8GetPinValue(u8 PinNumber, u8 PortNumber)
{
	u8 PinValue =0;
	
	switch(PortNumber)
	{
		case portA:
		PinValue = GET_BIT(PINA_REG,PinNumber);
		
		break;
		
		
		case portB:
		PinValue = GET_BIT(PINB_REG,PinNumber);
		
		break;
		
		
		case portC:
		PinValue = GET_BIT(PINC_REG,PinNumber);

		break;
		
		case portD:
		PinValue = GET_BIT(PIND_REG,PinNumber);

		break;
		
	}
	
	return PinValue;
	
}

u8 DIO_U8GetPortValue( u8 PortNumber)
{
	u8 PortValue =0;
	
	switch(PortNumber)
	{
		case portA:
		PortValue = PINA_REG;
		
		break;
		
		
		case portB:
		PortValue = PINB_REG;
		
		break;
		
		
		case portC:
		PortValue = PINC_REG;

		break;
		
		case portD:
		PortValue = PIND_REG;

		break;
		
	}
	
	return PortValue;

}
//****************************************************************************

