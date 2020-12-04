/*
 * MRCC_Prog.c

 *  Created on: 2/12/2020
 *      Author: Alaa Elanagar
 *			 Mobile:+201019793647
 */

#include "STD_TYPES.h"

#include "BIT_MATH.h"

#include "MRCC_Config.h"
#include "MRCC_Private.h"
#include "MRCC_Interface.h"

void MRCC_VidInitSysClock (void)
{
	#if MRCC_CLOCK_TYPE == MRCC_HSE_CRYSTAL
		//select HSE
		MRCC -> CFGR=0x00000001;
		//Enable hse and keep hsitrim value as 16
		MRCC->CR	= 0x00010080;
		//wait untill HSE stable
		while( GET_BIT(MRCC -> CR , 17) == 0);

	#elif MRCC_CLOCK_TYPE == MRCC_HSE_RC
		//select HSE
		MRCC ->CFGR	= 0x00000001;
		//Enable
		MRCC ->CR		= 0x00050080;
		//wait untill HSE stable
		while( GET_BIT(MRCC -> CR , 17) == 0);

	#elif MRCC_CLOCK_TYPE == MRCC_HSI
		//select HSI
		MRCC ->CFGR	= 0x00000000;
		//Enable
		MRCC ->CR		= 0x00000081;
		//wait untill HSI stable
		while( GET_BIT(MRCC -> CR , 1) == 0);


	#elif MRCC_CLOCK_TYPE == MRCC_PLL
		//select HSI
		MRCC ->CFGR	= 0x00000000;
		//Enable
		MRCC ->CR		= 0x00000081;
		//select PLL
		MRCC ->CFGR	= 0x00000002;
		#if (MRCC_PLL_MUL_VAL >= MRCC_PLL_MUL_BY_2) && (MRCC_PLL_MUL_VAL <= MRCC_PLL_MUL_BY_16 )
			MRCC -> CFGR &= ~((0b1111) << 18);
			MRCC -> CFGR |= ((MRCC_PLL_MUL_VAL) << 18);
		#else
			#warning ("Wrong MULL Factor For PLL")
		#endif

		#if MRCC_PLL_INPUT == MRCC_PLL_IN_HSI_2
			CLR_BIT(MRCC -> CR , 16);
			CLR_BIT(MRCC -> CFGR , 16);
			CLR_BIT(MRCC -> CFGR , 17);


		#elif 	MRCC_PLL_INPUT == MRCC_PLL_IN_HSE_2
			SET_BIT(MRCC -> CR , 16);
			SET_BIT(MRCC -> CFGR , 16);
			SET_BIT(MRCC -> CFGR , 17);
		#elif 	MRCC_PLL_INPUT == MRCC_PLL_IN_HSE
			SET_BIT(MRCC -> CR , 16);
			SET_BIT(MRCC -> CFGR , 16);
			CLR_BIT(MRCC -> CFGR , 17);
		#endif

		SET_BIT(MRCC -> CR , 24);
		while( GET_BIT(MRCC -> CR , 25) == 0);

	#endif

	#if MRCC_CS_SYS == MRCC_ENABLE_CS
		SET_BIT(MRCC -> CR , 19);
	#elif MRCC_CS_SYS == MRCC_DISABLE_CS
		CLR_BIT(MRCC-> CR , 19);
	#endif
}




void MRCC_VidEnablePeriClock(u8 copy_U8BusID , u8 copy_U8PerID)
{
	switch(copy_U8BusID)
	{
		 case     MRCC_AHB	 :SET_BIT( MRCC -> AHBENR , copy_U8PerID);	break;
	     case     MRCC_APB1 : SET_BIT( MRCC -> APB1ENR , copy_U8PerID);	break;
         case     MRCC_APB2 : SET_BIT( MRCC -> APB2ENR , copy_U8PerID);	break;
	}
}


void MRCC_VidDisablePeriClock(u8 copy_U8BusID , u8 copy_U8PerID)
{
	switch(copy_U8BusID)
	{
		case     MRCC_AHB	 : CLEAR_BIT( MRCC -> AHBENR , copy_U8PerID);	break;
	    case     MRCC_APB1	 : CLEAR_BIT( MRCC -> APB1ENR , copy_U8PerID);	break;
        case     MRCC_APB2	 : CLEAR_BIT( MRCC -> APB2ENR , copy_U8PerID);	break;
	}
}
