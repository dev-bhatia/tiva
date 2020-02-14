//
//  Feb_8_2.c
//  TIVA
//
//  Created by Dev Bhatia on 2/8/19.
//  PWM/UART
//

#include <stdio.h>
#include <stdint.h>
#include <tm4c123gh6pm.h>

int main(void)
{
    // Timers could be useful
    SYSCTL_RCGCGPIO_R = 0x02; // Only using port A GPIO
    
    // PORT B SPECS
    GPIO_PORTB_AFSEL_R = 0x40;  // Configure Port A for GPIO use
    GPIO_PORTB_DIR_R = 0x40;    // Set Pin A2 as OUTPUT
    GPIO_PORTB_PUR_R = 0x00;  // Disable port's pull-up R
    GPIO_PORTB_PDR_R = 0x00;  // Disable port's pull-down R
    GPIO_PORTB_ODR_R = 0x00;  // Disable port's open drain
    GPIO_PORTB_DEN_R = 0x40;  // Disable Pin A2 as Digital I/O
    // GPIO_PORTB_AMSEL_R = 0x40;  // Enable Analog function on A2
    
    // PWM TIMER
    TIMER0_CFG_R = 0x04; // Step 2. DS-725
    TIMER0_TAMR_R = 0x0A; // Step 3. AMS 0x1, CMR 0x0, MR 0x2
    // OUTPUT is not inverted by default
    // Not using prescaler
    TIMER0_TAILR_R = 0xFFFF;
    TIMER0_TAMATCHR_R = 0x8000;
    TIMER0_CTL_R = 0x01;  // Actually start the PWM
    
    return 0;
}
