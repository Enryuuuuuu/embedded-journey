ambiguity of size of integer in C language

Every data type has a different memory size. For example, an integer uses 4-8 bytes of memory, while a char uses 1 byte.

Using a general-purpose data type like int in an embedded system can cause problems, because the int type has an uncertain size in C. the size of a standard int in C depends on the processor's 'natural word size'. The natural word size is the amount of data that a CPU can process most efficiently in a single operation. for example:

- in the old 16bit microcontroller int is only 2 bytes in size. 2 bytes is comes from 16bit, that we know 1 byte is 8 bit, so 16 bit is equal to 2 bytes
- in newest 32bit microcontroller int is 4 bytes in size. 4 bytes is comes from 32bit, that we know 1 byte is 8 bit, so 32 bit is equal to 4 bytes

This inconsistency is not a weakness of the C language; it was created intentionally to make C code performant on any device.

to handle this, we can use a stdint.h header. This header file provides several integer data types that are consistent in size no matter how much natural word size of our device.

==================================================================
How to print sizeof

%z is usually used with another specifier like d or u --> %zd or %zu.

The purpose of the %z format specifier is to display the value of a size_t data type.

size_t data type is a unsigned integer in c language that used for define object size(result from sizeof operator)

=================================================================
variable overflow

we know that value of 8 bit unsigned integer is in range 0 until 255.

If we have an unsigned 8-bit integer (uint8_t) with a value of 255 and add 2 to it, the result won't be 257. Instead, because the value has exceeded the maximum limit, it wraps back around to 0, and the final result will be 1.
