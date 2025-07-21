#include "BUTTON.h"



STD_Return_Type BUTTON_INITIALIZE(BUTTON_CFG *ptr){
   
    STD_Return_Type RET = E_OK ;
    PIN_CFG ptr1 = {.port = ptr -> port , .pin = ptr -> pin , .logic = GPIO_LOW , .dir = GPIO_DIRECTION_INPUT};
    if(NULL == ptr){
        RET = E_NOK ;
    }else{  
       RET = GPIO_PIN_DIRECTION_INITIALIZE(&ptr1); 
    }
  return RET ;
}

//--------------------------------------------------------------------------

STD_Return_Type BUTTON_READ_STATE(BUTTON_CFG *ptr , button_state_t *state){
    
    STD_Return_Type RET = E_OK ;
    logic_t log;
    PIN_CFG ptr1 = {.port = ptr -> port , .pin = ptr -> pin , .logic = GPIO_LOW , .dir = GPIO_DIRECTION_INPUT};
    if(NULL == ptr){
        RET = E_NOK ;
    }else{  
       RET = GPIO_PIN_READ_LOGIC (&ptr1,&log);
       switch(ptr -> connection){
           case BUTTON_ACTIVE_HIGH :
             *state = (log == GPIO_LOW) ? RELEASED : PRESSED ;
             break;
             
           case BUTTON_ACTIVE_LOW :
             *state = (log == GPIO_LOW) ? PRESSED : RELEASED ;
             break;
             
           default :
               RET = E_NOK;
       }
    }
  return RET ;
           
}
