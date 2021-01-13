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

void __interrupt(high_priority) Hi_ISR(void) {
    if (PORTAbits.RA0 == 1) {
        inputArr[inputCtr] = 0;
        LED_BUZZER_SHOW(0, 500);
    } else if (PORTAbits.RA1 == 1) {
        inputArr[inputCtr] = 1;
        LED_BUZZER_SHOW(1, 500);
    } else if (PORTAbits.RA2 == 1) {
        inputArr[inputCtr] = 2;
        LED_BUZZER_SHOW(2, 500);
    } else if (PORTAbits.RA3 == 1) {
        inputArr[inputCtr] = 3;
        LED_BUZZER_SHOW(3, 500);
    } else if (PORTAbits.RA4 == 1) {
        // Game Reset.
        GAME_RESET();

        // RESET MESSAGE
        LED_BUZZER_SHOW(0, 250);
        LED_BUZZER_SHOW(2, 250);
        LED_BUZZER_SHOW(1, 250);
        LED_BUZZER_SHOW(3, 250);

        // delay 1 second before continuing the program
        __delay_ms(1000);

        // Show the question
        question_show(questionArr, questionCtr);

        // Can quit the interrupt now.
        INTCONbits.INT0IF = 0;
        return;
    }

    // delay 1 second before continuing the program
    __delay_ms(1000);

    int valid = validityCheck(questionArr, inputArr, inputCtr);
    if (valid) {
        // Input is valid, increase the counter
        if(inputCtr == questionCtr){
            // The input is all correct, move to next stage.
            // Only increase inputCtr if otherwise
            questionCtr++;
            inputCtr = 0;
        }
        else
            inputCtr++;

        if (questionCtr == QUESTION_LIMIT) {
            // Cleared the game
            // SUCCESS MESSAGE
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 4; j++) {
                    LED_BUZZER_SHOW(j, 250);
                }
            }
            GAME_RESET();
        }

        // delay 1 second before continuing the program
        __delay_ms(1000);

        // Show the question
        question_show(questionArr, questionCtr);

    } else {
        // Input is valid, show error message and reset the board.
        for (int i = 0; i < 2; i++) {
            LED_BUZZER_SHOW(3, 250);
            LED_BUZZER_SHOW(0, 250);
        }
        // Reset the input information
        GAME_RESET();
    }

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
    array_init(questionArray, inputArray);

    while (1) {
    }
    return (EXIT_SUCCESS);
}