/* 
 * File:   BUZZER.h
 * Author: sherif
 *
 * Created on April 23, 2025, 12:43 PM
 */





#ifndef BUZZER_H
#define	BUZZER_H

/*_____________________INCLUDE_PART_______________________*/

#include ".././../MCAL/GPIO/GPIO.h"

/*_________________________________________________________*/

typedef enum {
    SOUND_OFF,
    SOUND_ON
}buzzer_state_t;


typedef struct {
    uint8 port:3;
    uint8 pin:3 ;
    uint8 state:1; 
}BUZZER_CFG;


/*_________________FUNCTION_PROTOTYPES___________________*/

 STD_Return_Type  BUZZER_INITIALIZE (BUZZER_CFG *ptr);
 STD_Return_Type  BUZZER_TURN_ON (BUZZER_CFG *ptr);
 STD_Return_Type  BUZZER_TURN_OFF (BUZZER_CFG *ptr);
 STD_Return_Type  BUZZER_TOGGLE (BUZZER_CFG *ptr);


#endif	/* BUZZER_H */

