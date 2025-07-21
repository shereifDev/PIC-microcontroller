/* 
 * File:   DC_MOTOR.h
 * Author: sherif
 *
 * Created on May 1, 2025, 11:19 PM
 */

#ifndef DC_MOTOR_H
#define	DC_MOTOR_H

/*___________________INCLUDE_PART_______________________*/

#include "../MCAL/GPIO/GPIO.h"

/*_____________________________________________________*/

typedef enum{
    
    MOTOR_STOP_MOVING ,
    MOTOR_GO_FORWARD,
    MOTOR_GO_BACKWARD
}motor_state_t;

typedef enum{
    MOTOR_PIN1,
    MOTOR_PIN2         
}motor_pins;

typedef struct {
    PIN_CFG motor_pin[2] ;
}MOTOR_CFG;

/*_________________FUNCTION_PROTOTYPES___________________*/

STD_Return_Type  MOTOR_INITIALIZE(MOTOR_CFG *ptr);
STD_Return_Type  MOTOR_TURN_RIGHT(MOTOR_CFG *ptr);
STD_Return_Type  MOTOR_TURN_LEFT(MOTOR_CFG *ptr);
STD_Return_Type  MOTOR_TURN_OFF(MOTOR_CFG *ptr);



#endif	/* DC_MOTOR_H */

