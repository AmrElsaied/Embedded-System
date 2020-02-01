/*
 * DIO.h
 *
 *  Created on: Aug 31, 2019
 *      Author: Amr Elsaied
 */

#ifndef DIO_H_
#define DIO_H_

#include "DIO_Priv.h"

/*
 *
 * Port_number: port0 --> port3
 * pin_number:  pin0-->pin7
 * Direction:   OUTPUT / INPUT
 * Value (pin):       HIGH / LOW
 * Value (port) : 0 -> 255
 */
/*
 * INVALID DIRECTION ( OUTPUT / INPUT ) PINA0 WILL OUTPUT HIGH
 * INVALID VALUE ( HIGH / LOW ) PINA0 WILL OUTPUT HIGH
 * INVALID PORT PINA1 WILL OUTPUT HIGH
 */
void DIO_SetPinDirection (U8 Port_number, U8 Pin_number, U8 Direction);

void DIO_SetPinPullUp (U8 Port_number, U8 Pin_number);

void DIO_SetPinValue (U8 Port_number, U8 Pin_number, U8 Value);

U8 GetPinValue (U8 Port_number, U8 Pin_number);

void DIO_SetPortDirection (U8 Port_number,U8 Direction);

void DIO_SetPortValue (U8 Port_number, U8 Value);


#endif /* DIO_H_ */
