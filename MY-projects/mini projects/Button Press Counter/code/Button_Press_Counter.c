BUTTON_CFG btn = {
  .port = GPIO_PORTB,
  .pin = GPIO_PIN0,
  .connection = BUTTON_ACTIVE_HIGH,
  .state = RELEASED
};

LED_CFG led1 = {
 .port = GPIO_PORTC ,
.pin = GPIO_PIN0 ,
.connection = LED_ACTIVE_HIGH ,
.state = TURN_OFF  
};

LED_CFG led2 = {
 .port = GPIO_PORTC ,
.pin = GPIO_PIN3 ,
.connection = LED_ACTIVE_HIGH ,
.state = TURN_OFF  
};

LED_CFG led3 = {
 .port = GPIO_PORTC ,
.pin = GPIO_PIN6 ,
.connection = LED_ACTIVE_HIGH ,
.state = TURN_OFF  
};

button_state_t state = RELEASED ;
uint8 counter = 0;

int main(){
   
   // leds initialization
   LED_INITIALIZE(&led1);
   LED_INITIALIZE(&led2);
   LED_INITIALIZE(&led3);
   
   // button initialize 
   BUTTON_INITIALIZE(&btn);
   
   while(1){
       
       // check pressed 
       BUTTON_READ_STATE(&btn , &state);
       if(state == PRESSED){
           __delay_ms(50);
           BUTTON_READ_STATE(&btn , &state);
           if(state == PRESSED){
              counter = (counter >= 15) ? 0 : counter+1 ;
           }
           do{
                BUTTON_READ_STATE(&btn, &state);
               } while(state == PRESSED);
       }
       
       switch(counter){
           
           case 0 ... 5:
            LED_TURN_ON(&led1);
            LED_TURN_OFF(&led2);
            LED_TURN_OFF(&led3);
            break;
           
           case 6 ... 10:
            LED_TURN_ON(&led2);
            LED_TURN_OFF(&led1);
            LED_TURN_OFF(&led3);
            break;
            
           case 11 ... 15:
            LED_TURN_ON(&led3);
            LED_TURN_OFF(&led2);
            LED_TURN_OFF(&led1);
            break;     
       }
   }
   
return (EXIT_SUCCESS) ;
}