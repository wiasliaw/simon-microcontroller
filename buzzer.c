#include <xc.h>
#include "config.h"

void Buzzer_Init(void){
    // Define RC[3-0] as LED output
    TRISC = 0x00;
    // Clear output on RC[3-0]
    LATC = 0x00;
    return;
};
void Buzzer_On(int buzzer_ID){
    int buzzerPos = 1 << (buzzer_ID - 1);
    LATC = (LATC | buzzerPos);
    return;
};

void Buzzer_Off(int buzzer_ID){
    int buzzerPos = 1 << (buzzer_ID - 1);
    LATC = (LATC ^ buzzerPos);
    return;
};

void Buzzer_On_500ms(int buzzer_ID){
    Buzzer_On(buzzer_ID);
    __delay_ms(500);
    Buzzer_Off(buzzer_ID);
    return;
};
