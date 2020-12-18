
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include  "MSTK_interface.h"
#include  "MSTK_private.h"
#include  "MSTK_config.h"

static void (*MSTK_CallBack)(void);
static u8 MSTK_u8ModeOfInterval  ;

u32 STMU_Global_U32_TiksCount =0 ;

void MSTK_voidInit(void){


	#if    MSTK_CLOCK_SRC == MSTK_SRC_AHB

		/* Disable Systick , Disable Interrupt , Clock Source = AHB */
		MSTK -> CTRL = 0x00000004;

	#elif  MSTK_CLOCK_SRC == MSTK_SRC_AHB_8

		/* Disable Systick , Disable Interrupt , Clock Source = AHB_8 */
		MSTK -> CTRL = 0x00000000;

	#else
		#warning ("Wrong Systick Clock Configuration")

	#endif

}

void MSTK_voidSetBusyWait( u32 Copy_u32Ticks ){

	MSTK -> LOAD = Copy_u32Ticks - 1 ;

	SET_BIT( MSTK -> CTRL , 0 );

	while( GET_BIT( MSTK -> CTRL , 16 ) == 0 );

	CLR_BIT( MSTK -> CTRL , 0 );
	MSTK -> VAL  = 0 ;
	MSTK -> LOAD = 0 ;

}


void MSTK_voidStopTimer      (void){

	MSTK -> CTRL = 0 ;
	MSTK -> VAL  = 0 ;
	MSTK -> LOAD = 0 ;

}

u32 MSTK_u32GetElapsedTime   (void){

	u32 LOC_u32Result = ( MSTK -> LOAD ) - ( MSTK -> VAL ) ;
	return LOC_u32Result ;

}
u32 MSTK_u32GetRemainingTime (void){

	return (u32)MSTK -> VAL ;

}

void MSTK_voidSetIntervalSingle   ( u32 Copy_u32Ticks , void ( *Copy_ptr )(void) ){

	CLR_BIT( MSTK -> CTRL , 0 );
	MSTK -> VAL = 0            ;

	MSTK -> LOAD = Copy_u32Ticks - 1 ;
	SET_BIT( MSTK -> CTRL , 0 );

	MSTK_CallBack = Copy_ptr ;

	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL ;

	SET_BIT( MSTK -> CTRL , 1 );

}
void MSTK_voidSetIntervalPeriodic ( u32 Copy_u32Ticks , void ( *Copy_ptr )(void) ){

	MSTK -> LOAD = Copy_u32Ticks - 1 ;
	SET_BIT( MSTK -> CTRL , 0 );

	MSTK_CallBack = Copy_ptr ;

	MSTK_u8ModeOfInterval = MSTK_PERIODIC_INTERVAL ;

	SET_BIT( MSTK -> CTRL , 1 );

}

void SysTick_Handler(void){

	u8 LOC_u8ReadFlag = 0;

	STMU_Global_U32_TiksCount++;

	if( MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL ){

		MSTK -> CTRL = 0 ;
		MSTK -> LOAD = 0 ;
		MSTK -> VAL  = 0 ;

	}

	MSTK_CallBack();

	LOC_u8ReadFlag = GET_BIT( MSTK -> CTRL , 16 );

}
