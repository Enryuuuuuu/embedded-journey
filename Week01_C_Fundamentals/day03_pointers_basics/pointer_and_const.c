#include<stdio.h>

/*
case 1: const int * p_nilai
case 2: int * const p_nilai
case 3: const int * const p_nilai
*/

// case 1 berhasil, tidak ada error
void case1(){
  int object1 = 10;
  int object2 = 20;
  const int * p_nilai = &object1;
  printf("============================================\n");
  printf("                  case1\n");
  printf("============================================\n");
  printf("nilai yang ditunjuk pointer : %d\n", *p_nilai);
  printf("alamat yang ditunjuk pointer : %p\n", p_nilai);
  printf("\n");

  object1 = 30;
  printf("nilai yang ditunjuk pointer : %d\n", *p_nilai);
  printf("alamat yang ditunjuk pointer : %p\n", p_nilai);
  printf("\n");
  
  p_nilai = &object2;
  printf("nilai yang ditunjuk pointer : %d\n", *p_nilai);
  printf("alamat yang ditunjuk pointer : %p\n", p_nilai);
  printf("\n");
}

// //case 2 gagal, error pointer p_nilai tidak dapat ditimpa dengan alamat object2
// void case2(){
//   int object1 = 10;
//   int object2 = 20;
//   int * const p_nilai = &object1;
//   printf("============================================\n");
//   printf("                  case2\n");
//   printf("============================================\n");
//   printf("nilai yang ditunjuk pointer : %d\n", *p_nilai);
//   printf("alamat yang ditunjuk pointer : %p\n", p_nilai);
//   printf("\n");

//   object1 = 30;
//   printf("nilai yang ditunjuk pointer : %d\n", *p_nilai);
//   printf("alamat yang ditunjuk pointer : %p\n", p_nilai);
//   printf("\n");
  
//   p_nilai = &object2;
//   printf("nilai yang ditunjuk pointer : %d\n", *p_nilai);
//   printf("alamat yang ditunjuk pointer : %p\n", p_nilai);
//   printf("\n");
// }


// //case 3 gagal, error pointer p_nilai tidak dapat ditimpa dengan alamat object2
// void case3(){
//   int object1 = 10;
//   int object2 = 20;
//   const int * const p_nilai = &object1;
//   printf("============================================\n");
//   printf("                  case3\n");
//   printf("============================================\n");
//   printf("nilai yang ditunjuk pointer : %d\n", *p_nilai);
//   printf("alamat yang ditunjuk pointer : %p\n", p_nilai);
//   printf("\n");

//   object1 = 30;
//   printf("nilai yang ditunjuk pointer : %d\n", *p_nilai);
//   printf("alamat yang ditunjuk pointer : %p\n", p_nilai);
//   printf("\n");
  
//   // p_nilai = &object2;
//   printf("nilai yang ditunjuk pointer : %d\n", *p_nilai);
//   printf("alamat yang ditunjuk pointer : %p\n", p_nilai);
//   printf("\n");
// }

int main(){
  case1();
  // case2();  
  // case3();
  return 0;
}