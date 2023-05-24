<!-- Please do not change this html logo with link -->
<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="300"/></a>

# Toggle an LED using Timer1 with PIC16F15244

The 'pic16f15244-led-timer-example' code example uses the PIC16F15244 Curiosity Nano Development board to demonstrate how to toggle LED0 every second using Timer1 to configure that one second period.

##### PIC16F15244 Curiosity Nano Development Board:
![Curiosity Nano Development Board](images/NanoHighlights.png)

## Related Documentation
- [PIC16F15244 Product Page](https://www.microchip.com/wwwproducts/en/PIC16F15244)

## Software Used
- MPLAB® X IDE 6.10 or newer [(microchip.com/mplab/mplab-x-ide)](http://www.microchip.com/mplab/mplab-x-ide)
- MPLAB® XC8 2.41 or a newer compiler [(microchip.com/mplab/compilers)](http://www.microchip.com/mplab/compilers)
- MPLAB® Code Configurator (MCC) 5.3.7 or newer [(microchip.com/mplab/mplab-code-configurator)](https://www.microchip.com/mplab/mplab-code-configurator)
- Microchip PIC16F1xxxx Series Device Support (1.18.352) or newer [(packs.download.microchip.com/)](https://packs.download.microchip.com/)

## Hardware Used
- PIC16F15244 Curiosity Nano [(EV09Z19A)](https://www.microchip.com/Developmenttools/ProductDetails/EV09Z19A)
- Micro-USB to USB 2.0 cable

## Setup
1. Connect the PIC16f15244 Curiosity Nano board to a PC using the Micro-USB to USB 2.0 cable.
2. Download and install MPLAB®X IDE version 6.10, or newer.
3. Download and install the XC8 C-Compiler version 2.41, or newer.
4. Open the 'pic16f15244-led-timer-example.X' project, as shown in Figure 1.

  ###### Figure 1: Open Project Window
  ![Open Project Window](images/OpenProject.png)

5. Press **Open Project** to open the **Project Properties** window. Select the Curiosity tool from the tools drop-down menu, as shown in Figure 2.

  ###### Figure 2: Select the Nano in Project Properties Window
  ![Select Tool](images/SelectTool.png)

6. Press **Make and Program Device** to program the PIC, as shown in Figure 3. Verify if the device was successfully programmed, as shown in Figure 4.

  ###### Figure 3: 'Make and Program Device' Button
  ![Program Device Button](images/MakeAndProgramButton.png)

  ###### Figure 4: Program Complete
  ![Program Complete](images/ProgramSuccess.png)


## Operation
After the Curiosity Nano is programmed, LED0 states will switch from 'ON' to 'OFF' every second.

Timer1 is configured such that it will roll-over every second, causing an interrupt event to occur. Timer1 can be quickly configured using MCC. Figure 5 shows the configuration used to generate an interrupt once every second. During the Timer1 Interrupt Service Routine (ISR), pin RA2 is toggled, which allows LED0 to change states.

  ###### Figure 5: TMR1 Configuration in MCC
  ![Timer1 Configuration](images/TMR1MCC.png)


###### Example 1: TMR1 Interrupt Service Routine Code Snippet

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


## Summary
The 'pic16f15244-led-timer-example' code example uses the PIC16F15244 Curiosity Nano Development board to demonstrate how to toggle LED0 every second using Timer1 to configure that one second period.
