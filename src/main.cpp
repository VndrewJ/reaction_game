#include <Arduino.h>
#include "../lib/button.h"

#define BUTTON_1 5
#define LED_1 16

/* Button Initialisation */
Button button_1(BUTTON_1, LED_1);

void IRAM_ATTR handle_button_1(){
  /*
  if light on
    get time since light turned on
  if light off
    you lose, jumped the gun
  */

  //button debug
  button_1.test_pressed_flag = !button_1.test_pressed_flag;
}

void setup() {
  Serial.begin(115200);
  Serial.println("starting.....................");

  //interrupt setup
  attachInterrupt(BUTTON_1, handle_button_1, RISING);
}

void loop() {
  //toggles the light
  button_1.set_light(button_1.test_pressed_flag);
}
