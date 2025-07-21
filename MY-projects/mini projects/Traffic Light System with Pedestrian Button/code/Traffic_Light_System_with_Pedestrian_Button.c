/* 
 * File:   APP.c
 * Author: sherif
 *
 * Created on April 7, 2025, 12:33 AM
 */

#include "APP.h"


// red
LED_CFG LED1 = {
 .port = GPIO_PORTC ,
 .pin = GPIO_PIN0 , 
 .connection = ACTIVE_HIGH ,
 .state = TURN_OFF
};
//yellow 
LED_CFG LED2 = {
 .port = GPIO_PORTC ,
 .pin = GPIO_PIN1 , 
 .connection = ACTIVE_HIGH ,
 .state = TURN_OFF
};
//green
LED_CFG LED3 = {
 .port = GPIO_PORTC ,
 .pin = GPIO_PIN2 , 
 .connection = ACTIVE_HIGH ,
 .state = TURN_OFF
};

//cross_led
LED_CFG LED4 = {
 .port = GPIO_PORTB ,
 .pin = GPIO_PIN2 , 
 .connection = ACTIVE_HIGH ,
 .state = TURN_OFF
};

uint8 cnt = 0;

int main(){
   
   //led_initialization 
   LED_INITIALIZE(&LED1);
   LED_INITIALIZE(&LED2);
   LED_INITIALIZE(&LED3);
   LED_INITIALIZE(&LED4);
   
   while(1){
             
       if(cnt == 1){
           LED_TURN_ON(&LED1);
           LED_TURN_ON(&LED4);
           LED_TURN_OFF(&LED2);
           LED_TURN_OFF(&LED3);
       }  
       if(cnt == 2){
           LED_TURN_ON(&LED2);
           LED_TURN_OFF(&LED1);
           LED_TURN_OFF(&LED3);
           LED_TURN_OFF(&LED4);
       }
       if(cnt == 3){
           LED_TURN_ON(&LED3);
           LED_TURN_OFF(&LED1);
           LED_TURN_OFF(&LED2);
           LED_TURN_OFF(&LED4);
       }
       if(cnt == 3) cnt = 0 ;
       cnt ++ ;
       __delay_ms(1000);     
   }   
}