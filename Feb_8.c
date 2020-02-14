//
//  Feb_8.c
//  TIVA
//
//  Created by Dev Bhatia on 2/8/19.
//  LED toggle with button press.
//

#include <tm4c123gh6pm.h>  // Include header file for TIVA
#include <stdint.h>  // Account for unsigned int

int main(void)
{
    SYSCTL_RCGCGPIO_R = 0x29;  // Enable Clocks for Ports ADF
    int value = 0;
    
    // PORT A SPECS
    GPIO_PORTA_AFSEL_R = 0x00;  // Configure Port A for GPIO use
    GPIO_PORTA_DIR_R = 0x04;    // Set Pin A2 as OUTPUT
    GPIO_PORTA_PUR_R = 0x00;  // Disable port's pull-up R
    GPIO_PORTA_PDR_R = 0x00;  // Disable port's pull-down R
    GPIO_PORTA_ODR_R = 0x00;  // Disable port's open drain
    GPIO_PORTA_DEN_R = 0x04;  // Enable Pin A2 as Digital I/O
    
    // PORT D SPECS
    GPIO_PORTD_AFSEL_R = 0x00;  // Configure Port D for GPIO use
    GPIO_PORTD_DIR_R = 0x00;    // Set Pin D3 as INPUT (default)
    GPIO_PORTD_PUR_R = 0x00;  // Disable port's pull-up R
    GPIO_PORTD_PDR_R = 0x08;  // Enable port's pull-down R
    GPIO_PORTD_ODR_R = 0x00;  // Disable port's open drain
    GPIO_PORTD_DEN_R = 0x08;  // Enable Pin D3 as Digital I/O
    
    // PORT F SPECS
    GPIO_PORTF_AFSEL_R = 0x00;  // Configure Port F for GPIO use
    GPIO_PORTF_DIR_R = 0x02;    // Set Pin F1 as OUTPUT
    GPIO_PORTF_PUR_R = 0x00;  // Disable port's pull-up R
    GPIO_PORTF_PDR_R = 0x00;  // Disable port's pull-down R
    GPIO_PORTF_ODR_R = 0x00;  // Disable port's open drain
    GPIO_PORTF_DEN_R = 0x02;  // Enable Pin F1 as Digital I/O
    
    while(1)
    {
        // Why do we need to shift by 1?
        // GPIO_PORTF_DATA_BITS_R[0x02] = GPIO_PORTD_DATA_BITS_R[0x08]>>1;
        
        value = GPIO_PORTD_DATA_BITS_R[0x08];
        
        if (value != 0)
        {
            GPIO_PORTF_DATA_BITS_R[0x02] = 0xFF;
            GPIO_PORTA_DATA_BITS_R[0x04] = 0x00;
        }
        
        else
        {
            GPIO_PORTF_DATA_BITS_R[0x02] = 0x00;
            GPIO_PORTA_DATA_BITS_R[0x04] = 0xFF;
        }
        
        // Use this
        GPIO_PORTF_DATA_BITS_R[0x02] = GPIO_PORTD_DATA_BITS_R[0x08]>>2;
        GPIO_PORTA_DATA_BITS_R[0x04] = ~GPIO_PORTD_DATA_BITS_R[0x08]>>1;
    }
    
    return 0;
}
