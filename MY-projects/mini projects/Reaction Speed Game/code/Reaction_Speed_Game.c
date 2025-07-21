
LED_CFG led1 = {
 .port = GPIO_PORTC ,
.pin = GPIO_PIN0 ,
.connection = LED_ACTIVE_HIGH ,
.state = TURN_OFF  
};

LED_CFG led2 = {
 .port = GPIO_PORTC ,
.pin = GPIO_PIN1 ,
.connection = LED_ACTIVE_HIGH ,
.state = TURN_OFF  
};

LED_CFG led3 = {
 .port = GPIO_PORTC ,
.pin = GPIO_PIN2 ,
.connection = LED_ACTIVE_HIGH ,
.state = TURN_OFF  
};

LED_CFG led4 = {
 .port = GPIO_PORTC ,
.pin = GPIO_PIN3 ,
.connection = LED_ACTIVE_HIGH ,
.state = TURN_OFF  
};

LED_CFG led5 = {
 .port = GPIO_PORTC ,
.pin = GPIO_PIN4 ,
.connection = LED_ACTIVE_HIGH ,
.state = TURN_OFF  
};

LED_CFG led6 = {
 .port = GPIO_PORTC ,
.pin = GPIO_PIN5 ,
.connection = LED_ACTIVE_HIGH ,
.state = TURN_OFF  
};

LED_CFG led7 = {
 .port = GPIO_PORTC ,
.pin = GPIO_PIN6 ,
.connection = LED_ACTIVE_HIGH ,
.state = TURN_OFF  
};

LED_CFG led8 = {
 .port = GPIO_PORTC ,
.pin = GPIO_PIN7 ,
.connection = LED_ACTIVE_HIGH ,
.state = TURN_OFF  
};

BUZZER_CFG buzz = {
 .port = GPIO_PORTB ,
.pin = GPIO_PIN0 ,
 .state =SOUND_OFF
};

BUTTON_CFG btn = {
  .port = GPIO_PORTD,
  .pin = GPIO_PIN4,
  .connection = BUTTON_ACTIVE_HIGH,
  .state = RELEASED
};





uint8 counter = 0 ;
long long  time = 50000 ;    
button_state_t state = RELEASED ;

int main(){

   // leds initialization
   GPIO_PORT_DIRECTION_INITIALIZE(GPIO_PORTC,0x00);
   // button initialize 
   BUTTON_INITIALIZE(&btn);
   // buzzer initialize 
   BUZZER_INITIALIZE(&buzz);
   
    // time start
       BUZZER_TURN_ON(&buzz);
       __delay_ms(1000);
       BUZZER_TURN_OFF(&buzz);
   
   while(1){
           
       // check pressed 
       BUTTON_READ_STATE(&btn , &state);
       if(state == PRESSED){
           __delay_ms(80);
           BUTTON_READ_STATE(&btn , &state);
           if(state == PRESSED){
               counter ++;
           }
           do{
             BUTTON_READ_STATE(&btn , &state);
           }while(state == PRESSED);
       }
       
       time -- ;
       
       // check time 
       if(time == 0){
          
           // time out 
           BUZZER_TURN_ON(&buzz);
           __delay_ms(1000);
           BUZZER_TURN_OFF(&buzz);
           
           if(counter > 0 && counter <= 20 ){
               
             LED_TURN_ON(&led1);
            
           }
           if(counter > 20 && counter <= 100 ){
               
             LED_TURN_ON(&led1);
             __delay_ms(500);
             LED_TURN_ON(&led2);
             __delay_ms(500);
             LED_TURN_ON(&led3);
           }
           if(counter > 100 && counter <= 200 ){
               
             LED_TURN_ON(&led1);
             __delay_ms(500);
             LED_TURN_ON(&led2);
             __delay_ms(500);
             LED_TURN_ON(&led3);
             __delay_ms(500);
             LED_TURN_ON(&led4);
             __delay_ms(500);
             LED_TURN_ON(&led5);
           }
            if(counter >200 ){
               
             LED_TURN_ON(&led1);
             __delay_ms(500);
             LED_TURN_ON(&led2);
             __delay_ms(500);
             LED_TURN_ON(&led3);
             __delay_ms(500);
             LED_TURN_ON(&led4);
             __delay_ms(500);
             LED_TURN_ON(&led5);
             __delay_ms(500);
             LED_TURN_ON(&led6);
             __delay_ms(500);
             LED_TURN_ON(&led7);
             __delay_ms(500);
             LED_TURN_ON(&led8);
           }

       }
   }
   
 return (EXIT_SUCCESS) ; 
}