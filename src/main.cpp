#include <Arduino.h>

#include "../lib/button.h"
#include "../lib/state.h"
#include "../lib/player.h"

#define BUTTON_1 5
#define BUTTON_2 1
#define BUTTON_3 10
#define BUTTON_4 15
#define LED_1 16
#define LED_2 2
#define LED_3 11
#define LED_4 12

#define PLAYER_RED 1
#define PLAYER_GREEN 2

/* Button Initialisation */
Button button_1(BUTTON_1, LED_1);
Button button_2(BUTTON_2, LED_2);
Button button_3(BUTTON_3, LED_3);
Button button_4(BUTTON_4, LED_4);

/* Player Initialisation */
Player player_red(button_1, button_2);
Player play_green(button_3, button_4);

/* Game Variables */
STATE state;
bool player_pressed;
bool light_dir;

/* Timer Initialisation */
hw_timer_t *light_timer = NULL;
uint32_t timer_interval;
bool light_timer_flag;


/* TO DO
- light timer
- timeout timer
*/

/**************INTERRUPTS***************/
void IRAM_ATTR handle_button_1(){
  if(state == (NO_LIGHT || YES_LIGHT)){
    button_1.set_light(HIGH);
    player_pressed = PLAYER_RED;
  }
  //button animation
}

void IRAM_ATTR handle_button_2(){
  if(state == (NO_LIGHT || YES_LIGHT)){
    button_2.set_light(HIGH);
    player_pressed = PLAYER_RED;
  }
  //button animation
}

void IRAM_ATTR handle_button_3(){
  if(state == (NO_LIGHT || YES_LIGHT)){
    button_3.set_light(HIGH);
    player_pressed = PLAYER_GREEN;
  }
  //button animation
}

void IRAM_ATTR handle_button_4(){
  if(state == (NO_LIGHT || YES_LIGHT)){
    button_4.set_light(HIGH);
    player_pressed = PLAYER_GREEN;
  }
  //button animation
}

void IRAM_ATTR light_timer_cb(){
  Serial.println("light is on now");
  light_timer_flag = true;
}


/**************MAIN**************/
void setup(){
    //set initial states
    state = NO_LIGHT;
    player_pressed = 0;
    light_timer_flag = false;
    Serial.begin(115200);
    Serial.println("starting.....................");

    //interrupt setup
    noInterrupts();
    attachInterrupt(BUTTON_1, handle_button_1, RISING);

    //timer setup
    randomSeed(analogRead(0));
    light_timer = timerBegin(0, 80, true);
    timerAttachInterrupt(light_timer, &light_timer_cb, true);
    timerAlarmDisable(light_timer);
}

void loop(){
    switch(state)
    {
      case STARTING:
        //select random time from 3s to 11s
        timer_interval = random(3000000, 11000000);       
        timerAlarmWrite(light_timer, timer_interval, true);

        //choose light direction
        light_dir = random(0, 1);     
        state = NO_LIGHT;
        break;
      
      case NO_LIGHT:
        //start timer
        timerAlarmEnable(light_timer);
        if(light_timer_flag){
          light_timer_flag = false;
          timerAlarmDisable(light_timer);
          state = STARTING;
        }
    }
}
