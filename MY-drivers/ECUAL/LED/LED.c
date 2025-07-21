#include "./LED.h"





 STD_Return_Type  LED_INITIALIZE (LED_CFG *ptr){
     
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
 
 STD_Return_Type  LED_TURN_ON (LED_CFG *ptr){
     
     STD_Return_Type RET = E_OK ;
     PIN_CFG ptr1 = {.port = ptr -> port , .pin = ptr -> pin , .logic = GPIO_LOW , .dir = GPIO_DIRECTION_OUTPUT};
     if(NULL == ptr){
         RET = E_NOK ;
     }else{
         
         switch(ptr -> connection){
             
             case LED_ACTIVE_HIGH :
                RET = GPIO_PIN_WRITE_LOGIC(&ptr1,GPIO_HIGH);
                break;
                
             case LED_ACTIVE_LOW :
                RET = GPIO_PIN_WRITE_LOGIC(&ptr1,GPIO_LOW);
                break;
                
             default:
                RET = E_NOK ;
        }
   
     }
     
  return RET;      
 }

 //--------------------------------------------------------------------------
 
 STD_Return_Type  LED_TURN_OFF (LED_CFG *ptr){
     
     STD_Return_Type RET = E_OK ;
     PIN_CFG ptr1 = {.port = ptr -> port , .pin = ptr -> pin , .logic = GPIO_LOW , .dir = GPIO_DIRECTION_OUTPUT};
     if(NULL == ptr){
         RET = E_NOK ;
     }else{
         
         switch(ptr -> connection){
             
             case LED_ACTIVE_HIGH :
                RET = GPIO_PIN_WRITE_LOGIC(&ptr1,GPIO_LOW);
                break;
                
             case LED_ACTIVE_LOW :
                RET = GPIO_PIN_WRITE_LOGIC(&ptr1,GPIO_HIGH);
                break;
                
             default:
                RET = E_NOK ;
        }
      
      }
     
  return RET; 
 }

 //--------------------------------------------------------------------------
 
 STD_Return_Type  LED_TOGGLE (LED_CFG *ptr){
     
     STD_Return_Type RET = E_OK ;
     PIN_CFG ptr1 = {.port = ptr -> port , .pin = ptr -> pin , .logic = GPIO_LOW , .dir = GPIO_DIRECTION_OUTPUT};
     if(NULL == ptr){
         RET = E_NOK ;
     }else{
         
        RET = GPIO_PIN_TOGGLE_LOGIC(&ptr1) ;
      
      }
     
  return RET; 
 }
 