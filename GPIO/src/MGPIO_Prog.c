/*MGPIO_Prog.c
*  Created on: 2/12/2020
*      Author: Alaa Elanagar
			 Mobile:+201019793647
*/


#include "STD_TYPES.h"
#include "BIT_MATH.H"
#include "MGPIO_Interface.h"
#include "MGPIO_Private.h"


void MGPIO_VidSetPinDirection   (u8 Copy_U8Port  , u8 Copy_U8Pin , u8 Copy_U8Mode){


	switch (Copy_U8Port){

	case  MGPIO_PORTA :

		if (Copy_U8Pin<=7){

			MGPIOA -> CRL &= ~((0b1111) <<  (Copy_U8Pin*4));
			MGPIOA -> CRL |= ((Copy_U8Mode) <<  (Copy_U8Pin*4));
		}


		else if (Copy_U8Pin>7){
			MGPIOA -> CRH &= ~((0b1111) <<  ((Copy_U8Pin-8)*4));
			MGPIOA -> CRH |= ((Copy_U8Mode) <<  ((Copy_U8Pin-8)*4));
		}

		break ;



	case  MGPIO_PORTB :

		if (Copy_U8Pin<=7){

			MGPIOA -> CRL &= ~((0b1111) <<  (Copy_U8Pin*4));
			MGPIOA -> CRL |= ((Copy_U8Mode) <<  (Copy_U8Pin*4));
		}


		else if (Copy_U8Pin>7){
			MGPIOA -> CRH &= ~((0b1111) <<  ((Copy_U8Pin-8)*4));
			MGPIOA -> CRH |= ((Copy_U8Mode) <<  ((Copy_U8Pin-8)*4));
		}

		break ;


	case  MGPIO_PORTC :

		if (Copy_U8Pin<=7){

			MGPIOA -> CRL &= ~((0b1111) <<  (Copy_U8Pin*4));
			MGPIOA -> CRL |= ((Copy_U8Mode) <<  (Copy_U8Pin*4));
		}

		else if (Copy_U8Pin>7){
			MGPIOA -> CRH &= ~((0b1111) <<  ((Copy_U8Pin-8)*4));
			MGPIOA -> CRH |= ((Copy_U8Mode) <<  ((Copy_U8Pin-8)*4));
		}

		break ;

	}




}




void MGPIO_VidSetPinValue   (u8 Copy_U8Port  , u8 Copy_U8Pin , u8 Copy_U8Value){

	switch (Copy_U8Port){

	case  MGPIO_PORTA :

		if (Copy_U8Value == MGPIO_HIGH){

			SET_BIT(MGPIOA -> ODR  , Copy_U8Pin);
		}

		else if (Copy_U8Value == MGPIO_LOW){

			CLEAR_BIT(MGPIOA -> ODR , Copy_U8Pin);
		}
		break;

	case  MGPIO_PORTB :

		if (Copy_U8Value == MGPIO_HIGH){

			SET_BIT(MGPIOA -> ODR  , Copy_U8Pin);
		}

		else if (Copy_U8Value == MGPIO_LOW){

			CLEAR_BIT(MGPIOA -> ODR , Copy_U8Pin);
		}
		break;

	case  MGPIO_PORTC :

		if (Copy_U8Value == MGPIO_HIGH){

			SET_BIT(MGPIOA -> ODR , Copy_U8Pin);
		}

		else if (Copy_U8Value == MGPIO_LOW){

			CLEAR_BIT(MGPIOA -> ODR , Copy_U8Pin);
		}
		break;



	}

}


u8 MGPIO_VidGetPinValue   (u8 Copy_U8Port  , u8 Copy_U8Pin ){


	u8 LOC_U8Result  = 0;

	switch (Copy_U8Port){
		case MGPIO_PORTA :   LOC_U8Result = GET_BIT (MGPIOA -> IDR ,Copy_U8Pin);  break;
		case MGPIO_PORTB :   LOC_U8Result = GET_BIT (MGPIOB -> IDR ,Copy_U8Pin);  break;
		case MGPIO_PORTC :   LOC_U8Result = GET_BIT (MGPIOC -> IDR ,Copy_U8Pin);  break;

	}


	return (LOC_U8Result);

}
