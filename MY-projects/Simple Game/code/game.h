/* 
 * File:   game.h
 * Author: sherif
 */

#ifndef game_H
#define	game_H

//_____________include part__________________________
#include "APP.h"
//_____________functions prototype___________________

STD_Return_Type APPLICATION_SYSTEM_INITIALIZE(void);  
STD_Return_Type Logic_Gate_Puzzle(void);
STD_Return_Type power_bridge(void);
STD_Return_Type Servo_Lock_Challenge(void);
STD_Return_Type Seg7ment_Math_Gate(void);
STD_Return_Type Relay_Puzzle(void);
STD_Return_Type Final_Gate(void);

//_____________________user defined____________________

typedef enum {
    state1 = 1,
    state2,
    state3,
    state4,
    state5,
    state6
     
}state_t;


typedef struct {
  const char* question; 
  int answer;           
}puzzle;


#endif	/* game_H */

