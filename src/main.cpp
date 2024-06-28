#include <Arduino.h>

#include "../lib/button.h"
#include "../lib/state.h"
#include "../lib/player.h"
#include "../lib/interrupt.h"

#define BUTTON_1 5
#define BUTTON_2 1
#define LED_1 16
#define LED_2 2

/* Button Initialisation */
Button button_1(BUTTON_1, LED_1);
Button button_2(BUTTON_2, LED_2);

/* State Variables */
STATE state;

/* Player Initialisation */
Player player_red(button_1, button_2);

/* TO DO
- light timer
- timeout timer
*/

void setup(){
    state = NO_LIGHT;
    Serial.begin(115200);
    Serial.println("starting.....................");

    //interrupt setup
    noInterrupts();
    attachInterrupt(BUTTON_1, handle_button_1, RISING);
}

void loop(){
    switch(state)
    {
      case STARTING:
        //calculates time till light turns on (t/c interrupt val)
        //randomly pick light r or l
        //go to NO_LIGHT
        break;
      
      case NO_LIGHT:
        //starts timer
        //if button pressed
        //  award OTHER player a point
        //  go to ROUND_OVER
        //else
        //  go to YES_LIGHT;
        break;

      case YES_LIGHT:
        //Start timeout timer
        //if button pressed
        //  award that player a point
        //else
        // go to ROUND_OVER

      case ROUND_OVER:
        //cute lil animation on screen or on the buttons idk
        //break for 5 seconds
        //if a player has 5 points
        //  go to GAME_OVER
        //else
        //  go to STARTING

      case GAME_OVER:
        //cute lil animation showing winner
        //idle, wait for restart
    }
}
