#ifndef _MSTK_PRIVATE_H_
#define _MSTK_PRIVATE_H_

typedef struct{
	
	volatile u32 CTRL  ;
	volatile u32 LOAD  ;
	volatile u32 VAL   ;
	volatile u32 CALIB ;
	
}SysTick_Type;


#define MSTK ((volatile SysTick_Type*)0xE000E010)


#define MSTK_SRC_AHB      0
#define MSTK_SRC_AHB_8    1

#define MSTK_SINGLE_INTERVAL       0
#define MSTK_PERIODIC_INTERVAL     1


#endif