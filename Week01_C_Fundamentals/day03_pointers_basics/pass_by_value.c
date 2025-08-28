#include<stdio.h>

void damage_taken(int health){
  health -= 10;
}

int main(){
  int player_health = 100;
  printf("player health : %d\n", player_health);
  damage_taken(player_health);
  printf("player health : %d\n", player_health);
  return 0;
}

/*
Hasil: 100 -> 100. Nilai player_health tidak berubah.
hal ini terjadi karena pada program diatas kita tidak
merekayasa isi dari variabel player_health.
pada fungsi damage_taken() kita hanya mengambil salinan
dari variabel player_health, sehingga isi dari varible 
player_health tidak berubah.
*/

