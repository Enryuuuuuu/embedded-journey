#include<stdio.h>
#include<stdint.h>

void main(){
    //print sizes of data types
    printf("Size of int: %d bytes\n", sizeof(int));
    printf("Size of long: %zu bytes\n", sizeof(long));
    printf("Size of long long: %zu bytes\n", sizeof(long long));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of char: %zu bytes\n", sizeof(char));
    printf("Size of int8_t: %zu bytes\n", sizeof(int8_t));
    printf("Size of int16_t: %zu bytes\n", sizeof(int16_t));
    printf("Size of int32_t: %zu bytes\n", sizeof(int32_t));
    printf("Size of int64_t: %zu bytes\n", sizeof(int64_t));
    printf("Size of uint8_t: %zu bytes\n", sizeof(uint8_t));
    printf("Size of uint16_t: %zu bytes\n", sizeof(uint16_t));
    printf("Size of uint32_t: %zu bytes\n", sizeof(uint32_t));
    printf("Size of uint64_t: %zu bytes\n", sizeof(uint64_t));
    printf("Size of size_t: %zu bytes\n", sizeof(size_t));
    printf("\n");

    
    //test oveflow integer
    uint8_t overflowtest = 254;
    printf("\nValue before overflow: %u\n", overflowtest);
    overflowtest += 1;
    printf("Value after adding 1: %u\n", overflowtest);
    overflowtest += 1;
    printf("Value after adding another 1 (overflow): %u\n", overflowtest);
    overflowtest += 1;
    printf("Value after adding yet another 1: %u\n", overflowtest);
}