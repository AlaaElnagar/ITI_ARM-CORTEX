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

			MGPIOB -> CRL &= ~((0b1111) <<  (Copy_U8Pin*4));
			MGPIOB -> CRL |= ((Copy_U8Mode) <<  (Copy_U8Pin*4));
		}


		else if (Copy_U8Pin>7){
			MGPIOB -> CRH &= ~((0b1111) <<  ((Copy_U8Pin-8)*4));
			MGPIOB -> CRH |= ((Copy_U8Mode) <<  ((Copy_U8Pin-8)*4));
		}

		break ;


	case  MGPIO_PORTC :

		if (Copy_U8Pin<=7){

			MGPIOC -> CRL &= ~((0b1111) <<  (Copy_U8Pin*4));
			MGPIOC -> CRL |= ((Copy_U8Mode) <<  (Copy_U8Pin*4));
		}

		else if (Copy_U8Pin>7){
			MGPIOC -> CRH &= ~((0b1111) <<  ((Copy_U8Pin-8)*4));
			MGPIOC -> CRH |= ((Copy_U8Mode) <<  ((Copy_U8Pin-8)*4));
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

/*Port bit set/reset register (GPIOx_BSRR)*/

void MGPIO_VidPortBitSet_BSRR(u8 Copy_U8Port  , u8 Copy_U8PinsNumbre , u8 Copy_U8StartPosition){

	/*converting from decimal to ones  ex2  --->11*/

	if (Copy_U8StartPosition<15){

		u32 Local_U32BSRR_Helper=0;

		switch (Copy_U8Port){


		case MGPIO_PORTA :

			for (u8 i= Copy_U8StartPosition; i< (Copy_U8PinsNumbre+ Copy_U8StartPosition) ; i++){
				SET_BIT(Local_U32BSRR_Helper,i);
			}

			MGPIOA -> BSRR  =Local_U32BSRR_Helper ;

			break;

		case MGPIO_PORTB :

			for (u8 i= Copy_U8StartPosition ; i< (Copy_U8PinsNumbre+ Copy_U8StartPosition) ; i++){
				SET_BIT(Local_U32BSRR_Helper,i);

			}

			MGPIOB -> BSRR  =Local_U32BSRR_Helper ;

			break;


		case MGPIO_PORTC :

			for (u8 i= Copy_U8StartPosition ; i< (Copy_U8PinsNumbre+ Copy_U8StartPosition) ; i++){
				SET_BIT(Local_U32BSRR_Helper,i);

			}

			MGPIOC -> BSRR  =Local_U32BSRR_Helper ;

			break;





}


	}



	else {

#warning "NOT VALID NUMBRR IN MGPIO_Prog.c in  MGPIO_VidPortBitSet_BSRR"

	}

}




/*Port bit set/reset register (GPIOx_BSRR)*/

void MGPIO_VidPortBitReset_BSRR(u8 Copy_U8Port  , u8 Copy_U8PinsNumbre , u8 Copy_U8StartPosition){

	/*converting from decimal to ones  ex2  --->11*/
	if (Copy_U8StartPosition<=15){
		/*TO SWITCH TO SECOND HALF OF BSRR*/
		 Copy_U8StartPosition+=16;
		u32 Local_U32BSRR_Helper=0;

		switch (Copy_U8Port){


		case MGPIO_PORTA :

			for (u8 i= Copy_U8StartPosition; i< (Copy_U8PinsNumbre+ Copy_U8StartPosition) ; i++){
				SET_BIT(Local_U32BSRR_Helper,i);
			}

			MGPIOA -> BSRR  =Local_U32BSRR_Helper ;

			break;

		case MGPIO_PORTB :

			for (u8 i= Copy_U8StartPosition ; i< (Copy_U8PinsNumbre+ Copy_U8StartPosition) ; i++){
				SET_BIT(Local_U32BSRR_Helper,i);

			}

			MGPIOB -> BSRR  =Local_U32BSRR_Helper ;

			break;


		case MGPIO_PORTC :

			for (u8 i= Copy_U8StartPosition ; i< (Copy_U8PinsNumbre+ Copy_U8StartPosition) ; i++){
				SET_BIT(Local_U32BSRR_Helper,i);

			}

			MGPIOC -> BSRR  =Local_U32BSRR_Helper ;

			break;





}


	}



	else {

#warning "NOT VALID NUMBRR IN RESET FUNC MGPIO_Prog.c "

	}

}






