#include "player.h"

Player::Player(Button &left_button, Button &right_button) : _left_button(left_button), _right_button(right_button) {}

void Player::set_light(Button &button, bool level){
    button.set_light(level);
    if(level == HIGH){
        this->is_lit = true;
    }else{
        this->is_lit = false;
    }
}