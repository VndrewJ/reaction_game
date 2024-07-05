#include "button.h"

Button::Button(int button_pin, int led_pin) : _button_pin(button_pin), _led_pin(led_pin), _lit_flag(false) {
    pinMode(_button_pin, INPUT);
    pinMode(_led_pin, OUTPUT);
    digitalWrite(_led_pin, LOW); // Start with the LED off

    test_pressed_flag = false;
}

bool Button::is_lit(){
    return _lit_flag;
}

void Button::set_light(bool level){
    this->_lit_flag = level;
    digitalWrite(_led_pin, level);
}
