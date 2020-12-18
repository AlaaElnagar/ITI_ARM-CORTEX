#ifndef _MGPIO_PRIVATE_H_
#define _MGPIO_PRIVATE_H_

typedef struct{
	
	volatile u32 CRL   ;
	volatile u32 CRH   ;
	volatile u32 IDR   ;
	volatile u32 ODR   ;
	volatile u32 BSRR  ;
	volatile u32 BRR   ;
	volatile u32 LCKR  ;
	
}GPIO_Type;

#define MGPIOA ((volatile GPIO_Type*)0x40010800)
#define MGPIOB ((volatile GPIO_Type*)0x40010C00)
#define MGPIOC ((volatile GPIO_Type*)0x40011000)

#endif