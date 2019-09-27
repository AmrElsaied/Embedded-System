/*
 * BitOperation.h
 *
 *  Created on: Aug 31, 2019
 *      Author: 20120
 */

#ifndef BITOPERATION_H_
#define BITOPERATION_H_

#define SETBIT(X,Bit) ((X)|=(unsigned char )1<<(Bit))
#define CLRBIT(X,Bit) ((X)&=~(1<<(Bit)))
#define GETBIT(X,Bit) (((X)>>(Bit))&(1))
#define TOGLEBIT(X,Bit) ((X)^=1<<(Bit))

#endif /* BITOPERATION_H_ */
