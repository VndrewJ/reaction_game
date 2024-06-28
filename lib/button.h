#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button{
private:
    int _button_pin;
    int _led_pin;
    volatile bool _lit_flag;
public:
    bool test_pressed_flag;

    Button(int button_pin, int led_pin);
    
    bool is_lit();
    void set_light(bool level);
};

#endif