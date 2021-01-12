#ifndef BUZZER_H
#define	BUZZER_H

/**
 * Definition of Buzzer Interface
 * 
 * Interface
 * - Buzzer_Init
 * - Buzzer_On
 * - Buzzer_Off
 * - Buzzer_On_500ms
 */

void Buzzer_Init(void);
void Buzzer_On(int buzzer_ID);
void Buzzer_Off(int buzzer_ID);

void Buzzer_On_500ms(int buzzer_ID);

#endif
