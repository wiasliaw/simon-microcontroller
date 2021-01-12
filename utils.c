#include <stdlib.h>
#include <time.h>
#include "led.h"
#include "xc.h"

void ques_init(int *q) {
    srand(time(NULL));
    for(int i=0; i<10; i++) {
        q[i] = rand()%4;
    }
}

int ques_check(int *q, int ptr, int src) {
    if(q[ptr] == src) {
        ptr++;
        return 1;
    }
    return 0;
}

void ques_next(int *q, int ptr) {
    for(int i=0; i<ptr; i++) {
        LED_On(q[i]);
        LED_Off(q[i]);
    }
}
