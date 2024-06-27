#include <Arduino.h>
#include "../lib/button.h"

/* Button Initialisation */
Button button_1(5, 16);

void IRAM_ATTR handle_button_1(){
  button_1.set_pressed();
}

void setup() {
  Serial.begin(115200);
  Serial.println("testing");
}

void loop() {
  bool toggle = button_1.is_pressed();
  button_1.set_light(!toggle);
}
