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
        Player(Button &left_button, Button &right_button);

};

#endif