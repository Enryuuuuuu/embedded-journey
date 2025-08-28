#include<stdio.h>

int main(){
  int data_log[6] = {11,22,33,44,55,66};
  int *p_log = &data_log[1];

  for(int i = 0; i <= 5; i++){
    printf("Nilai data_log[%d] : %d\n", i, data_log[i]);
  }

  for(int i = 0; i <= 5; i++){
    printf("Nilai data_log[%d] dengan pointer : %d\n", i, *(p_log + i));
  }

  for(int i = 0; i <= 5; i++){
    printf("alamat data_log[%d] : %p\n", i, (p_log + i));
  }

  printf("size of int is : %zd\n", sizeof(int));
  printf("isi array : %ull", data_log);
  return 0;
}