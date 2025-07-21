
#include "SEG7MENT.h"



STD_Return_Type SEG7MENT_INITIALIZE(SEG7MENT_CFG *ptr){
      
     STD_Return_Type RET = E_OK ;
     if(NULL == ptr){
       RET = E_NOK ;
     }else{
         for(int i=0 ; i<4 ; i++){
            RET = GPIO_PIN_DIRECTION_INITIALIZE(&(ptr -> seg7ment_pin[i]));
         }    
     }   
 return RET;    
}


STD_Return_Type SEG7MENT_DISPLAY_NUMBER(SEG7MENT_CFG *ptr , uint8 number){
          
     STD_Return_Type RET = E_OK ;
     if(NULL == ptr || number > 9 || number < 0){
       RET = E_NOK ;
     }else{
         for(int i=0 ; i<4 ; i++){
              RET = GPIO_PIN_WRITE_LOGIC(&(ptr -> seg7ment_pin[i]),READ_BIT(number,i));
         }          
     }   
 return RET;   
}
