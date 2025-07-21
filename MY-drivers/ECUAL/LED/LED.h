/* 
 * File:   LED.h
 * Author: sherif
 *
 * Created on April 21, 2025, 9:24 PM
 */





#ifndef LED_H
#define	LED_H


/*_____________________INCLUDE_PART_______________________*/

#include "./../../MCAL/GPIO/GPIO.h"

/*_________________________________________________________*/

typedef enum {
    TURN_OFF ,
    TURN_ON
}led_state_t;


typedef enum {
   LED_ACTIVE_LOW ,
   LED_ACTIVE_HIGH
}led_connection_t;

typedef struct {
    uint8 port:3;
    uint8 pin:3 ;
    uint8 connection:1;
    uint8 state:1; 
}LED_CFG;

/*_________________FUNCTION_PROTOTYPES___________________*/

 STD_Return_Type  LED_INITIALIZE (LED_CFG *ptr);
 STD_Return_Type  LED_TURN_ON (LED_CFG *ptr);
 STD_Return_Type  LED_TURN_OFF (LED_CFG *ptr);
 STD_Return_Type  LED_TOGGLE (LED_CFG *ptr);
 
 
 
 
#endif	/* LED_H */

