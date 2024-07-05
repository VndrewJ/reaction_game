#ifndef PLAYER_H
#define PLAYER_H

#include "button.h"

class Player{
    protected:
        Button _left_button;
        Button _right_button;
        /*TODO
        - score
        */

    public:
        bool is_lit;

        Player(Button &left_button, Button &right_button);
        void set_light(Button &button, bool level);
};

#endif