#ifndef _MNVIC_PRIVATE_H_
#define _MNVIC_PRIVATE_H_


typedef struct{
	
	volatile u32 ISER[32]     ;
	volatile u32 ICER[32]     ;
	volatile u32 ISPR[32]     ;
	volatile u32 ICPR[32]     ;
	volatile u32 IABR[32]     ;
	volatile u32 RESERVED[32] ;
	volatile u8  IPR[128]     ;//Because This Peripheral is byte access
	
}NVIC_Type;


#define MNVIC ((volatile NVIC_Type *)0xE000E100)

#define MNVIC_STIR *((volatile u32 *)0xE000EF00)

typedef struct {

	volatile u32 CPUID     ;
	volatile u32 ICSR      ;
	volatile u32 VTOR      ;
	volatile u32 AIRCR     ;
	volatile u32 SCR       ;
	volatile u32 CCR       ;
	volatile u32 SHPR1     ;
	volatile u32 SHPR2     ;
	volatile u32 SHPR3     ;
	volatile u32 SHCSR     ;
	volatile u32 CFSR      ;
	volatile u32 HFSR      ;
	volatile u32 RESERVED  ;
	volatile u32 MMFAR     ;
	volatile u32 BFAR      ;

}SCB_Type;


#define MSCB ((volatile SCB_Type*)0xE000ED00)


#define MNVIC_GROUP_4_SUB_0  0x05FA0300 // 4bit for Grou and 0 bit For Sub
#define MNVIC_GROUP_3_SUB_1	 0x05FA0400 // 3bit for Grou and 1 bit For Sub
#define MNVIC_GROUP_2_SUB_2  0x05FA0500 // 2bit for Grou and 2 bit For Sub
#define MNVIC_GROUP_1_SUB_3  0x05FA0600 // 1bit for Grou and 3 bit For Sub
#define MNVIC_GROUP_0_SUB_4  0x05FA0700 // 0bit for Grou and 4 bit For Sub

#endif
