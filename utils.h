#ifndef UTILS_H
#define	UTILS_H
#define QUESTION_LIMIT 10

#define LED_BUZZER_SHOW(ID, LENGTH) \
        LED_On(ID); \
        Buzzer_On(ID); \
        __delay_ms(LENGTH); \
        Buzzer_Off(ID); \
        LED_Off(ID);

#define GAME_RESET() \
        array_init(questionArray, inputArray); \
        questionCtr = 0; \
        inputCtr = 0;

void array_init(int*, int*);
void question_show(int*, int);
int validityCheck(int*, int*, int);

#endif	/* UTILS_H */
