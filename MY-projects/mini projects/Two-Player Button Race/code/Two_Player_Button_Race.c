BUTTON_CFG btn1 = {
  .port = GPIO_PORTD,
  .pin = GPIO_PIN0,
  .connection = BUTTON_ACTIVE_HIGH,
  .state = RELEASED
};

LED_CFG led1 = {
 .port = GPIO_PORTD ,
.pin = GPIO_PIN6 ,
.connection = LED_ACTIVE_HIGH ,
.state = TURN_OFF  
};


BUTTON_CFG btn2 = {
  .port = GPIO_PORTB,
  .pin = GPIO_PIN0,
  .connection = BUTTON_ACTIVE_HIGH,
  .state = RELEASED
};

LED_CFG led2 = {
 .port = GPIO_PORTB ,
.pin = GPIO_PIN6 ,
.connection = LED_ACTIVE_HIGH ,
.state = TURN_OFF  
};

button_state_t s1 = RELEASED ;
button_state_t s2 = RELEASED ;
uint8 flag = 0 ;

int main(){
   
   // leds initilization
   LED_INITIALIZE(&led1);
   LED_INITIALIZE(&led2);
   // buttons initialization
   BUTTON_INITIALIZE(&btn1);
   BUTTON_INITIALIZE(&btn2);
   
   while(1){
       
        BUTTON_READ_STATE(&btn1 , &s1);
        if(s1 == PRESSED && flag == 0){
            LED_TURN_ON(&led1);
            flag = 1 ;
        }
        
        BUTTON_READ_STATE(&btn2 , &s2);
        if(s2 == PRESSED && flag == 0){
            LED_TURN_ON(&led2);
            flag = 1 ;
        }
   }
   
   
   
  return (EXIT_SUCCESS) ;
}