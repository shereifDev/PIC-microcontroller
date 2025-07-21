

#include "../DC_MOTOR/DC_MOTOR.h"



STD_Return_Type MOTOR_INITIALIZE(MOTOR_CFG *ptr){
    
     STD_Return_Type RET = E_OK ;
     if(NULL == ptr){
       RET = E_NOK ;
     }else{
         
        RET = GPIO_PIN_DIRECTION_INITIALIZE(&(ptr -> motor_pin[MOTOR_PIN1]));
        RET = GPIO_PIN_DIRECTION_INITIALIZE(&(ptr -> motor_pin[MOTOR_PIN2]));
     }   
 return RET; 
}

//--------------------------------------------------------------------------

STD_Return_Type  MOTOR_TURN_RIGHT(MOTOR_CFG *ptr){
    
     STD_Return_Type RET = E_OK ;
     if(NULL == ptr){
        RET = E_NOK ;
     }else{
         
        RET = GPIO_PIN_WRITE_LOGIC(&(ptr -> motor_pin[MOTOR_PIN1]),GPIO_HIGH);
        RET = GPIO_PIN_WRITE_LOGIC(&(ptr -> motor_pin[MOTOR_PIN2]),GPIO_LOW);
     }   
 return RET;  
}

//--------------------------------------------------------------------------

STD_Return_Type  MOTOR_TURN_LEFT(MOTOR_CFG *ptr){
          
     STD_Return_Type RET = E_OK ;
     if(NULL == ptr){
        RET = E_NOK ;
     }else{
         
        RET = GPIO_PIN_WRITE_LOGIC(&(ptr -> motor_pin[MOTOR_PIN2]),GPIO_HIGH);
        RET = GPIO_PIN_WRITE_LOGIC(&(ptr -> motor_pin[MOTOR_PIN1]),GPIO_LOW);
     }   
 return RET;    
}

//--------------------------------------------------------------------------

STD_Return_Type  MOTOR_TURN_OFF(MOTOR_CFG *ptr){
       
     STD_Return_Type RET = E_OK ;
     if(NULL == ptr){
        RET = E_NOK ;
     }else{
         
        RET = GPIO_PIN_WRITE_LOGIC(&(ptr -> motor_pin[MOTOR_PIN1]),GPIO_HIGH);
        RET = GPIO_PIN_WRITE_LOGIC(&(ptr -> motor_pin[MOTOR_PIN2]),GPIO_HIGH);
     }   
 return RET;    
}
