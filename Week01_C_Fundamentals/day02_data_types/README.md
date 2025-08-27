ambiguity of size of integer in C leanguage

every different data type has a different memory size, such as integer use 4-8bytes of memory char use 1byte memory

if we use a general int data type in C leanguage such as int for your embedded system it might be cause a problem, because general int in C have a uncertian size. the size of general int in C depend on "natural word size". natural word size is a size of data that computer can proses data in that size with the most eficient way. for example:

- in the old 16bit microcontroller int is only 2 bytes in size. 2 bytes is come from 16bit, that we know 1 byte is 8 bit, so 16 bit is equal to 2 bytes
- in newest 32bit microcontroller int is 4 bytes in size. 4 bytes is come from 32bit, that we know 1 byte is 8 bit, so 32 bit is equal to 4 bytes

this inconsistency of int size is not a weakness of c leanguage. this was created on purpose to make c leanguage code fast in every devices.

to handle this, we can use a stdint.h header. this header file provide a several type of data integer that consisten in size no matter how much natural word size of our device.

==================================================================
How to print sizeof

%z is usually used with another specifier like d or u --> %zd or %zu.

the function of %z is for show value of size_t data type

size_t data type is a unsigned integer in c leanguage that used for define object size(result from sizeof operator)

=================================================================
variable overflow

we know that value of 8 bit unsigned integer is in range 0 until 255.
if we have a unsigned 8 bit integer, that we fill that variabel with 255. and then we add that varaible with 2, the result of addition wont be 257, but it will back to 0 after the value is bigger than 255, so the result of addition will be 1.
