/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.5
        Device            :  PIC24FJ1024GB610
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#define FCY 2000000UL

#include "mcc_generated_files/system.h"
#include "mcc_generated_files/i2c1.h"

#include "xc.h"
#include "libpic30.h"

/*
                         Main application
 */

void WriteData(uint8_t cmd, uint8_t value, I2C1_MESSAGE_STATUS* status)
{
    uint8_t data[] = {cmd, value};
    I2C1_MasterWrite(data, 2, 0x39, status);
}

uint16_t ReadData(uint8_t cmd, I2C1_MESSAGE_STATUS* status)
{
    uint8_t data[2];
    I2C1_MasterWrite(&cmd, 1, 0x39, status);
    __delay_ms(12);
    I2C1_MasterRead(data, 2, 0x39, status);
    return (uint16_t) (data[0]) | (uint16_t) (data[1]) << 8;
}

int main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    TRISA = 0x00;
    
    I2C1_MESSAGE_STATUS status;
    
    WriteData(0, 0, &status); // Désactive tout
    WriteData(1, 0xff, &status); // ATIME
    WriteData(2, 0xff, &status); // Wait time
    WriteData(3, 0xff, &status); // PTIME
    WriteData(0x0E, 8, &status);  // PPULSE
    WriteData(0x0F, 0x20, &status);
    
    WriteData(0, 15, &status);
    
    __delay_ms(12);
    
    /*while(status != I2C1_MESSAGE_COMPLETE) 
    { 
        __delay_us(10);
    }*/
    
   // uint8_t data2[2];
    
    while (1)
    {
        //uint8_t command[] = { 0b10100000, 0x18 };
        uint8_t cmd = 0xA0;
        I2C1_MasterWrite(&cmd, 1, 0x39, &status);
        LATA = ReadData(0x14, &status);
        
        
        
        __delay_ms(12);
        
        /*uint16_t prox = ReadData();
        
        uint8_t command = 0x18; 
        I2C1_MasterWrite(&command, 1, 0x39, &status);
        __delay_ms(12); 
        I2C1_MasterRead(data2, 1, 0x39, &status);
        __delay_ms(12);
        
        LATA = data2[0];*/
        
        /*I2C1_MasterWrite(&command, 1, 0x39, &status);
        while(status != I2C1_MESSAGE_COMPLETE);
        I2C1_MasterRead(&dataL, 1, 0x39, &status);
        while(status != I2C1_MESSAGE_COMPLETE);
        command = 0x19;
        I2C1_MasterWrite(&command, 1, 0x39, &status);
        while(status != I2C1_MESSAGE_COMPLETE);
        I2C1_MasterRead(&dataH, 1, 0x39, &status);
        while(status != I2C1_MESSAGE_COMPLETE);*/
    }

    return 1;
}
/**
 End of File
*/

