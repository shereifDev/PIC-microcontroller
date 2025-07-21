
#include "../../MCAL/RELAY.h"


STD_Return_Type RELAY_INITIALIZE(RELAY_CFG *ptr){
    
     STD_Return_Type RET = E_OK ;
     if(NULL == ptr){
         RET = E_NOK ;
     }else{   
         RET = GPIO_PIN_DIRECTION_INITIALIZE(&(ptr -> relay_pin));
     }  
return RET;  
}

//--------------------------------------------------------------------------

STD_Return_Type RELAY_SWITCH_ON(RELAY_CFG *ptr){
    
    STD_Return_Type RET = E_OK ;
    if(NULL == ptr){
        RET = E_NOK ;
    }else{   
        RET = GPIO_PIN_WRITE_LOGIC(&(ptr -> relay_pin),GPIO_HIGH);
    }
return RET;  
}

//--------------------------------------------------------------------------

STD_Return_Type RELAY_SWITCH_OFF(RELAY_CFG *ptr){
    
    STD_Return_Type RET = E_OK ;
    if(NULL == ptr){
        RET = E_NOK ;
    }else{   
        RET = GPIO_PIN_WRITE_LOGIC(&(ptr -> relay_pin),GPIO_LOW);
    }
return RET;  
}
