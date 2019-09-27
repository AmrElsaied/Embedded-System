/*
 * DIO.h
 *
 *  Created on: Aug 31, 2019
 *      Author: 20120
 */

#ifndef DIO_H_
#define DIO_H_

//define variables
// PORTS
#define port0 0
#define port1 1
#define port2 2
#define port3 3


// PINS
#define pin0 0
#define pin1 1
#define pin2 2
#define pin3 3
#define pin4 4
#define pin5 5
#define pin6 6
#define pin7 7

// DIRECTION

#define OUTPUT 1
#define INPUT  0

// VALUE

#define HIGH 1
#define LOW 0
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
