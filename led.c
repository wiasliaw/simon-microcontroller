#include <xc.h>
#include "config.h"

void LED_Init() {
    // Define RD[3-0] as LED output
    TRISD = 0x00;
    // Clear output on RD[3-0]
    LATD = 0x00;
    return;
};

void LED_On(int led_ID){
    int ledPos = 1 << led_ID;
    LATD = (LATD | ledPos);
    return;
};
void LED_Off(int led_ID){
    int ledPos = 1 << led_ID;
    LATD = (LATD ^ ledPos);
    return;
};

void LED_On_500ms(int led_ID){
    LED_On(led_ID);
    __delay_ms(500);
    LED_Off(led_ID);
    return;
};