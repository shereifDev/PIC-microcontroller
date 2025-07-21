BUTTON_CFG switch1 = {
  .port = GPIO_PORTC,
  .pin = GPIO_PIN0,
  .connection = BUTTON_ACTIVE_HIGH,
  .state = RELEASED
};

BUTTON_CFG switch2 = {
  .port = GPIO_PORTC,
  .pin = GPIO_PIN3,
  .connection = BUTTON_ACTIVE_HIGH,
  .state = RELEASED
};

BUTTON_CFG switch3 = {
  .port = GPIO_PORTC,
  .pin = GPIO_PIN6,
  .connection = BUTTON_ACTIVE_HIGH,
  .state = RELEASED
};


LED_CFG led = {
 .port = GPIO_PORTA ,
.pin = GPIO_PIN4 ,
.connection = LED_ACTIVE_HIGH ,
.state = TURN_OFF  
};


button_state_t s1 = RELEASED ;
button_state_t s2 = RELEASED ;
button_state_t s3 = RELEASED ;




int main(){
   
   // buttons initialization
   BUTTON_INITIALIZE(&switch1);
   BUTTON_INITIALIZE(&switch2);
   BUTTON_INITIALIZE(&switch3);
   // led initialization
   LED_INITIALIZE(&led);
   
   
   while(1){
      
       BUTTON_READ_STATE(&switch1,&s1);
       BUTTON_READ_STATE(&switch2,&s2);
       BUTTON_READ_STATE(&switch3,&s3);
       
          
    /*** the led turn on only if switch2 and switch3 are closed and switch1 is open ****/
          
       if(s1 == RELEASED && s2 == PRESSED && s3 == PRESSED ){
           
           LED_TURN_ON(&led);
       }else{
           LED_TURN_OFF(&led);
        }
   }
 return (EXIT_SUCCESS) ;
}