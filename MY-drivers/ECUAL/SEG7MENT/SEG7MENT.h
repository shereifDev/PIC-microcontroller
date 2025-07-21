/* 
 * File:   SEG7MENT.h
 * Author: sherif
 *
 * Created on May 11, 2025, 5:58 PM
 */

#ifndef SEG7MENT_H
#define	SEG7MENT_H

/*_____________________INCLUDE_PART_______________________*/

#include "GPIO/GPIO.h"

/*_________________________________________________________*/

typedef enum{
    COMMON_ANODE ,
    COMMON_CATHOD   
}seg7ment_type_t;


typedef enum {
    SEG7MENT_PIN1 ,   
    SEG7MENT_PIN2 , 
    SEG7MENT_PIN3 , 
    SEG7MENT_PIN4 , 
}seg7ment_pins_t;


typedef struct{
   PIN_CFG seg7ment_pin[4];    
}SEG7MENT_CFG;

/*_________________FUNCTION_PROTOTYPES___________________*/

STD_Return_Type SEG7MENT_INITIALIZE(SEG7MENT_CFG *ptr);
STD_Return_Type SEG7MENT_DISPLAY_NUMBER(SEG7MENT_CFG *ptr , uint8 number);

#endif	/* SEG7MENT_H */

