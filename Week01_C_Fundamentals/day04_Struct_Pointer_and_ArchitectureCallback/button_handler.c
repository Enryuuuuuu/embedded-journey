#include<stdio.h>

void play_music(){
  printf("playing music...\n");
}
void stop_music(){
  printf("music stoped...\n");
}

struct Button{
  int pin;
  void (*on_press_action)(void);
};

int main(){
  struct Button button_play;
  struct Button button_stop;

  button_play.on_press_action = play_music;
  button_stop.on_press_action = stop_music;

  button_play.on_press_action();
  button_stop.on_press_action();


  return 0;
}