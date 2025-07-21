/* 
 * File:   APP.c
 * Author: sherif
 *
 * Created on April 7, 2025, 11:26 AM
 */

#include "APP.h"




LED_CFG LED1 = {
 .port = GPIO_PORTC ,
 .pin = GPIO_PIN0 , 
 .connection = ACTIVE_HIGH ,
 .state = TURN_OFF
};

LED_CFG LED2 = {
 .port = GPIO_PORTC ,
 .pin = GPIO_PIN1 , 
 .connection = ACTIVE_HIGH ,
 .state = TURN_OFF
};

LED_CFG LED3 = {
 .port = GPIO_PORTC ,
 .pin = GPIO_PIN2 , 
 .connection = ACTIVE_HIGH ,
 .state = TURN_OFF
};


int main(){
   
   // led_initialization
   LED_INITIALIZE(&LED1);
   LED_INITIALIZE(&LED2);
   LED_INITIALIZE(&LED3);
 
   while(1){
        
       // turnOn
       LED_TURN_ON(&LED1);
       __delay_ms(500);
       LED_TURN_ON(&LED2);
       __delay_ms(500);
        LED_TURN_ON(&LED3);
       __delay_ms(500);
       
       // turnOff
        LED_TURN_OFF(&LED3);
       __delay_ms(500);
       LED_TURN_OFF(&LED2);
       __delay_ms(500);
        LED_TURN_OFF(&LED1);
       __delay_ms(500);
     
   }

}