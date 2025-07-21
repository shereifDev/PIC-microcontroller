void delay_ms(uint16_t ms);


LED_CFG led = {
 .port = GPIO_PORTB ,
.pin = GPIO_PIN0 ,
.connection = LED_ACTIVE_HIGH ,
.state = TURN_OFF  
};

BUTTON_CFG btn = {
  .port = GPIO_PORTC,
  .pin = GPIO_PIN1,
  .connection = BUTTON_ACTIVE_HIGH,
  .state = RELEASED
};


button_state_t state = RELEASED ;

uint8 counter = 0 ;
const uint16 delays[] = {500, 450, 400, 350, 300, 250, 200, 150, 100, 50};
     
int main(){

   // led initializatoin 
   LED_INITIALIZE(&led);
   // button initialization
   BUTTON_INITIALIZE(&btn);

   while(1){
       
       BUTTON_READ_STATE(&btn , &state);
       if(state == PRESSED){
           __delay_ms(80);
           BUTTON_READ_STATE(&btn , &state);
           if(state == PRESSED){
              counter = (counter == 9)? 0 : counter+1 ;
           }
           do{
              BUTTON_READ_STATE(&btn , &state);
           }while(state == PRESSED);
       }
       
       LED_TOGGLE(&led);
       delay_ms(delays[counter]);
       
       
   }
   
   
   
  return (EXIT_SUCCESS) ;
}

void delay_ms(uint16_t ms){
   while(ms--){
       __delay_ms(1); 
   }
}