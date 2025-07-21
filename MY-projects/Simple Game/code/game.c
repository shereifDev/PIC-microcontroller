/*
 * File:   game.c
 * Author: sherif
 */

#include "../APP.h"
#include "../game.h"



const puzzle puzzle_list[] = {
  {"1 AND 0 = ?", 0},
  {"1 OR 0 = ?", 1},
  {"0 AND 0 = ?", 0},
  {"1 AND 1 = ?", 1},
  {"0 OR 1 = ?", 1},
  {"1 XOR 1 = ?", 0},
  {"1 XOR 0 = ?", 1}
};
uint8 q1_index = 0 ;

const puzzle math_list[] = {
  {"1 + 3 = ?", 4},
  {"6 - 4 = ?", 2},
  {"5 + 2 = ?", 7},
  {"1 * 8 = ?", 8},
  {"0 * 1 = ?", 0},
  {"1 - 1 = ?", 0},
  {"4 / 2 = ?", 2}
};
uint8 q2_index = 0 ;


KEYPAD_CFG keypad = {
     // KEYPAD ROWS 
    .KEYPAD_ROWS[R1].port = GPIO_PORTC,
    .KEYPAD_ROWS[R1].pin = GPIO_PIN0,
    .KEYPAD_ROWS[R1].dir = GPIO_DIRECTION_OUTPUT,
    .KEYPAD_ROWS[R1].logic = GPIO_LOW,
    
    .KEYPAD_ROWS[R2].port = GPIO_PORTC,
    .KEYPAD_ROWS[R2].pin = GPIO_PIN1,
    .KEYPAD_ROWS[R2].dir = GPIO_DIRECTION_OUTPUT,
    .KEYPAD_ROWS[R2].logic = GPIO_LOW,
    
    .KEYPAD_ROWS[R3].port = GPIO_PORTC,
    .KEYPAD_ROWS[R3].pin = GPIO_PIN2,
    .KEYPAD_ROWS[R3].dir = GPIO_DIRECTION_OUTPUT,
    .KEYPAD_ROWS[R3].logic = GPIO_LOW,
    
    .KEYPAD_ROWS[R4].port = GPIO_PORTC,
    .KEYPAD_ROWS[R4].pin = GPIO_PIN3,
    .KEYPAD_ROWS[R4].dir = GPIO_DIRECTION_OUTPUT,
    .KEYPAD_ROWS[R4].logic = GPIO_LOW,
    
    //KEYPAD COLUMNS
    .KEYPAD_COLUMNS[C1].port = GPIO_PORTC,
    .KEYPAD_COLUMNS[C1].pin  = GPIO_PIN4,
    .KEYPAD_COLUMNS[C1].dir = GPIO_DIRECTION_INPUT,
    .KEYPAD_COLUMNS[C1].logic = GPIO_LOW,
    
    .KEYPAD_COLUMNS[C2].port = GPIO_PORTC,
    .KEYPAD_COLUMNS[C2].pin  = GPIO_PIN5,
    .KEYPAD_COLUMNS[C2].dir = GPIO_DIRECTION_INPUT,
    .KEYPAD_COLUMNS[C2].logic = GPIO_LOW,
    
    .KEYPAD_COLUMNS[C3].port = GPIO_PORTC,
    .KEYPAD_COLUMNS[C3].pin  = GPIO_PIN6,
    .KEYPAD_COLUMNS[C3].dir = GPIO_DIRECTION_INPUT,
    .KEYPAD_COLUMNS[C3].logic = GPIO_LOW,
    
    .KEYPAD_COLUMNS[C4].port = GPIO_PORTC,
    .KEYPAD_COLUMNS[C4].pin  = GPIO_PIN7,
    .KEYPAD_COLUMNS[C4].dir = GPIO_DIRECTION_INPUT,
    .KEYPAD_COLUMNS[C4].logic = GPIO_LOW
};

LCD_CFG lcd = {
    .En_pin.port = GPIO_PORTE,
    .En_pin.pin = GPIO_PIN0,
    .En_pin.dir = GPIO_DIRECTION_OUTPUT,
    .En_pin.logic = GPIO_LOW,
    
    .Rs_pin.port = GPIO_PORTE,
    .Rs_pin.pin = GPIO_PIN1,
    .Rs_pin.dir = GPIO_DIRECTION_OUTPUT,
    .Rs_pin.logic = GPIO_LOW,
    
    .data_pins[0].port = GPIO_PORTD,
    .data_pins[0].pin = GPIO_PIN0,
    .data_pins[0].dir = GPIO_DIRECTION_OUTPUT,
    .data_pins[0].logic = GPIO_LOW,
    
    .data_pins[1].port = GPIO_PORTD,
    .data_pins[1].pin = GPIO_PIN1,
    .data_pins[1].dir = GPIO_DIRECTION_OUTPUT,
    .data_pins[1].logic = GPIO_LOW,
    
    .data_pins[2].port = GPIO_PORTD,
    .data_pins[2].pin = GPIO_PIN2,
    .data_pins[2].dir = GPIO_DIRECTION_OUTPUT,
    .data_pins[2].logic = GPIO_LOW,
    
    .data_pins[3].port = GPIO_PORTD,
    .data_pins[3].pin = GPIO_PIN3,
    .data_pins[3].dir = GPIO_DIRECTION_OUTPUT,
    .data_pins[3].logic = GPIO_LOW,
    
};

BUZZER_CFG BZ = {
    .port = GPIO_PORTE ,
    .pin = GPIO_PIN2,
    .state = SOUND_OFF
};

BUTTON_CFG S1 = {
    .port = GPIO_PORTB,
    .pin = GPIO_PIN0,
    .connection = BUTTON_ACTIVE_HIGH,
    .state =  RELEASED   
};
BUTTON_CFG S2 = {
    .port = GPIO_PORTB,
    .pin = GPIO_PIN1,
    .connection = BUTTON_ACTIVE_HIGH,
    .state =  RELEASED   
};
BUTTON_CFG S3 = {
    .port = GPIO_PORTB,
    .pin = GPIO_PIN2,
    .connection = BUTTON_ACTIVE_HIGH,
    .state =  RELEASED   
};

LED_CFG RED_LED = {
    .port = GPIO_PORTB,
    .pin = GPIO_PIN3,
    .connection = LED_ACTIVE_HIGH,
    .state =  TURN_OFF
};

LED_CFG GRN_LED = {
    .port = GPIO_PORTB,
    .pin = GPIO_PIN4,
    .connection = LED_ACTIVE_HIGH,
    .state =  TURN_OFF
};

LED_CFG BLUE_LED = {
    .port = GPIO_PORTB,
    .pin = GPIO_PIN5,
    .connection = LED_ACTIVE_HIGH,
    .state =  TURN_OFF
};

SEG7MENT_CFG SEG = {
    .seg7ment_pin[0].port = GPIO_PORTA,
    .seg7ment_pin[0].pin  = GPIO_PIN0,
    .seg7ment_pin[0].dir = GPIO_DIRECTION_OUTPUT,
    .seg7ment_pin[0].logic = GPIO_LOW,
    
    .seg7ment_pin[1].port = GPIO_PORTA,
    .seg7ment_pin[1].pin  = GPIO_PIN1,
    .seg7ment_pin[1].dir = GPIO_DIRECTION_OUTPUT,
    .seg7ment_pin[1].logic = GPIO_LOW,
    
    .seg7ment_pin[2].port = GPIO_PORTA,
    .seg7ment_pin[2].pin  = GPIO_PIN2,
    .seg7ment_pin[2].dir = GPIO_DIRECTION_OUTPUT,
    .seg7ment_pin[2].logic = GPIO_LOW,
    
    .seg7ment_pin[3].port = GPIO_PORTA,
    .seg7ment_pin[3].pin  = GPIO_PIN3,
    .seg7ment_pin[3].dir = GPIO_DIRECTION_OUTPUT,
    .seg7ment_pin[3].logic = GPIO_LOW,
  
};

RELAY_CFG RY = {
    .relay_pin.port = GPIO_PORTA,
    .relay_pin.pin  = GPIO_PIN4,
    .relay_pin.dir = GPIO_DIRECTION_OUTPUT,
    .relay_pin.logic = GPIO_LOW
};

MOTOR_CFG lock = {
    .motor_pin[0].port = GPIO_PORTA,
    .motor_pin[0].pin = GPIO_PIN5,
    .motor_pin[0].dir = GPIO_DIRECTION_OUTPUT,
    .motor_pin[0].logic = GPIO_LOW,
    
    .motor_pin[1].port = GPIO_PORTB,
    .motor_pin[1].pin = GPIO_PIN6,
    .motor_pin[1].dir = GPIO_DIRECTION_OUTPUT,
    .motor_pin[1].logic = GPIO_LOW 
};


uint8 current_state = state1 ;

int main(){
    
    APPLICATION_SYSTEM_INITIALIZE();
    
    while(1){
       
        switch(current_state){
            case state1 :
            Logic_Gate_Puzzle();    
            break;
            
            case state2 :
            power_bridge();    
            break;
            
            case state3 :
            Servo_Lock_Challenge();    
            break;
            
            case state4 :
            Seg7ment_Math_Gate();    
            break;
            
            case state5 :
            Relay_Puzzle();    
            break;
            
            case state6 :
            Final_Gate();    
            break;
            
        }
    }
  
 return (EXIT_SUCCESS);
    
}


STD_Return_Type APPLICATION_SYSTEM_INITIALIZE(void){    
    STD_Return_Type RET = E_OK;
    RET &= LCD_INITIALIZE(&lcd);
    RET &= KEYPAD_INITIALIZE(&keypad);
    RET &= BUZZER_INITIALIZE(&BZ);
    RET &= LED_INITIALIZE(&RED_LED);
    RET &= LED_INITIALIZE(&GRN_LED);
    RET &= LED_INITIALIZE(&BLUE_LED);
    RET &= BUTTON_INITIALIZE(&S1);
    RET &= BUTTON_INITIALIZE(&S2);
    RET &= BUTTON_INITIALIZE(&S3);
    RET &= SEG7MENT_INITIALIZE(&SEG);
    RET &= RELAY_INITIALIZE(&RY);
    RET &= MOTOR_INITIALIZE(&lock);
    
    return RET;
}

uint8 get_key_from_keypad(void) {
    uint8 key = NOT_PRESSED;
    do {
        KEYPAD_GET_KEY(&keypad, &key);
    } while (key == NOT_PRESSED);
    return key;
}

STD_Return_Type Logic_Gate_Puzzle(void){
    
    STD_Return_Type RET = E_OK;
    uint8 key_value;
    RET = LCD_CLEAR_SCREEN(&lcd);
    RET &= LCD_SEND_STRING(&lcd,(puzzle_list[q1_index].question));
    key_value = get_key_from_keypad();
    if((key_value-'0') == (puzzle_list[q1_index].answer)){
        RET &= LCD_CLEAR_SCREEN(&lcd);
        RET &= LCD_MOVE_CUR(&lcd,1,5);
        RET &= LCD_SEND_STRING(&lcd,"Correct");
        __delay_ms(2000);
        current_state ++;
    }else{
        RET &= BUZZER_TURN_ON(&BZ);
        q1_index = (q1_index<6)?q1_index+1 : 0;
        __delay_ms(2000);
        RET &= BUZZER_TURN_OFF(&BZ);
    }
  return RET ;  
}


STD_Return_Type power_bridge(void){
    
    STD_Return_Type RET = E_OK;
    button_state_t S1_state = RELEASED;
    button_state_t S2_state = RELEASED;
    button_state_t S3_state = RELEASED;
    
    RET = LCD_CLEAR_SCREEN(&lcd);
    RET &= LCD_SEND_STRING(&lcd,"Light Only GREEN!");
    RET &= BUTTON_READ_STATE(&S1,&S1_state);
    RET &= BUTTON_READ_STATE(&S2,&S2_state);
    RET &= BUTTON_READ_STATE(&S3,&S3_state);
    if(S1_state == PRESSED){
        RET &= LED_TURN_ON(&GRN_LED);
        __delay_ms(2000);
        RET &= LED_TURN_OFF(&GRN_LED);
        current_state ++;
    }
    if(S2_state == PRESSED){
        RET &= LED_TURN_ON(&GRN_LED);
        RET &= LED_TURN_ON(&RED_LED);
        RET &= LED_TURN_ON(&BLUE_LED);
        RET &= BUZZER_TURN_ON(&BZ);
        __delay_ms(2000);
        RET &= LED_TURN_OFF(&GRN_LED);
        RET &= LED_TURN_OFF(&RED_LED);
        RET &= LED_TURN_OFF(&BLUE_LED);
        RET &= BUZZER_TURN_OFF(&BZ);
    }
    if(S3_state == PRESSED){
        RET &= LED_TURN_ON(&GRN_LED);
        RET &= LED_TURN_ON(&RED_LED);
        RET &= LED_TURN_ON(&BLUE_LED);
        RET &= BUZZER_TURN_ON(&BZ);
        __delay_ms(2000);
        RET &= LED_TURN_OFF(&GRN_LED);
        RET &= LED_TURN_OFF(&RED_LED);
        RET &= LED_TURN_OFF(&BLUE_LED);
        RET &= BUZZER_TURN_OFF(&BZ);
    }
   return RET ;  
}


STD_Return_Type Servo_Lock_Challenge(void){
    
    STD_Return_Type RET = E_OK;
    uint8 key_value;
    uint8 correct_angle = 90;
    uint8 num_p1 ;
    uint8 num_p2 ;
    RET = LCD_CLEAR_SCREEN(&lcd);
    RET &= LCD_SEND_STRING(&lcd,"Angle = 180 - 90");
    key_value = get_key_from_keypad();
    num_p1 = key_value;
    RET &= LCD_MOVE_CUR(&lcd,2,7);
    RET &= LCD_SEND_CHAR(&lcd,num_p1);
    key_value = get_key_from_keypad();
    num_p2 = key_value;
    RET &= LCD_SEND_CHAR(&lcd,num_p2);
    if(((num_p1-'0')*10)+(num_p2-'0') == 90){
        RET &= MOTOR_TURN_LEFT(&lock);
    }else MOTOR_TURN_RIGHT(&lock);
    __delay_ms(1000);
    RET &= MOTOR_TURN_OFF(&lock);
    current_state ++;
    
  return RET ;  
}


STD_Return_Type Seg7ment_Math_Gate(void){
    
    STD_Return_Type RET = E_OK;
    uint8 key_value;
    RET = LCD_CLEAR_SCREEN(&lcd);
    RET &= LCD_SEND_STRING(&lcd,(math_list[q2_index].question));
    key_value = get_key_from_keypad();
    RET &= SEG7MENT_DISPLAY_NUMBER(&SEG,(key_value-'0'));
    if((key_value-'0') == (math_list[q2_index].answer)){
        RET &= LCD_CLEAR_SCREEN(&lcd);
        RET &= LCD_SEND_STRING(&lcd,"Access Code Accepted");
        __delay_ms(1000);
        RET &= LCD_CLEAR_SCREEN(&lcd);
        RET &= LCD_SEND_STRING(&lcd,"coolant code");
        LCD_MOVE_CUR(&lcd,2,5);
        RET &= LCD_SEND_STRING(&lcd,"1233");
        __delay_ms(2000);
        current_state ++;
    }else{
        RET &= SEG7MENT_DISPLAY_NUMBER(&SEG,3);
        q2_index = (q2_index<6)?q2_index+1 : 0;
        __delay_ms(2000);
    }
        
  return RET;
}

STD_Return_Type Relay_Puzzle(void){
    
    STD_Return_Type RET = E_OK;
    uint16 code = 1233;
    uint8 num_p1 ;
    uint8 num_p2 ;
    uint8 num_p3 ;
    uint8 num_p4 ;
    RET = LCD_CLEAR_SCREEN(&lcd);
    RET &= LCD_SEND_STRING(&lcd,"Enter Cool Code");
    RET &= LCD_MOVE_CUR(&lcd,2,7);
    RET &= LCD_SEND_STRING(&lcd,"----");
    RET &= LCD_MOVE_CUR(&lcd,2,7);
    num_p1 = get_key_from_keypad();
    RET &= LCD_SEND_CHAR(&lcd,num_p1);
    num_p2 = get_key_from_keypad();
    RET &= LCD_SEND_CHAR(&lcd,num_p2);
    num_p3 = get_key_from_keypad();
    RET &= LCD_SEND_CHAR(&lcd,num_p3);
    num_p4 = get_key_from_keypad();
    RET &= LCD_SEND_CHAR(&lcd,num_p4);
    if(((num_p1-'0')*1000)+((num_p2-'0')*100)+((num_p3-'0')*10)+((num_p4-'0')) == code){
        RET &= RELAY_SWITCH_ON(&RY);
        __delay_ms(2000);
        RET &= RELAY_SWITCH_OFF(&RY); 
        current_state ++;
    }else{
        RET &= LCD_CLEAR_SCREEN(&lcd);
        RET &= LCD_SEND_STRING(&lcd,"Overheat! Retry");
        __delay_ms(2000);
    }      
  return RET;
}

STD_Return_Type Final_Gate(void){
    
     STD_Return_Type RET = E_OK;
     uint8 key_value;
     uint8 code = 3+3+3;
     RET = LCD_CLEAR_SCREEN(&lcd);
     RET &= LCD_SEND_STRING(&lcd,"LAST GATE...");
     RET &= LCD_MOVE_CUR(&lcd,2,1);
     RET &= LCD_SEND_STRING(&lcd,"Enter CODE=A+S+L");
     key_value = get_key_from_keypad();
    if(key_value == '9'){
        RET &= LCD_CLEAR_SCREEN(&lcd);
        RET &= LCD_MOVE_CUR(&lcd,1,3);
        RET &= LCD_SEND_STRING(&lcd,"YOU ESCAPED"); 
        RET &= LCD_MOVE_CUR(&lcd,2,3);
        RET &= LCD_SEND_STRING(&lcd,"THE CHAMBER"); 
        __delay_ms(2000);
         while(1);
    }else{
        RET &= LCD_CLEAR_SCREEN(&lcd);
        RET &= LCD_SEND_STRING(&lcd, "System Resetting...");
        __delay_ms(2000);
    }
} 
