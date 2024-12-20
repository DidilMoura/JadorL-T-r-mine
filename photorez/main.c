/*
 * File:   main.c
 * Author: hr913666
 *
 * Created on 20 décembre 2024, 09:10
 */

#define FCY 2000000U
#include <xc.h>
#include <libpic30.h>
#include "mcc_generated_files/system.h"
uint8_t flagAdc =0;

void  ADC1_CallBack(void)
{
    flagAdc ^= 1;
}

void main(void) {
    SYSTEM_Initialize();
    uint16_t AdcValue =0;
    
    while(1){
        
        if(flagAdc == 1)
        {
            ADC1_ConversionResultBufferGet(&AdcValue);
      
        }
    
        
        
    }
}
