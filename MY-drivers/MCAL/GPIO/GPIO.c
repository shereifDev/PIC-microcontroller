/* 
 * File:   GPIO.c
 * Author: sherif
 *
 * Created on April 3, 2025, 10:26 AM
 */

#include "GPIO.h"

//______________________________________________________

//volatile uint8* TRIS_REG[5] = {&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
//volatile uint8* LAT_REG[5]  = {&LATA,&LATB,&LATC,&LATD,&LATE};
//volatile uint8* PORT_REG[5] = {&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};

//_______________________________________________________


//<PINS>

                   
STD_Return_Type GPIO_PIN_DIRECTION_INITIALIZE(PIN_CFG *ptr){

    STD_Return_Type RET = E_OK ; 
    
    if((NULL == ptr) || (ptr -> port > GPIO_PORT_MAX-1) || (ptr -> pin > GPIO_PIN_MAX-1) ){
      RET = E_NOK ;
    }else{

      switch(ptr -> port){

           case GPIO_PORTA :
               if (ptr -> dir == GPIO_DIRECTION_OUTPUT) CLR_BIT(TRISA_REG,ptr -> pin) ;
               else  SET_BIT(TRISA_REG,ptr -> pin) ;
               break;

           case GPIO_PORTB :
               if (ptr -> dir == GPIO_DIRECTION_OUTPUT) CLR_BIT(TRISB_REG,ptr -> pin) ;
               else SET_BIT(TRISB_REG,ptr -> pin) ;
               break;

           case GPIO_PORTC :
               if (ptr -> dir == GPIO_DIRECTION_OUTPUT) CLR_BIT(TRISC_REG,ptr -> pin) ;
               else SET_BIT(TRISC_REG,ptr -> pin) ;
               break;

           case GPIO_PORTD :
               if (ptr -> dir == GPIO_DIRECTION_OUTPUT) CLR_BIT(TRISD_REG,ptr -> pin) ;
               else SET_BIT(TRISD_REG,ptr -> pin) ;
               break;

           case GPIO_PORTE :
               if (ptr -> dir == GPIO_DIRECTION_OUTPUT) CLR_BIT(TRISE_REG,ptr -> pin) ;
               else SET_BIT(TRISE_REG,ptr -> pin) ;
               break;

           default :
               RET = E_NOK;
      } 
       RET = GPIO_PORT_WRITE_LOGIC(ptr -> port , 0x00);
    }
 return RET;
}

//
//STD_Return_Type GPIO_PIN_DIRECTION_INITIALIZE(PIN_CFG *ptr){
//
//    STD_Return_Type RET = E_OK ; 
// 
//    if((NULL == ptr) || (ptr ->port > GPIO_PORT_MAX-1) || (ptr ->pin > GPIO_PIN_MAX-1) ){
//      RET = E_NOK ;
//    }else{
//
//        switch(ptr->dir){
//
//            case OUTPUT:
//               CLR_BIT(*(TRIS_REG[ptr->port]),ptr->pin);
//               break; 
//
//            case INPUT:
//               SET_BIT(*(TRIS_REG[ptr->port]),ptr->pin);
//               break; 
//
//            default :
//                RET = E_NOK;
//         }
//       }
//  return RET;
//}

//--------------------------------------------------------------------------

STD_Return_Type GPIO_PIN_GET_DIRECTION(PIN_CFG *ptr,direction_t *state){
    
    STD_Return_Type RET = E_OK ; 

    if((NULL == state) ||(NULL == ptr) || (ptr -> port > GPIO_PORT_MAX-1) || (ptr -> pin > GPIO_PIN_MAX-1) ){
      RET = E_NOK ;
    }else{
        switch(ptr -> port){
           case GPIO_PORTA : *state = READ_BIT(TRISA_REG,ptr -> pin); break;
           case GPIO_PORTB : *state = READ_BIT(TRISB_REG,ptr -> pin); break;
           case GPIO_PORTC : *state = READ_BIT(TRISC_REG,ptr -> pin); break;
           case GPIO_PORTD : *state = READ_BIT(TRISD_REG,ptr -> pin); break;
           case GPIO_PORTE : *state = READ_BIT(TRISA_REG,ptr -> pin); break;
           default :RET = E_NOK;
        }
    }
  return RET;
}


//STD_Return_Type GPIO_PIN_GET_DIRECTION(PIN_CFG *ptr,direction_t *state){
//    
//    STD_Return_Type RET = E_OK ; 
//
//    if((NULL == state) || (NULL == ptr) || (ptr -> port > GPIO_PORT_MAX-1) || (ptr -> pin > GPIO_PIN_MAX-1) ){
//      RET = E_NOK ;
//    }else{
//        
//        *state = READ_BIT(*(TRIS_REG[ptr -> port]),ptr -> pin);  
//    }
//  return RET;
//}


//--------------------------------------------------------------------------
                    
STD_Return_Type GPIO_PIN_WRITE_LOGIC(PIN_CFG *ptr,logic_t log){

    STD_Return_Type RET = E_OK ; 

    if((NULL == ptr) || (ptr -> port > GPIO_PORT_MAX-1) || (ptr -> pin > GPIO_PIN_MAX-1) ){
      RET = E_NOK ;
    }else{

      switch(ptr -> port){

           case GPIO_PORTA :
               if (log == GPIO_HIGH)  SET_BIT(LATA_REG,ptr -> pin) ;
               else  CLR_BIT(LATA_REG,ptr -> pin) ;
               break;

           case GPIO_PORTB :
               if (log == GPIO_HIGH)  SET_BIT(LATB_REG,ptr -> pin) ;
               else  CLR_BIT(LATB_REG,ptr -> pin) ;
               break;
           case GPIO_PORTC :
               if (log == GPIO_HIGH) 
               {
                   SET_BIT(LATC_REG,ptr -> pin);
               }
               else 
               {
                  CLR_BIT(LATC_REG,ptr -> pin);
               }
               break;

           case GPIO_PORTD :
               if (log == GPIO_HIGH)  SET_BIT(LATD_REG,ptr -> pin) ;
              else  CLR_BIT(LATD_REG,ptr -> pin) ;
               break;

           case GPIO_PORTE :
               if (log == GPIO_HIGH)  SET_BIT(LATE_REG,ptr -> pin) ;
               else  CLR_BIT(LATE_REG,ptr -> pin) ;
               break;

           default :
               RET = E_NOK;
       }  
     }
    return RET;
}


// 
//STD_Return_Type GPIO_PIN_WRITE_LOGIC(PIN_CFG *ptr,logic_t log){
//    
//    STD_Return_Type RET = E_OK ; 
//
//    if((NULL == ptr) || (ptr -> port > GPIO_PORT_MAX-1) || (ptr -> pin > GPIO_PIN_MAX-1) ){
//      RET = E_NOK ;
//    }else{
//        
//        switch(log){
//            case GPIO_HIGH :
//                SET_BIT(*(LAT_REG[ptr -> port]),ptr -> pin);
//                break;
//                
//            case GPIO_LOW:
//                CLR_BIT(*(LAT_REG[ptr -> port]),ptr -> pin);
//                break;
//                
//            default :
//                RET = E_NOK;  
//        }
//    }
// return RET; 
//}
//      
//--------------------------------------------------------------------------  

STD_Return_Type GPIO_PIN_READ_LOGIC(PIN_CFG *ptr,logic_t *log){

    STD_Return_Type RET = E_OK ; 

    if((NULL == log) || (NULL == ptr) || (ptr -> port > GPIO_PORT_MAX-1) || (ptr -> pin > GPIO_PIN_MAX-1) ){
      RET = E_NOK ;
    }else{

      switch(ptr -> port){
           case GPIO_PORTA : *log = READ_BIT(PORTA_REG,ptr -> pin) ; break;
           case GPIO_PORTB : *log = READ_BIT(PORTB_REG,ptr -> pin) ; break;
           case GPIO_PORTC : *log = READ_BIT(PORTC_REG,ptr -> pin) ; break;
           case GPIO_PORTD : *log = READ_BIT(PORTD_REG,ptr -> pin) ; break;
           case GPIO_PORTE : *log = READ_BIT(PORTE_REG,ptr -> pin) ; break;
           default : RET = E_NOK; break;
      }  
    }
 return RET;
}


//STD_Return_Type GPIO_PIN_READ_LOGIC(PIN_CFG *ptr,direction_t *log){
//    
//    STD_Return_Type RET = E_OK ; 
//
//    if((NULL == log) ||(NULL == ptr) || (ptr -> port > GPIO_PORT_MAX-1) || (ptr -> pin > GPIO_PIN_MAX-1) ){
//      RET = E_NOK ;
//    }else{
//        
//        *log = READ_BIT(*(PORT_REG[ptr -> port]),ptr -> pin);  
//    }
//  return RET;
//}

//--------------------------------------------------------------------------

STD_Return_Type GPIO_PIN_TOGGLE_LOGIC(PIN_CFG *ptr){

    STD_Return_Type RET = E_OK ; 

    if((NULL == ptr) || (ptr -> port > GPIO_PORT_MAX-1) || (ptr -> pin > GPIO_PIN_MAX-1) ){
      RET = E_NOK ;
    }else{
         switch(ptr -> port){
           case GPIO_PORTA : TOGG_BIT(LATA_REG,ptr -> pin) ; break;
           case GPIO_PORTB : TOGG_BIT(LATB_REG,ptr -> pin) ; break;
           case GPIO_PORTC : TOGG_BIT(LATC_REG,ptr -> pin) ; break;
           case GPIO_PORTD : TOGG_BIT(LATD_REG,ptr -> pin) ; break;
           case GPIO_PORTE : TOGG_BIT(LATE_REG,ptr -> pin) ; break;
           default : RET = E_NOK;
        }  
     }    
  return RET; 
}

//STD_Return_Type GPIO_PIN_TOGGLE_LOGIC(PIN_CFG *ptr){
//
//    STD_Return_Type RET = E_OK ; 
//
//    if((NULL == ptr) || (ptr -> port > GPIO_PORT_MAX-1) || (ptr -> pin > GPIO_PIN_MAX-1) ){
//      RET = E_NOK ;
//    }else TOGG_BIT(*(LAT_REG[ptr->port]),ptr -> pin);
//             
//  return RET; 
//}

//*****************************************************************************

//<NIBBLES>



//*****************************************************************************

//<PORTS>


STD_Return_Type GPIO_PORT_DIRECTION_INITIALIZE(port_t port,uint8 dir){

    STD_Return_Type RET = E_OK ; 

    if((port > GPIO_PORT_MAX-1)){
      RET = E_NOK ;
    }else{
    
        switch(port){
            case GPIO_PORTA : TRISA_REG = dir ; break;           
            case GPIO_PORTB : TRISB_REG = dir ; break;             
            case GPIO_PORTC : TRISC_REG = dir ; break;                
            case GPIO_PORTD : TRISD_REG = dir ; break;                
            case GPIO_PORTE : TRISE_REG = dir ; break;            
            default : RET = E_NOK;
        }
    }
  return RET;    
}

//STD_Return_Type GPIO_PORT_DIRECTOIN_INITIALIZE(port_t port,uint8 dir){
//
//    STD_Return_Type RET = E_OK ; 
//
//    if((port > GPIO_PORT_MAX-1)){
//      RET = E_NOK ;
//    }else{     
//        *TRIS_REG[port] = dir ;
//    }
//   return RET;  
//}

//--------------------------------------------------------------------------

STD_Return_Type GPIO_PORT_GET_DIRECTOIN(port_t port , uint8 *dir){

    STD_Return_Type RET = E_OK ; 

    if((port > GPIO_PORT_MAX-1)){
      RET = E_NOK ;
    }else{
    
        switch(port){
            case GPIO_PORTA : *dir = TRISA_REG; break;
            case GPIO_PORTB : *dir = TRISB_REG; break;
            case GPIO_PORTC : *dir = TRISC_REG; break;
            case GPIO_PORTD : *dir = TRISD_REG; break;
            case GPIO_PORTE : *dir = TRISE_REG; break;
            default : RET = E_NOK;
        }
    }
 return RET;  
}


//STD_Return_Type GPIO_PORT_GET_DIRECTOIN(port_t port , uint8 *dir){
//
//    STD_Return_Type RET = E_OK ; 
//
//    if((port > GPIO_PORT_MAX-1)){
//      RET = E_NOK ;
//    }else{
//        *dir = *TRIS_REG[port];
//    }
//    return RET;  
//}


//--------------------------------------------------------------------------

STD_Return_Type GPIO_PORT_WRITE_LOGIC(port_t port , uint8 logic){
    
    STD_Return_Type RET = E_OK ; 

    if((port > GPIO_PORT_MAX-1)){
      RET = E_NOK ;
    }else{
    
        switch(port){
            case GPIO_PORTA : LATA_REG = logic ; break;
            case GPIO_PORTB : LATB_REG = logic ; break;
            case GPIO_PORTC : LATC_REG = logic ; break;    
            case GPIO_PORTD : LATD_REG = logic ; break;
            case GPIO_PORTE : LATE_REG = logic ; break;
            default : RET = E_NOK;
        }
    }
  return RET; 
}

//STD_Return_Type GPIO_PORT_WRITE_LOGIC(port_t port , uint8 logic){
//    
//     STD_Return_Type RET = E_OK ; 
//
//    if((port > GPIO_PORT_MAX-1)){
//      RET = E_NOK ;
//    }else{
//    
//       *LAT_REG[port] = logic ;
//    }
//    return RET; 
//}


//--------------------------------------------------------------------------

STD_Return_Type GPIO_PORT_READ_LOGIC(port_t port ,cptr logic){
    
    
    STD_Return_Type RET = E_OK ; 

    if((port > GPIO_PORT_MAX-1)){
      RET = E_NOK ;
    }else{
        
        switch(port){
            case GPIO_PORTA : *logic = PORTA_REG; break;
            case GPIO_PORTB : *logic = PORTB_REG; break;
            case GPIO_PORTC : *logic = PORTC_REG; break;
            case GPIO_PORTD : *logic = PORTD_REG; break;
            case GPIO_PORTE : *logic = PORTE_REG; break;
            default : RET = E_NOK;
        }
    }
   return RET;  
}

   
//STD_Return_Type GPIO_PORT_READ_LOGIC(port_t port , uint8 *logic){
//    
//    
//    STD_Return_Type RET = E_OK ; 
//
//    if((port > GPIO_PORT_MAX-1)){
//      RET = E_NOK ;
//    }else{
//        *logic = *PORT_REG[port];
//    }
//    return RET;  
//}    
    

//--------------------------------------------------------------------------

STD_Return_Type GPIO_PORT_TOGGLE_LOGIC(port_t port){
    
    STD_Return_Type RET = E_OK ; 

    if((port > GPIO_PORT_MAX-1)){
      RET = E_NOK ;
    }else{
        switch (port) {
        case GPIO_PORTA: LATA_REG ^= 0xFF; break;  
        case GPIO_PORTB: LATB_REG ^= 0xFF; break;
        case GPIO_PORTC: LATC_REG ^= 0xFF; break;
        case GPIO_PORTD: LATD_REG ^= 0xFF; break;
        case GPIO_PORTE: LATE_REG ^= 0xFF; break;
       }
    }
 return RET; 
}


//STD_Return_Type GPIO_PORT_TOGGLE_LOGIC(port_t port){
//    
//    STD_Return_Type RET = E_OK ; 
//
//    if((port > GPIO_PORT_MAX-1)){
//      RET = E_NOK ;
//    }else{
//        *LAT_REG[port] = ~(*LAT_REG[port]) ;
//    }
// return RET; 
//}