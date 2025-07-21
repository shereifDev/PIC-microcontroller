/* 
 * File:   APP.c
 * Author: sherif
 *
 * Created on April 7, 2025, 12:33 AM
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

LED_CFG LED4 = {
 .port = GPIO_PORTC ,
 .pin = GPIO_PIN3 , 
 .connection = ACTIVE_HIGH ,
 .state = TURN_OFF
};

LED_CFG LED5 = {
 .port = GPIO_PORTC ,
 .pin = GPIO_PIN4 , 
 .connection = ACTIVE_HIGH ,
 .state = TURN_OFF
};

LED_CFG LED6 = {
 .port = GPIO_PORTC ,
 .pin = GPIO_PIN5 , 
 .connection = ACTIVE_HIGH ,
 .state = TURN_OFF
};

LED_CFG LED7 = {
 .port = GPIO_PORTC ,
 .pin = GPIO_PIN6 , 
 .connection = ACTIVE_HIGH ,
 .state = TURN_OFF
};

uint8* arr[7] = {&LED1,&LED2,&LED3,&LED4,&LED5,&LED6,&LED7};
#define LED_NUM   7

int main(){
   
   // led_initialization
   for(int i=0 ; i<LED_NUM ; i++){
        LED_INITIALIZE(arr[i]);
   }
   
   while(1){
        
       for(int i=0 ; i<LED_NUM ; i++){
         LED_TURN_ON(arr[i]);
         __delay_ms(1000);
         LED_TURN_OFF(arr[i]); 
       }   
   }

}