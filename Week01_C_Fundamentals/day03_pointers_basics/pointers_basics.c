#include<stdio.h>

int main(){
  int level_daya = 9000;
  int *p_level_daya = NULL;
  p_level_daya = &level_daya;
  printf("nilai variabel level_daya = %d\n", level_daya);
  printf("alamat variabel level_daya = %p\n", &level_daya);
  printf("nilai pointer p_level_daya = %p\n", p_level_daya);
  printf("nilai yang ditunjuk pointer = %d\n", *p_level_daya);
  
  *p_level_daya = 9001;
  printf("nilai variabel level_daya = %d\n", level_daya);
  return 0;
}