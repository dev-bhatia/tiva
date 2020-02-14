//
//  Feb_4.cpp
//  TIVA
//
//  Created by Dev Bhatia on 2/4/19.
//

#include <tm4c123gh6pm.h>  // Include header file for TIVA
#include <stdint.h>  // Account for unsigned int

int main(void){
    SYSCTL_RCGCGPIO_R = 0x08; // Enable Port D, DS-340. This GPIO is for all ports.
    
    // BELOW - must be done for each port being used
    GPIO_PORTD_DIR_R = 0x04; // Enable Pin 2 as a output, DS-663
    GPIO_PORTD_AFSEL_R = 0x00; // Set AFSEL bits to 0. Must do this at beginning every time. DS-672
    // Drive Strength is 2mA by default
    // Pull-UP/DOWN/OP-DRAIN, DS-657
    GPIO_PORTD_PUR_R = 0x00;  // Disable port's pull-up
    GPIO_PORTD_PDR_R = 0x00;  // Disable port's pull-down
    GPIO_PORTD_ODR_R = 0x00;  // Disable port's open drain
    
    // Set Digital/Analog I/O
    GPIO_PORTD_DEN_R = 0x04;  // Set Port D, Pin 2 to a digital I/O
    // GPIO AMSEL for Analog is 0 by default
    // Interrupt GPIOs are disabled by default
    signed int i = 0;
    
    while(1){
        for (i = 0; i < 1000000; i++)
        {
            
        }
        GPIO_PORTD_DATA_BITS_R[4]=1U<<2;  // At Pin 2 (4 = 100bi), set the value of (1U<<2 -> which is 1 shifted to the left twice -> 100)
        //GPIO_PORTD_DATA_BITS_R[0xff]=0x0f;  // Set all the pins to 1.
        //GPIO_PORTD_DATA_R=0x0f; // Set all the pins at port D to 1.
        
        for (i = 0; i < 1000000; i++)
        {
            
        }
        GPIO_PORTD_DATA_BITS_R[1U<<2]=0; // At Pin 2 (1U<<2), write the value of 0.
    }
    return 0;
}
