/* 
 * File:   MCAL_STD_types.h
 * Author: sherif
 *
 * Created on April 7, 2025, 9:42 AM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/*___________________INCLUDE_PART___________________*/

#include "STD_LIBRARIES.h"     
#include "COMPILER.h" 
#include "DEVICE_CONFIG.h"


/*_____________________STDINT_TYPES_________________*/

typedef  unsigned char    uint8      ;
typedef  signed char      int8       ;

typedef  unsigned short   uint16     ;
typedef  signed short     int16      ;

typedef  unsigned int     uint32     ;
typedef  signed int       int32      ;

typedef  float            float32    ;
typedef  double           float64    ;
typedef  long double      float128   ;

typedef  int*             intptr     ;
typedef  char*             cptr      ;
 
/*_______________________MACROS_DECLARATION___________________*/

#define    SET_BIT(reg , bit)	   reg|=(1<<bit)
#define    CLR_BIT(reg , bit)	   reg&=(~(1<<bit)) 
#define    READ_BIT(reg , bit)     (reg&(1<<bit))>>bit    //return 0 or 1 
#define    TOGG_BIT(reg , bit)	   reg^=(1<<bit)

#define   HIGH      0x01
#define   LOW       0x00

#define   ACTIVE    0x01
#define   IDLE      0x00

#define   ON        0x01
#define   OFF       0x00

#define   E_OK      0x01
#define   E_NOK     0x00 

#define OUTPUT      0x01
#define INPUT       0x00


#define  STD_Return_Type  uint8 


#endif	/* MCAL_STD_TYPES_H */

