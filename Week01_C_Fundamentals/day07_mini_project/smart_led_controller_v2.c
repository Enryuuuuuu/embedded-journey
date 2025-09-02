#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h>

uint8_t led_register = 0b00000000;
char input_buffer[20];
char command[15];
int pin = -1;

//fungsi untuk mencetak bilangan biner x bit

void print_binary(uint8_t n) {
    for (int i = 7; i >= 0; i--) {
        unsigned int mask = 1u << i;
        putchar((n & mask) ? '1' : '0');
    }
}


enum CommandType{
  TURN_ON,
  TURN_OFF,
  TOGGLE,
  STATUS,
  EXIT
};

void action_turn_on(uint8_t *reg, int led_num){
  printf("turn on\n");
  *reg = *reg | (1 << led_num);
  printf("status LED register : ");
  print_binary(led_register);
  printf("\n");
  printf("\n");
}

void action_turn_off(uint8_t *reg, int led_num){
  printf("turn off\n");
  *reg = *reg & (~(1 << led_num));
  printf("status LED register : ");
  print_binary(led_register);
  printf("\n");
  printf("\n");
}

void action_toggle(uint8_t *reg, int led_num){
  printf("toggle\n");
  *reg = *reg ^ (1 << led_num);
    printf("status LED register : ");
  print_binary(led_register);
  printf("\n");
  printf("\n");
}

void action_print_status(uint8_t *reg, int led_num){
  printf("Status LED %d saat ini : ", led_num);
  if(*reg & (1 << led_num))   printf("ON");
  else   printf("OFF");
  printf("\n");
  printf("\n");
}

void action_exit(uint8_t *reg, int led_num){
  exit(0); //untuk kill program yang sedang dirunning
}


/*void action_print_status(uint8_t reg); 
parameter fungsi action_print_status diubah supaya 
memiliki parameter yang sama dengan fungsi lain 
sehingga kita hanya membutuhkan satu pointer function
*/

struct Command{
  char *name; 
  enum CommandType instruksi;
  void (*action_machine)(uint8_t *, int);
};


int main(){
  struct Command Perintah[5];

  Perintah[0].name = "Turn_on";
  Perintah[0].instruksi = TURN_ON;
  Perintah[0].action_machine = action_turn_on;
  Perintah[1].name = "Turn_off";
  Perintah[1].instruksi = TURN_OFF;
  Perintah[1].action_machine = action_turn_off;
  Perintah[2].name = "Toggle";
  Perintah[2].instruksi = TOGGLE;
  Perintah[2].action_machine = action_toggle;
  Perintah[3].name = "Print_status";
  Perintah[3].instruksi = STATUS;
  Perintah[3].action_machine = action_print_status;
  Perintah[4].name = "Exit";
  Perintah[4].instruksi = EXIT;
  Perintah[4].action_machine = action_exit;

  while(1){
    printf("Masukan perintah :");
    fflush(stdout);
    fgets(input_buffer, sizeof(input_buffer), stdin); //meminta input dari keyboar hingga enter
    int item_read = sscanf(input_buffer, "%s %d", command, &pin); //memparsing string dengan delimiter white char
    int status_validasi = 1;
    // printf("%d", item_read); untuk debug

    for(int i = 0; i < 5; i++){
      // printf("Masuk for"); untuk debug
      if(strcmp(command, Perintah[i].name) == 0){ //membandingakan string
        // printf("Masuk if utama"); untuk debug
        if((Perintah[i].instruksi == TURN_ON || Perintah[i].instruksi == STATUS ||Perintah[i].instruksi == TURN_OFF || Perintah[i].instruksi == TOGGLE) &&  item_read < 2){
          status_validasi = 1;
          break;
        }

        else if(Perintah[i].instruksi == EXIT && item_read > 1){
          status_validasi = 1;
          break;
        }

        else{
            // printf("Masuk else"); untuk debug
          Perintah[i].action_machine(&led_register, pin);
          status_validasi = 0;
          break;
        }
      }
    }

    if(status_validasi == 1){
      printf("Input tidak valid\n\n");
    }

  }
return 0;
}



