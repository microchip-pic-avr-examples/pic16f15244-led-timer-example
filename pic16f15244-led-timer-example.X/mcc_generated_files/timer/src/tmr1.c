/**
  TMR1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr1.c

  @Summary
    This is the generated driver implementation file for the TMR1 driver

  @Description
    This source file provides APIs for driver for TMR1.
    Generation Information :
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.20
        MPLAB             :  MPLAB X v5.40
*/
/*
Copyright (c) [2012-2020] Microchip Technology Inc.  

    All rights reserved.

    You are permitted to use the accompanying software and its derivatives 
    with Microchip products. See the Microchip license agreement accompanying 
    this software, if any, for additional info regarding your rights and 
    obligations.
    
    MICROCHIP SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT 
    WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
    LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
    AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP OR ITS
    LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT 
    LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE 
    THEORY FOR ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT 
    LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, 
    OR OTHER SIMILAR COSTS. 
    
    To the fullest extend allowed by law, Microchip and its licensors 
    liability will not exceed the amount of fees, if any, that you paid 
    directly to Microchip to use this software. 
    
    THIRD PARTY SOFTWARE:  Notwithstanding anything to the contrary, any 
    third party software accompanying this software is subject to the terms 
    and conditions of the third party's license agreement.  To the extent 
    required by third party licenses covering such third party software, 
    the terms of such license will apply in lieu of the terms provided in 
    this notice or applicable license.  To the extent the terms of such 
    third party licenses prohibit any of the restrictions described here, 
    such restrictions will not apply to such third party software.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "../tmr1.h"
#include "../../system/pins.h"

/**
  Section: Global Variables Definitions
*/
volatile uint16_t timer1ReloadVal;
void (*Timer1_InterruptHandler)(void);

const struct TMR_INTERFACE Timer1 = {
    .Initialize = Timer1_Initialize,
    .Start = Timer1_Start,
    .Stop = Timer1_Stop,
    .PeriodCountSet = Timer1_Write,
    .TimeoutCallbackRegister = Timer1_OverflowCallbackRegister,
    .Tasks = NULL
};
static void (*Timer1_OverflowCallback)(void);
static void Timer1_DefaultOverflowCallback(void);

void Timer1_Initialize(void)

{
    //TGGO done; TGSPM disabled; TGTM disabled; TGPOL low; TMRGE disabled; 
    T1GCON = 0x0;
    //TGSS T1G_pin; 
    T1GATE = 0x0;
    //TMRCS MFINTOSC_500kHz; 
    T1CLK = 0x6;
    //TMRH 11; 
    TMR1H = 0xB;
    //TMRL 220; 
    TMR1L = 0xDC;
    
    // Clearing IF flag before enabling the interrupt.
    PIR1bits.TMR1IF = 0;

    // Load the TMR value to reload variable
    timer1ReloadVal=(uint16_t)((TMR1H << 8) | TMR1L);
    
    // Enabling interrupt.
    PIE1bits.TMR1IE = 1;
  
    //Set default callback for TMR1 overflow interrupt
    Timer1_OverflowCallbackRegister(Timer1_DefaultOverflowCallback);
    
    
    // Clearing IF flag before enabling the interrupt.
    PIR2bits.TMR1GIF = 0;

    // Enabling interrupt.
    PIE2bits.TMR1GIE = 1;
    T1CON = 0x30;
}

void Timer1_Start(void)
{
    // Start the Timer by writing to TMRxON bit
    T1CONbits.TMR1ON = 1;
}

void Timer1_Stop(void)
{
    // Stop the Timer by writing to TMRxON bit
    T1CONbits.TMR1ON = 0;
}

uint16_t Timer1_Read(void)
{
    uint16_t readVal;
    uint8_t readValHigh;
    uint8_t readValLow;
    
	
    readValLow = TMR1L;
    readValHigh = TMR1H;
    
    readVal = ((uint16_t)readValHigh << 8) | readValLow;

    return readVal;
}

void Timer1_Write(size_t timerVal)
{
    if (T1CONbits.NOT_SYNC == 1)
    {
        // Stop the Timer by writing to TMRxON bit
        T1CONbits.TMR1ON = 0;

        // Write to the Timer1 register
        TMR1H = (uint8_t)(timerVal >> 8);
        TMR1L = (uint8_t)timerVal;

        // Start the Timer after writing to the register
        T1CONbits.TMR1ON = 1;
    }
    else
    {
        // Write to the Timer1 register
        TMR1H = (uint8_t)(timerVal >> 8);
        TMR1L = (uint8_t)timerVal;
    }
}

void Timer1_Reload(void)
{
    Timer1_Write(timer1ReloadVal);
}

void Timer1_StartSinglePulseAcquisition(void)
{
    T1GCONbits.T1GGO = 1;
}

uint8_t Timer1_CheckGateValueStatus(void)
{
    return (T1GCONbits.T1GVAL);
}

void Timer1_OverflowISR(void)
{

    // Clear the TMR1 interrupt flag
    PIR1bits.TMR1IF = 0;
    Timer1_Write(timer1ReloadVal);

    if(Timer1_OverflowCallback)
    {
        Timer1_OverflowCallback();
    }
}

void Timer1_OverflowCallbackRegister(void (* CallbackHandler)(void))
{
    Timer1_OverflowCallback = CallbackHandler;
}

static void Timer1_DefaultOverflowCallback(void)
{
    if(LED0_TRIS == 1)
    {
        LED0_SetDigitalOutput();
    }
    else
    {
        LED0_SetDigitalInput();
    }
}

bool Timer1_HasOverflowOccured(void)
{
    return(PIR1bits.TMR1IF);
}

void Timer1_GATE_ISR(void)
{
    // clear the TMR1 interrupt flag
    PIR2bits.TMR1GIF = 0;
}


/**
  End of File
*/