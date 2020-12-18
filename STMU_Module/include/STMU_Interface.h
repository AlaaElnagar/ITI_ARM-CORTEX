

#ifndef _STMU_INTERFACE_H_
#define _STMU_INTERFACE_H_



typedef struct {
	
	void (*Task_Func) (void )  ;
	
	u32  Periodicity          ;


}Tasks_t;


 
void STMU_VidAddTask(Tasks_t  Task_Periodicity );


void STMU_VidDisable();


void STMU_VidStartSchudler (u32 Ticks_ms);



#endif 
