/*
 * DIO.c
 *
 *  Created on: Aug 31, 2019
 *      Author: Amr Elsaied
 */


#include "Std_types.h"
#include "DIO.h"
#include "Register.h"
#include "BitOperation.h"

void DIO_SetPinDirection (U8 Port_number, U8 Pin_number, U8 Direction)
{
	switch (Port_number)
		{
	case port0:

	    if (Direction==OUTPUT)
	    {
	    	SETBIT (DDRA,Pin_number);
	    }
	    else if (Direction==INPUT)
	    {
	    	CLRBIT (DDRA,Pin_number);
	    }
	    else
	    {
	    	SETBIT (DDRA,pin0);
	    	SETBIT (PORTA,pin0);
	    }
	    break;

	case port1:

	    if (Direction==OUTPUT)
	    {
	    	SETBIT (DDRB,Pin_number);
	    }
	    else if (Direction==INPUT)
	    {
	    	CLRBIT (DDRB,Pin_number);
	    }
	    else
	    {
	    	//INVALID DIRECTION PINA0 WILL OUTPUT HIGH
	    	SETBIT (DDRA,pin0);
	    	SETBIT (PORTA,pin0);
	    }


		break;
	case port2:

	    if (Direction==OUTPUT)
	    {
	    	SETBIT (DDRC,Pin_number);
	    }
	    else if (Direction==INPUT)
	    {
	    	CLRBIT (DDRC,Pin_number);
	    }
	    else
	    {
	    	SETBIT (DDRA,pin0);
	    	SETBIT (PORTA,pin0);
	    }


		break;
	case port3:

	    if (Direction==OUTPUT)
	    {
	    	SETBIT (DDRD,Pin_number);
	    }
	    else if (Direction==INPUT)
	    {
	    	CLRBIT (DDRD,Pin_number);
	    }
	    else
	    {
	    	SETBIT (DDRA,pin0);
	    	SETBIT (PORTA,pin0);
	    }
		break;
	default :
		//INVALID PORT PINA1 WILL OUTPUT HIGH
			SETBIT (DDRA,pin1);
			SETBIT (PORTA,pin1);
		break;
		}
}

void DIO_SetPinPullUp (U8 Port_number, U8 Pin_number)
{
  CLRBIT (SFIOR,2);
  switch (Port_number)
  		{
  	case port0:
  			CLRBIT (DDRA,Pin_number);
  			SETBIT (PORTA,Pin_number);
  	        break;
  	case port1:
  	  		CLRBIT (DDRB,Pin_number);
  	  		SETBIT (PORTB,Pin_number);
  	  	    break;
  	case port2:
  	  		CLRBIT (DDRC,Pin_number);
  	  		SETBIT (PORTC,Pin_number);
  	  	    break;
  	case port3:
  	  		CLRBIT (DDRD,Pin_number);
  	  		SETBIT (PORTD,Pin_number);
  	  	    break;
  	default :
  			//INVALID PORT PINA1 WILL OUTPUT HIGH
  			SETBIT (DDRA,pin1);
  			SETBIT (PORTA,pin1);
  			break;
  	    }

}

void DIO_SetPinValue (U8 Port_number, U8 Pin_number, U8 Value)
{
	switch (Port_number)
			{
		case port0:

		    if (Value==HIGH)
		    {
		    	SETBIT (PORTA,Pin_number);
		    }
		    else if (Value==LOW)
		    {
		    	CLRBIT (PORTA,Pin_number);
		    }
		    else
		    {
		    	//INVALID VALUE PINA0 WILL OUTPUT HIGH
		    	SETBIT (DDRA,pin0);
		    	SETBIT (PORTA,pin0);
		    }
		    break;

		case port1:

			if (Value==HIGH)
			{
			   	SETBIT (PORTB,Pin_number);
		    }
			else if (Value==LOW)
		    {
				CLRBIT (PORTB,Pin_number);
		    }
			else
			{
				//INVALID VALUE PINA0 WILL OUTPUT HIGH
				SETBIT (DDRA,pin0);
				SETBIT (PORTA,pin0);
			}
			break;

		case port2:

			if (Value==HIGH)
			{
				SETBIT (PORTC,Pin_number);
		    }
			else if (Value==LOW)
		   {
		    	CLRBIT (PORTC,Pin_number);
		   }
			else
			{
				//INVALID VALUE PINA0 WILL OUTPUT HIGH
				SETBIT (DDRA,pin0);
				SETBIT (PORTA,pin0);
			}
     		break;
		case port3:

			if (Value==HIGH)
			{
				SETBIT (PORTD,Pin_number);
			}
			else if (Value==LOW)
			{
				CLRBIT (PORTD,Pin_number);
			}
			else
			{
				//INVALID VALUE PINA0 WILL OUTPUT HIGH
				SETBIT (DDRA,pin0);
				SETBIT (PORTA,pin0);
			}
			break;
		default :
				//INVALID PORT PINA1 WILL OUTPUT HIGH
				SETBIT (DDRA,pin1);
				SETBIT (PORTA,pin1);
			break;
			}
}

U8 GetPinValue (U8 Port_number, U8 Pin_number)
{
U8 RetVal=0;
switch (Port_number)
  		{
  	case port0:
  		     	CLRBIT (DDRA,Pin_number);
  		     	RetVal=GETBIT (PINA,Pin_number);
  		     	break;
  	case port1:
  	  		    CLRBIT (DDRB,Pin_number);
  	  			RetVal=GETBIT (PINB,Pin_number);
  	  	        break;
  	case port2:
  	  		    CLRBIT (DDRC,Pin_number);
  	  			RetVal=GETBIT (PINC,Pin_number);
  	  	        break;
  	case port3:
  	  		    CLRBIT (DDRD,Pin_number);
  	  			RetVal=GETBIT (PIND,Pin_number);
  	  	        break;
  	default :
  				//INVALID PORT PINA1 WILL OUTPUT HIGH
  				SETBIT (DDRA,pin1);
  				SETBIT (PORTA,pin1);
  				break;
  		}
return RetVal;
}
void DIO_SetPortDirection (U8 Port_number, U8 Direction)
{
	switch (Port_number)
	  		{
	  	case port0:
	  		if (Direction == OUTPUT)
	  		{

	  			/*
	  			 * It can be made by another way and USE For LOOP like that:
	  			 * int i=0;
	  			 * for (i=0; i<8 ; i++)
	  			 * {
	  			 *   SETBIT (DDRA,i);
	  			 * }
	  			 */
		  		SETBIT (DDRA,pin0);
		  		SETBIT (DDRA,pin1);
		  		SETBIT (DDRA,pin2);
		  		SETBIT (DDRA,pin3);
		  		SETBIT (DDRA,pin4);
		  		SETBIT (DDRA,pin5);
		  		SETBIT (DDRA,pin6);
		  		SETBIT (DDRA,pin7);
	  		}
	  		else if (Direction==INPUT)
	  		{
		  		CLRBIT (DDRA,pin0);
		  		CLRBIT (DDRA,pin1);
		  		CLRBIT (DDRA,pin2);
		  		CLRBIT (DDRA,pin3);
		  		CLRBIT (DDRA,pin4);
		  		CLRBIT (DDRA,pin5);
		  		CLRBIT (DDRA,pin6);
		  		CLRBIT (DDRA,pin7);

	  		}

	  	        break;
	  	case port1:
	  		if (Direction == OUTPUT)
	  		{
		  		SETBIT (DDRB,pin0);
		  		SETBIT (DDRB,pin1);
		  		SETBIT (DDRB,pin2);
		  		SETBIT (DDRB,pin3);
		  		SETBIT (DDRB,pin4);
		  		SETBIT (DDRB,pin5);
		  		SETBIT (DDRB,pin6);
		  		SETBIT (DDRB,pin7);
	  		}
	  		else if (Direction==INPUT)
	  		{
		  		CLRBIT (DDRB,pin0);
		  		CLRBIT (DDRB,pin1);
		  		CLRBIT (DDRB,pin2);
		  		CLRBIT (DDRB,pin3);
		  		CLRBIT (DDRB,pin4);
		  		CLRBIT (DDRB,pin5);
		  		CLRBIT (DDRB,pin6);
		  		CLRBIT (DDRB,pin7);

	  		}
	  	  	    break;
	  	case port2:
	  		if (Direction == OUTPUT)
	  		{
		  		SETBIT (DDRC,pin0);
		  		SETBIT (DDRC,pin1);
		  		SETBIT (DDRC,pin2);
		  		SETBIT (DDRC,pin3);
		  		SETBIT (DDRC,pin4);
		  		SETBIT (DDRC,pin5);
		  		SETBIT (DDRC,pin6);
		  		SETBIT (DDRC,pin7);
	  		}
	  		else if (Direction==INPUT)
	  		{
		  		CLRBIT (DDRC,pin0);
		  		CLRBIT (DDRC,pin1);
		  		CLRBIT (DDRC,pin2);
		  		CLRBIT (DDRC,pin3);
		  		CLRBIT (DDRC,pin4);
		  		CLRBIT (DDRC,pin5);
		  		CLRBIT (DDRC,pin6);
		  		CLRBIT (DDRC,pin7);
	  		}
	  	     break;
	  	case port3:
	  		if (Direction == OUTPUT)
	  		{
		  		SETBIT (DDRD,pin0);
		  		SETBIT (DDRD,pin1);
		  		SETBIT (DDRD,pin2);
		  		SETBIT (DDRD,pin3);
		  		SETBIT (DDRD,pin4);
		  		SETBIT (DDRD,pin5);
		  		SETBIT (DDRD,pin6);
		  		SETBIT (DDRD,pin7);
	  		}
	  		else if (Direction==INPUT)
	  		{
		  		CLRBIT (DDRD,pin0);
		  		CLRBIT (DDRD,pin1);
		  		CLRBIT (DDRD,pin2);
		  		CLRBIT (DDRD,pin3);
		  		CLRBIT (DDRD,pin4);
		  		CLRBIT (DDRD,pin5);
		  		CLRBIT (DDRD,pin6);
		  		CLRBIT (DDRD,pin7);

	  		}
	  	  	    break;
	  	  default :
	  			//INVALID PORT PINA1 WILL OUTPUT HIGH
	  			SETBIT (DDRA,pin1);
	  			SETBIT (PORTA,pin1);
	  			break;
	  	    }
}

void DIO_SetPortValue (U8 Port_number, U8 Value)
{
	switch (Port_number)
	  		{
	  	case port0:
	  		    PORTA= Value;
	  		     	break;
	  	case port1:
		     	PORTB= Value;
	  	  	        break;
	  	case port2:
		     	PORTC= Value;
	  	  	        break;
	  	case port3:
		     	PORTD= Value;
	  	  	        break;
	  	default :
	  	//INVALID PORT PINA1 WILL OUTPUT HIGH
	  			SETBIT (DDRA,pin1);
	  			SETBIT (PORTA,pin1);
	  				break;
	  		}
}
