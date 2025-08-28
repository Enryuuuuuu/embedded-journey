#include<stdio.h>

void apply_damage(int *p_health){
  *p_health -= 10;
}

int main(){
  int player_health = 100;
  printf("player health = %d\n", player_health);
  apply_damage(&player_health);
  printf("player health = %d", player_health);
  return 0;
}