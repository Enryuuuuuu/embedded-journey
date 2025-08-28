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

==================================================================
Struct and Struct padding

struct is a data type that allow you to make a group that consist of various type and size of data. for example

struct weather_packet2 {
uint8_t packet_id; // 1 byte
float temperature_celsius; // 4 bytes
uint16_t humidity_percent; // 2 bytes
uint32_t pressure_pascals; // 4 bytes
};

that stuct is consist of a several data size and type like uint8_t,float, uint16_t, and uint32_t. to use struct first we should make the format for out struct. we should define what our struct consist of. next we should make variable using our struct as the data type:

struct weather_packet2 sensor2;

in that code we are making a variable named sensor2 that have data type weather_packet2.

to access the content of the struct we use dot operator (.):

sensor2.packet_id

the content of weather_packet2 data type have a various size of memory like uint8_t has 1 bytes, float has 4 bytes etc. if we count the sum of
the content of weather_packet2 data type have a various size of memory like uint8_t has 1 bytes, float has 4 bytes etc. if we count the sum of the sizes of the individual members of the struct weather_packet2 you will find thatThe sum of the parts is 11 bytes. but in fact the actual size of the struct is 16 bytes because something called padding. here is the detail about that.

// Alamat | Anggota | Ukuran | Penjelasan
//---------|-----------------------|---------|------------------------------------
// 0 | packet_id | 1 byte | Dimulai di alamat 0.
// 1 | <--- PADDING ---> | 3 byte | Ditambahkan agar 'float' mulai di kelipatan 4.
// 4 | temperature_celsius | 4 byte | Sekarang mulai di alamat 4.
// 8 | humidity_percent | 2 byte | Dimulai di alamat 8.
// 10 | <--- PADDING ---> | 2 byte | Ditambahkan agar 'uint32_t' mulai di kelipatan 4.
// 12 | pressure_pascals | 4 byte | Sekarang mulai di alamat 12.
//---------|-----------------------|---------|------------------------------------
// UKURAN TOTAL = 16 byte
