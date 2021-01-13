#include <stdlib.h>
#include <time.h>
#include "led.h"
#include "buzzer.h"
#include "xc.h"
#include "utils.h"
#include "config.h"

void array_init(int *quesArr, int *inpArr){
    srand(time(NULL));
    for(int i = 0; i < QUESTION_LIMIT; i++){
        quesArr[i] = rand()%4;
        inpArr[i] = -1;
    }
    return;
}

void question_show(int *q, int ptr) {
    for(int i = 0; i <= ptr; i++) {
        LED_BUZZER_SHOW(q[i], 500);
    }
}

int validityCheck(int *quesArr, int *inpArr, int inpCtr){
    if(quesArr[inpCtr] == inpArr[inpCtr])
        return 1;
    else
        return 0;
}
