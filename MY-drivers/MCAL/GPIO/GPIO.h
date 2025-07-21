/* 
 * File:   GPIO.h
 * Author: sherif 
 *
 * Created on April 3, 2025, 10:26 AM
 */

#ifndef GPIO_H
#define	GPIO_H

/*_____________________INCLUDE_PART_______________________*/

#include <pic18f4620.h>
#include "../MCAL_STD_types.h"

/*_______________GPIO_REGISTERS_DEFINETIONS_______________*/

#define TRISA_REG   *(volatile unsigned char*)0xF92
#define TRISB_REG   *(volatile unsigned char*)0xF93
#define TRISC_REG   *(volatile unsigned char*)0xF94
#define TRISD_REG   *(volatile unsigned char*)0xF95
#define TRISE_REG   *(volatile unsigned char*)0xF96

#define LATA_REG    *(volatile unsigned char*)0xF89
#define LATB_REG    *(volatile unsigned char*)0xF8A
#define LATC_REG    *(volatile unsigned char*)0xF8B
#define LATD_REG    *(volatile unsigned char*)0xF8C
#define LATE_REG    *(volatile unsigned char*)0xF8D

#define PORTA_REG   *(volatile unsigned char*)0xF80
#define PORTB_REG   *(volatile unsigned char*)0xF81
#define PORTC_REG   *(volatile unsigned char*)0xF82
#define PORTD_REG   *(volatile unsigned char*)0xF83
#define PORTE_REG   *(volatile unsigned char*)0xF84
/*_____________________MACROS_DECLARATION___________________*/

#define GPIO_PORT_MAX    5
#define GPIO_PIN_MAX     8

/*_________________________________________________________*/


typedef enum{
    
   GPIO_PORTA ,
   GPIO_PORTB ,
   GPIO_PORTC ,
   GPIO_PORTD ,
   GPIO_PORTE 
    
}port_t;



typedef enum{

    GPIO_PIN0 ,
    GPIO_PIN1 ,
    GPIO_PIN2 ,
    GPIO_PIN3 ,
    GPIO_PIN4 ,
    GPIO_PIN5 ,
    GPIO_PIN6 ,
    GPIO_PIN7

}pin_t;


typedef enum{
    
  
    GPIO_DIRECTION_OUTPUT,
    GPIO_DIRECTION_INPUT
  
            
}direction_t;


typedef enum{
    GPIO_LOW,
    GPIO_HIGH  
}logic_t;


typedef struct{
    
    uint8 port:3  ;
    uint8 pin:3   ;
    uint8 dir:1   ;
    uint8 logic:1 ;
    
}PIN_CFG; 


/*_________________FUNCTION_PROTOTYPES___________________*/

//<PIN>
STD_Return_Type GPIO_PIN_DIRECTION_INITIALIZE(PIN_CFG *ptr);
STD_Return_Type GPIO_PIN_GET_DIRECTION(PIN_CFG *ptr,direction_t *state);
STD_Return_Type GPIO_PIN_WRITE_LOGIC(PIN_CFG *ptr,logic_t log);
STD_Return_Type GPIO_PIN_READ_LOGIC(PIN_CFG *ptr,logic_t *log);
STD_Return_Type GPIO_PIN_TOGGLE_LOGIC(PIN_CFG *ptr) ;

//<PORT>
STD_Return_Type GPIO_PORT_DIRECTION_INITIALIZE(port_t port,uint8 dir);
STD_Return_Type GPIO_PORT_GET_DIRECTION(PIN_CFG *ptr);
STD_Return_Type GPIO_PORT_WRITE_LOGIC(port_t port , uint8 logic);
STD_Return_Type GPIO_PORT_READ_LOGIC(port_t port , cptr logic);
STD_Return_Type GPIO_PORT_TOGGLE_LOGIC(port_t port);


#endif	/* GPIO_H */

