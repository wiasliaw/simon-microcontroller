#include "xc.h"

void Button_Init(void) {
    // define RA4-0 is input
    TRISA = 0x1F;
}