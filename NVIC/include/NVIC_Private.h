#ifndef   _NVIC_PRIVATE_H_
#define   _NVIC_PRIVATE_H_


typedef struct {
	
	volatile u32 ISER  [32]        ;
	volatile u32 ICER  [32]        ;
	volatile u32 ISPR  [32]        ;
	volatile u32 ICBR  [32]        ;
	volatile u32 IABR       [32]   ;
	volatile u32 RESERVED   [32]   ;
	volatile u8 IPR        [128]   ;    /*Byte access  and each byte cotroll priority */

	
	
}NVIC_Type;
  


#define  MNVIC ((volatile NVIC_Type*)0xE000E100)

#define  MNVIC_STIR *((volatile u32*)0xE000EF00)








#endif
