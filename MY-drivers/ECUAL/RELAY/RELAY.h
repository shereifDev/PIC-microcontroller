/* 
 * File:   RELAY.h
 * Author: sherif
 *
 * Created on May 12, 2025, 12:48 PM
 */

#ifndef RELAY_H
#define	RELAY_H

/*___________________INCLUDE_PART_______________________*/

#include "GPIO/GPIO.h"

/*_____________________________________________________*/

typedef struct {
  PIN_CFG relay_pin ;  
}RELAY_CFG;

/*_________________FUNCTION_PROTOTYPES___________________*/

STD_Return_Type RELAY_INITIALIZE(RELAY_CFG *ptr);
STD_Return_Type RELAY_SWITCH_ON(RELAY_CFG *ptr);
STD_Return_Type RELAY_SWITCH_OFF(RELAY_CFG *ptr);

#endif	/* RELAY_H */

