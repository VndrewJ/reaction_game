#include "button.h"

Button::Button(int button_pin, int led_pin) : _button_pin(button_pin), _led_pin(led_pin), _pressed_flag(false), _lit_flag(false) {
    pinMode(_button_pin, INPUT);
    pinMode(_led_pin, OUTPUT);
    digitalWrite(_led_pin, LOW); // Start with the LED off
}

bool Button::is_pressed(){
    //TODO
}

void Button::set_pressed(){
    //TODO
}

bool Button::is_lit(){
    //TODO
}

void Button::set_light(bool level){
    //TODO
}