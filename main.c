#include <xc.h>
#include <pic18f4520.h>
#include "config.h"
#include "button.h"
#include "buzzer.h"
#include "utils.h"
#include "led.h"

int questionArr[QUESTION_LIMIT];
int inputArr[QUESTION_LIMIT];

// Question starts from 0
int questionCtr = 0;
int inputCtr = 0;

int interrupt_occur = 0;

void __interrupt(high_priority) Hi_ISR(void) {
    GAME_RESET();
    interrupt_occur = 1;
    INTCONbits.INT0IF = 0;
    return;
}

int main(void) {
    // Set up external interfaces
    Config_Init();
    Button_Init();
    Buzzer_Init();
    LED_Init();

    // Set up arrays
    GAME_RESET();

    while (1) {
        // show question
        __delay_ms(1000);
        question_show(questionArr, questionCtr);
        interrupt_occur = 0;
        while(1) {
            int havent_input = 1;
            if (interrupt_occur == 1)
                break;
            while(havent_input) {
                // listen input
                if (PORTAbits.RA0 == 1) {
                    inputArr[inputCtr] = 0;
                    LED_BUZZER_SHOW(0, 500);
                    havent_input = 0;
                } else if (PORTAbits.RA1 == 1) {
                    inputArr[inputCtr] = 1;
                    LED_BUZZER_SHOW(1, 500);
                    havent_input = 0;
                } else if (PORTAbits.RA2 == 1) {
                    inputArr[inputCtr] = 2;
                    LED_BUZZER_SHOW(2, 500);
                    havent_input = 0;
                } else if (PORTAbits.RA3 == 1) {
                    inputArr[inputCtr] = 3;
                    LED_BUZZER_SHOW(3, 500);
                    havent_input = 0;
                }
            }

            // delay 1 sec
            __delay_ms(100);
            // check
            int valid = validityCheck(questionArr, inputArr, inputCtr);
            if (valid) {
                if(inputCtr == questionCtr) {
                    questionCtr++;
                    inputCtr = 0;
                    break;
                }
                else {
                    inputCtr++;
                }
                
                if (questionCtr == QUESTION_LIMIT) {
                    for (int i = 0; i < 2; i++) {
                        for (int j = 0; j < 4; j++) {
                            LED_BUZZER_SHOW(j, 250);
                        }
                    }
                    __delay_ms(1000);
                    GAME_RESET();
                    break;
                }
            } else {
                for (int i = 0; i < 2; i++) {
                    LED_BUZZER_SHOW(3, 250);
                    LED_BUZZER_SHOW(0, 250);
                }
                GAME_RESET();
                __delay_ms(1000);
                break;
            }
        }
    }
    return (EXIT_SUCCESS);
}