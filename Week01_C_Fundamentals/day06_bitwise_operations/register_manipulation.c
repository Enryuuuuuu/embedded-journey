#include<stdio.h>
#include<stdint.h>

void print_binary(unsigned int n) {
    for (int i = 7; i >= 0; i--) {
        unsigned int mask = 1u << i;
        putchar((n & mask) ? '1' : '0');
    }
}

int main(){
  uint8_t led_register = 0b00000000;
  printf("Initial Value: %d\n", led_register);

  printf("Tugas Set versi 1\n");
  led_register = led_register | ((1 << 3)|(1 << 7));
  print_binary(led_register);
  printf("\n");
  
  printf("Tugas CLEAR versi 1\n");
  led_register = led_register & (1 << 3);
  print_binary(led_register);
  printf("\n");

  printf("Tugas CLEAR versi 2\n");
  led_register = led_register & ~(1 << 7);
  print_binary(led_register);
  printf("\n");

//jawaban versi 1 tugas clear kurang tepat karena yang 
// dilakukan disana adalah mematikan semuanya,  buka bit 7 saja

  printf("Tugas TOOGLE versi 1\n");
  led_register = led_register ^ (1 << 3) ^ (1 << 0);
  print_binary(led_register);
  printf("\n");

  printf("Tugas CHECK  versi 1\n");
  if(led_register & (1 << 0)){
    printf("LED 0 is ON");
  }
  else{
    printf("LED 0 is OFF");
  }

  return 0;
  

}
