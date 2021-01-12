#ifndef LED_H
#define	LED_H

/**
 * Definition of LED Interface
 * 
 * Interface
 * - LED_Init
 * - LED_On
 * - LED_Off
 * - LED_On_500ms
 */

void LED_Init();
void LED_On(int led_ID);
void LED_Off(int led_ID);

void LED_On_500ms(int led_ID);

#endif
