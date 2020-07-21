/**
  TMR1 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr1.h

  @Summary
    This is the generated header file for the TMR1 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for TMR1.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.0
        Device            :  PIC16F15244
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20
        MPLAB 	          :  MPLAB X 5.40
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef TMR1_H
#define TMR1_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  @Summary
    Initializes the TMR1

  @Description
    This routine initializes the TMR1.
    This routine must be called before any other TMR1 routine is called.
    This routine should only be called once during system initialization.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    

  @Example
    <code>
    main()
    {
        // Initialize TMR1 module
        TMR1_Initialize();

        // Do something else...
    }
    </code>
*/
void TMR1_Initialize(void);



/**
  @Summary
    Writes the TMR1 register.

  @Description
    This function writes the TMR1 register.
    This function must be called after the initialization of TMR1.

  @Preconditions
    Initialize  the TMR1 before calling this function.

  @Param
    timerVal - Value to write into TMR1 register.

  @Returns
    None

  @Example
    <code>
    #define PERIOD 0x80
    #define ZERO   0x00

    while(1)
    {
        // Read the TMR1 register
        if(ZERO == TMR1_ReadTimer())
        {
            // Do something else...

            // Write the TMR1 register
            TMR1_WriteTimer(PERIOD);
        }

        // Do something else...
    }
    </code>
*/
void TMR1_WriteTimer(uint16_t timerVal);

/**
  @Summary
    Timer Interrupt Service Routine

  @Description
    Timer Interrupt Service Routine is called by the Interrupt Manager.

  @Preconditions
    Initialize  the TMR1 module with interrupt before calling this ISR.

  @Param
    None

  @Returns
    None
*/
void TMR1_ISR(void);

/**
  @Summary
    Set Timer Interrupt Handler

  @Description
    This sets the function to be called during the ISR

  @Preconditions
    Initialize  the TMR1 module with interrupt before calling this.

  @Param
    Address of function to be set

  @Returns
    None
*/
 void TMR1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Timer Interrupt Handler

  @Description
    This is a function pointer to the function that will be called during the ISR

  @Preconditions
    Initialize  the TMR1 module with interrupt before calling this isr.

  @Param
    None

  @Returns
    None
*/
extern void (*TMR1_InterruptHandler)(void);

/**
  @Summary
    Default Timer Interrupt Handler

  @Description
    This is the default Interrupt Handler function

  @Preconditions
    Initialize  the TMR1 module with interrupt before calling this isr.

  @Param
    None

  @Returns
    None
*/
void TMR1_DefaultInterruptHandler(void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // TMR1_H
/**
 End of File
*/
