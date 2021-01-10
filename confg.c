#include "xc.h"

void Config_Init() {
    RCONbits.IPEN = 0x1;
    INTCONbits.GIE = 0x1;
    INTCONbits.INT0IE = 0x1;
    INTCONbits.INT0IF = 0x0;
}
