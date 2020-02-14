//
//  Feb_11.c
//  TIVA
//
//  Created by Dev Bhatia on 2/11/19.
//

#include <stdio.h>
#include <stdint.h>
#include <tm4c123gh6pm.h>

int main(void)
{
    // Enable Port C
    SYSCTL_RCGCGPIO_R = 0x04;
    
    //  PWM Example from DS-1239
    SYSCTL_RCGC0_R = 0x00100000;     // 1 - Enable 250k samples/sec ~ 25kHz Freq.
    SYSCTL_RCGC2_R = 0x00000004;     // 2 - Enable the correct port for GPIO CG. I chose port C
    GPIO_PORTC_AFSEL_R = 0x10;       // 3 - Port C pins set for GPIO function
    GPIO_PORTC_PCTL_R = 0x00040000;  // 4 - Assign PWM signals to pin 4
    SYSCTL_RCC_R ^= (0x0F<<17);       // 5 - RCC_R uses USEPWMDIV & PWMDIV divides by 2
    
    // 6 - Immediate updates to parameters
    PWM0_0_CTL_R = 0x00;
    PWM0_0_GENA_R = 0x0000008C;
    PWM0_0_GENB_R = 0x0000080C;
    
    PWM0_0_LOAD_R = 0x0000018F;  // 7 - Set the period
    PWM0_0_CMPA_R = 0x0000012B;  // 8 - Set 25% Duty Cycle for A
    PWM0_0_CMPB_R = 0x00000063;  // 9 - Set 75% Duty Cycle for B
    PWM0_0_CTL_R = 0x00000001;   // 10 - Start the timers
    PWM0_ENABLE_R = 0x00000011;    // 11 - Enable PWM output
    
    return 0;
}
