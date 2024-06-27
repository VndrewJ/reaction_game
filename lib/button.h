#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button{
private:
    int _button_pin;
    int _led_pin;
    volatile bool _pressed_flag;
    volatile bool _lit_flag;
public:
    Button(int button_pin, int led_pin);

    bool is_pressed();
    void set_pressed();
    
    bool is_lit();
    void set_light(bool level);
};

#endif