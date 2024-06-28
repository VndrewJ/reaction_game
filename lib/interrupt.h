#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <Arduino.h>
//RED buttons
void IRAM_ATTR handle_button_1();
void IRAM_ATTR handle_button_2();

//GREEN buttons
void IRAM_ATTR handle_button_3();
void IRAM_ATTR handle_button_4();

#endif