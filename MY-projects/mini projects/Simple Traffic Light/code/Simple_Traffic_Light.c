
// functions prototype
void stop (void);
void ready (void);
void go (void);


LED_CFG RED_LED = {
 .port = GPIO_PORTD,
.pin = GPIO_PIN0,
.state =  TURN_OFF,
.connection = LED_ACTIVE_HIGH  
   
   
};

LED_CFG YELLOW_LED = {
 .port = GPIO_PORTD,
.pin = GPIO_PIN1,
.state =  TURN_OFF,
.connection = LED_ACTIVE_HIGH  
   
   
};

LED_CFG GREEN_LED = {
 .port = GPIO_PORTD,
.pin = GPIO_PIN2,
.state =  TURN_OFF,
.connection = LED_ACTIVE_HIGH  
   
   
};


int main(){
   
   // leds initialization
   LED_INITIALIZE(&RED_LED);
   LED_INITIALIZE(&YELLOW_LED);
   LED_INITIALIZE(&GREEN_LED);
   
   
   while(1){
       
       stop();
       ready();
       go();
       
   }

  return (EXIT_SUCCESS) ;
}

// functions implementations
void stop (void){
   LED_TURN_ON(&RED_LED);
   __delay_ms(5000);
   LED_TURN_OFF(&RED_LED);   
}

void ready (void){
   LED_TURN_ON(&YELLOW_LED);
   __delay_ms(2000);
   LED_TURN_OFF(&YELLOW_LED);   
}

void go (void){
   LED_TURN_ON(&GREEN_LED);
   __delay_ms(5000);
   LED_TURN_OFF(&GREEN_LED);   
}


