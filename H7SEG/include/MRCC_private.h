

#ifndef _MRCC_PRIVATE_
#define _MRCC_PRIVATE_

typedef struct{
	
	volatile u32 CR ;   		//0x00   0x40021000
	volatile u32 CFGR ; 		//0x04
	volatile u32 CIR ; 			//0x08
	volatile u32 APB2RSTR ; 	//0x0C
	volatile u32 APB1RSTR ; 	//0x10
	volatile u32 AHBENR ; 		//0x14
	volatile u32 APB2ENR ; 		//0x18
	volatile u32 APB1ENR ; 		//0x1C
	volatile u32 BDCR ; 		//0x20
	volatile u32 CSR ; 			//0x24
	
}RCC_Type;


#define MRCC ((volatile RCC_Type *)0x40021000)

#define MRCC_HSE_CRYSTAL 0
#define MRCC_HSE_RC		 1
#define MRCC_HSI         2
#define MRCC_PLL		 3

#define MRCC_PLL_IN_HSI_2   0
#define MRCC_PLL_IN_HSE_2   1
#define MRCC_PLL_IN_HSE     2

#define MRCC_ENABLE_CS     1
#define MRCC_DISABLE_CS    0

#define MRCC_PLL_MUL_BY_2    0
#define MRCC_PLL_MUL_BY_3    1
#define MRCC_PLL_MUL_BY_4    2
#define MRCC_PLL_MUL_BY_5    3
#define MRCC_PLL_MUL_BY_6    4
#define MRCC_PLL_MUL_BY_7    5
#define MRCC_PLL_MUL_BY_8    6
#define MRCC_PLL_MUL_BY_9    7
#define MRCC_PLL_MUL_BY_10   8
#define MRCC_PLL_MUL_BY_11   9
#define MRCC_PLL_MUL_BY_12   10 
#define MRCC_PLL_MUL_BY_13   11
#define MRCC_PLL_MUL_BY_14   12
#define MRCC_PLL_MUL_BY_15   13
#define MRCC_PLL_MUL_BY_16   14



#endif