/*
 * mian.c
 *
 *  Created on: Aug 31, 2019
 *      Author: Amr Elsaied
 */

#include <util/delay.h>
#include "Std_types.h"
#include "DIO.h"
#include "Register.h"
#include "BitOperation.h"

int main (void )

{
    // SET PINA0 DIRECTION input
	DIO_SetPinDirection (port0, pin0, INPUT);
	// make pull up to pinA0

	DIO_SetPinPullUp(port0,pin0);

	// Set DDRA1 OUTPUT
	DIO_SetPinDirection (port0, pin1, OUTPUT);
while (1)
{
	if (!(GetPinValue(port0,pin0)))  // READ PINA0
	    {
		// TURN ON THE LED
		   DIO_SetPinValue(port0,pin1,HIGH);
	    	_delay_ms(300);
	    	DIO_SetPinValue(port0,pin1,LOW);
	    	_delay_ms(300);


	    }
	    else
	    {

	    	// TURN OFF THE LED
	    	 DIO_SetPinValue(port0,pin1,HIGH);
	    	_delay_ms(800);
	    	DIO_SetPinValue(port0,pin1,LOW);
	    	_delay_ms(800);

	    }
}
}
