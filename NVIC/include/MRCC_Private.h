/*
 * MRCC_Private.h

 *MGPIO_Prog.c
 *  Created on: 2/12/2020
 *      Author: Alaa Elanagar
 *			 Mobile:+201019793647
 */


#ifndef MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_




typedef struct {

	volatile u32 CR ;
	volatile u32 CFGR ;
	volatile u32 CIR ;
	volatile u32 APB2RSTR ;
	volatile u32 APB1RSTR ;
	volatile u32 AHBENR ;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR ;
	volatile u32 BDCR ;




}RCC_Type;


#define  MRCC ((volatile RCC_Type* )0x40021000 )






#define MRCC_HSE_CRYSTAL				0
#define MRCC_HSE_RC						1
#define MRCC_HSI						2
#define MRCC_HSE_PIL					3




#define MRCC_PLL_IN_HSI_2				0
#define MRCC_PLL_HSE_RC					1
#define MRCC_PLL_HSE_CRYSTAL			2

#endif /* MRCC_PRIVATE_H_ */
