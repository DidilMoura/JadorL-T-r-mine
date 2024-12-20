#define FCY 2000000  // Fréquence de l'oscillateur du processeur
#include "lcd/lcd.h"
#include "lcd/print_lcd.h"

#include <stdio.h>
#include <stdlib.h>

#include "mcc_generated_files/system.h"
#include "mcc_generated_files/adc1.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include <xc.h>

#include "mcc_generated_files/system.h"
/*
                         Main application
 */
int flag = 0 ;
int buffer;
float volume;
char value[16];
int main(void){
    
    SYSTEM_Initialize();
    LCD_Initialize();
    ADC1_Start();
    while (1){
    
        buffer = ADC1_GetConversion(0x5);
        volume = ((buffer*5.0)/1024);
        
    
    }   
    

    return 1;
}




//void __attribute__ ( ( __interrupt__ , auto_psv ) ) _ADC1Interrupt ( void ){
//    flag = 1;
//    IFS0bits.AD1IF = false;
//}
//
