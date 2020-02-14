//
//  Feb_5.cpp
//  TIVA
//
//  Created by Dev Bhatia on 2/5/19.
//

//
//  Feb_5.cpp
//  TIVA
//
//  Created by Dev Bhatia on 2/5/19.
//

#include <tm4c123gh6pm.h>  // Include header file for TIVA
#include <stdint.h>  // Account for unsigned int
#include <stdlib.h>  // notice this! you need it!

void logic(int pressed);

int main(void)
{
    int pressed = 0;
    
    SYSCTL_RCGCGPIO_R = 0x29;  // Enable Clocks for Ports ADF
    
    // PORT A SPECS
    GPIO_PORTA_AFSEL_R = 0x00;  // Configure Port A for GPIO use
    GPIO_PORTA_DIR_R = 0x04;    // Set Pin A2 as OUTPUT
    GPIO_PORTA_PUR_R = 0x00;  // Disable port's pull-up R
    GPIO_PORTA_PDR_R = 0x00;  // Disable port's pull-down R
    GPIO_PORTA_ODR_R = 0x00;  // Disable port's open drain
    GPIO_PORTA_DEN_R = 0x04;  // Enable Pin A2 as Digital I/O
    
    // PORT D SPECS
    GPIO_PORTD_AFSEL_R = 0x00;  // Configure Port D for GPIO use
    GPIO_PORTD_DIR_R = 0x08;    // Set Pin D3 as INPUT (default)
    GPIO_PORTD_PUR_R = 0x00;  // Disable port's pull-up R
    GPIO_PORTD_PDR_R = 0x08;  // Enable port's pull-down R
    GPIO_PORTD_ODR_R = 0x00;  // Disable port's open drain
    GPIO_PORTD_DEN_R = 0x08;  // Enable Pin D3 as Digital I/O
    
    // PORT F SPECS
    GPIO_PORTF_AFSEL_R = 0x00;  // Configure Port D for GPIO use
    GPIO_PORTF_DIR_R = 0x01;    // Set Pin F1 as OUTPUT
    GPIO_PORTF_PUR_R = 0x00;  // Disable port's pull-up R
    GPIO_PORTF_PDR_R = 0x00;  // Disable port's pull-down R
    GPIO_PORTF_ODR_R = 0x00;  // Disable port's open drain
    GPIO_PORTF_DEN_R = 0x01;  // Enable Pin F1 as Digital I/O
    
    GPIO_PORTF_DATA_BITS_R[0x01] = 1U;
    GPIO_PORTA_DATA_BITS_R[0x02] = 1U<<2;
    
    while(1)
    {
        //pressed = GPIO_PORTD_DATA_BITS_R[0x08];
        //logic(pressed);
    }
    
    return 0;
}

void logic(int pressed)
{
    if (pressed)
    {
        // Turn on Blue LED
        GPIO_PORTF_DATA_BITS_R[0x01] = 1U;
    }
    else
    {
        // Turn on Red LED
        GPIO_PORTA_DATA_BITS_R[0x02] = 1U<<2;
    }
}
