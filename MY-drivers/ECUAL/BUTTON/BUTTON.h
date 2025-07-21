/* 
 * File:   BUTTON.h
 * Author: sherif
 *
 * Created on April 25, 2025, 2:47 PM
 */

#ifndef BUTTON_H
#define	BUTTON_H

/*_____________________INCLUDE_PART_______________________*/

#include "../../MCAL/GPIO/GPIO.h"

/*_________________________________________________________*/

typedef struct {
    uint8 port:3 ;
    uint8 pin:3 ;
    uint8 connection:1;
    uint8 state:1;
 
}BUTTON_CFG;


typedef enum {
    BUTTON_ACTIVE_LOW ,
    BUTTON_ACTIVE_HIGH
  
}button_connection_t;



typedef enum {
    RELEASED ,
    PRESSED
}button_state_t;

/*_________________FUNCTION_PROTOTYPES___________________*/


STD_Return_Type BUTTON_INITIALIZE(BUTTON_CFG *ptr);
STD_Return_Type BUTTON_READ_STATE(BUTTON_CFG *ptr , button_state_t *state);




#endif	/* BUTTON_H */

