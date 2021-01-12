#include "xc.h"
#include "pic18f4520.h"
#include "config.h"
#include "button.h"
//#include "buzzer.h"
#include "utils.h"
#include "led.h"

int ques[10];
int ptr_q = 0;

void __interrupt(high_priority) Mi_ISR(void) {
    int ans = -1;
    if (PORTAbits.RA0 == 1) {
        LED_On(1);
        ans = ques_check(ques, ptr_q, 0);
        if (ans == 1 && ptr_q!=11) {
            ques_next(ques);
        }
        else if (ans == 1 && ptr_q==11) {
            // success event
        }
        else {
            // failure event
        }
        LED_Off(1);
    } else if (PORTAbits.RA1 == 1) {
        LED_On(2);
        ans = ques_check(ques, ptr_q, 1);
        LED_Off(2);
    } else if (PORTAbits.RA2 == 1) {
        LED_On(3);
        ans = ques_check(ques, ptr_q, 2);
        LED_Off(3);
    } else if (PORTAbits.RA3 == 1) {
        LED_On(4);
        ans = ques_check(ques, ptr_q, 3);
        LED_Off(4);
    } else if (PORTAbits.RA4 == 1) {
        // clear
    }
    INTCONbits.INT0IF = 0;
    return;
}

int main(void) {
    Config_Init();
    Button_Init();
    LED_Init();
    ques_init(ques);
    while(1) {
    }
    return (EXIT_SUCCESS);
}
