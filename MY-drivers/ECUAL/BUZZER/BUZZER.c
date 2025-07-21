
#include "./BUZZER.h"





 STD_Return_Type  BUZZER_INITIALIZE (BUZZER_CFG *ptr){
     
     STD_Return_Type RET = E_OK ;
     PIN_CFG ptr1 = {.port = ptr -> port , .pin = ptr -> pin , .logic = GPIO_LOW , .dir = GPIO_DIRECTION_OUTPUT};
     if(NULL == ptr){
         RET = E_NOK ;
     }else{
         
        RET = GPIO_PIN_DIRECTION_INITIALIZE(&ptr1);
      
      }
     
  return RET; 
 }
 
 //--------------------------------------------------------------------------
 
 STD_Return_Type  BUZZER_TURN_ON (BUZZER_CFG *ptr){
     
          
     STD_Return_Type RET = E_OK ;
     PIN_CFG ptr1 = {.port = ptr -> port , .pin = ptr -> pin , .logic = GPIO_LOW , .dir = GPIO_DIRECTION_OUTPUT};
     if(NULL == ptr){
         RET = E_NOK ;
     }else{
         
        RET = GPIO_PIN_WRITE_LOGIC(&ptr1,GPIO_HIGH);
      
      }
     
  return RET; 
     
 }
 
 //--------------------------------------------------------------------------
 
 STD_Return_Type  BUZZER_TURN_OFF (BUZZER_CFG *ptr){
     
     STD_Return_Type RET = E_OK ;
     PIN_CFG ptr1 = {.port = ptr -> port , .pin = ptr -> pin , .logic = GPIO_LOW , .dir = GPIO_DIRECTION_OUTPUT};
     if(NULL == ptr){
         RET = E_NOK ;
     }else{
         
        RET = GPIO_PIN_WRITE_LOGIC(&ptr1,GPIO_LOW);
      
      }
     
  return RET; 
    
 }

 //--------------------------------------------------------------------------
 
 STD_Return_Type  BUZZER_TOGGLE(BUZZER_CFG *ptr){
     
          
     STD_Return_Type RET = E_OK ;
     PIN_CFG ptr1 = {.port = ptr -> port , .pin = ptr -> pin , .logic = GPIO_LOW , .dir = GPIO_DIRECTION_OUTPUT};
     if(NULL == ptr){
         RET = E_NOK ;
     }else{
         
        RET = GPIO_PIN_TOGGLE_LOGIC(&ptr1);
      
      }
     
  return RET; 
     
 }