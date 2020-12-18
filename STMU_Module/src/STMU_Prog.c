

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MSTK_interface.h"
#include "STMU_Private.h"
#include "STMU_Config.h"
#include "STMU_Interface.h"

u8 Global_U8_TaskCount  ;
extern u32 STMU_Global_U32_TiksCount ;
Tasks_t Tasks_t_arr[STMU_MAX_TASKS]  ;

void STMU_VidAddTask(Tasks_t  Task_Periodicity ){
	
	Tasks_t_arr[Global_U8_TaskCount]  = Task_Periodicity;
		Global_U8_TaskCount++ ;

}


void STMU_VidSchdular(void ){
	
	u16 Local_U16Loop = 0;
	
	for (Local_U16Loop=0 ;Local_U16Loop <STMU_MAX_TASKS;Local_U16Loop++){
		
		
		if ( (STMU_Global_U32_TiksCount % Tasks_t_arr[Local_U16Loop].Periodicity ) == 0 ){
			
		
		 Tasks_t_arr[Local_U16Loop].Task_Func() ;

		}
		else {
			
			
			//do nothing 
		}
		
		
	}
		
}
/*send number of tics in ms from 0 to 65536 ms */
void STMU_VidStartSchudler(u32 Ticks_ms)
{

if (Global_U8_TaskCount ==  STMU_MAX_TASKS ){

    MSTK_voidInit () ;

	MSTK_voidSetIntervalPeriodic( (Ticks_ms *ms), STMU_VidSchdular);
	
}
	
}

void STMU_VidDisable(){
	
	MSTK_voidStopTimer ();
	
}
