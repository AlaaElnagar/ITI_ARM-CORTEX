/*
 * MRCC_Interface.h
*  Created on: 2/12/2020
*      Author: Alaa Elanagar
			 Mobile:+201019793647
 */

#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_




#define MRCC_AHB		0
#define MRCC_APB1		1
#define MRCC_APB2		2

/* AHB */

/* APB2 */
#define MRCC_GPIOA_EN		2
#define MRCC_GPIOB_EN		3
#define MRCC_GPIOC_EN		4




/* APB1*/

void MRCC_VidInitSysClock (void);

void MRCC_VidEnablePeriClock(u8 copy_U8BusID , u8 copy_U8PerID);

void MRCC_VidDisablePeriClock(u8 copy_U8BusID , u8 copy_U8PerID);





























#endif /* MRCC_INTERFACE_H_ */
