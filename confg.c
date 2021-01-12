#include "xc.h"

void Config_Init() {
    RCONbits.IPEN = 1;
    INTCONbits.GIE = 1;
    INTCONbits.INT0IE = 1;
    INTCONbits.INT0IF = 0;
    ADCON1bits.PCFG = 15;
}
