#ifndef _MSTK_INTERFACE_H_
#define _MSTK_INTERFACE_H_


void MSTK_voidInit(void);

void MSTK_voidSetBusyWait( u32 Copy_u32Ticks );  //Synchronous Function


void MSTK_voidStopTimer      (void);
u32 MSTK_u32GetElapsedTime   (void);
u32 MSTK_u32GetRemainingTime (void);

void MSTK_voidSetIntervalSingle   ( u32 Copy_u32Ticks , void ( *Copy_ptr )(void) );           //Asynchronous Function
void MSTK_voidSetIntervalPeriodic ( u32 Copy_u32Ticks , void ( *Copy_ptr )(void) );           //Asynchronous Function

#endif