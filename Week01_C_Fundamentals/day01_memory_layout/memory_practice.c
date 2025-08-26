#include<stdio.h>

long int global_id = 99;

void calculate_something (int multiplier) {
  double local_result;
  int *ptrMultiplier = &multiplier;
  double *ptrlocal_result = &local_result;
  printf("alamat variabel multiplier %p\n",ptrMultiplier);
  printf("alamat variabel local result %p\n",ptrlocal_result);
}

int main() {
  char main_flag = 'H';
  char *ptrMainFlag = &main_flag;
  long int *ptrGlobalId = &global_id;
  printf("alamat variabel main flag %p\n",ptrMainFlag);
  printf("alamat variabel global %p\n",ptrGlobalId);
  calculate_something(100);
  return 0;
}