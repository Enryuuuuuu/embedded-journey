Uji Kompetensi Teori

1. Jika datasheet adalah satu-satunya sumber kebenaran, mengapa mengandalkan tutorial atau contoh kode dari internet bisa berbahaya saat mengerjakan proyek profesional?

- karena khususnya dalam memory map yang berbicara soal register, apabila kita mengandalkan sumber yang tidak kredibel akan berbahaya contohnya bila pengetahuan kita salah soal alamat salah satu register itu bisa saja mengacaukan data yang ada atau bahkan mengaktifkan register yang salah yang terhubung ke output yang tidak seharusnya di ubah kondisinya

2. Anda ingin menyalakan LED yang terhubung ke pin GPIO 5. Menggunakan analogi "Kantor Pos Internal", jelaskan langkah-langkah konseptual yang harus Anda lakukan untuk mencapai ini.

- pertama saya harus mencari alamt pos dari GPIO, selanjutnya saya harus memerintahkan GPIO 5 sebagai output digital, dan dilanjut dengan memerintahkan GPIO 5 yang sudah menjadi output digital tersebut untuk aktif

3. Di dalam kode C, kita akan berinteraksi dengan register ini menggunakan pointer. Mengapa pointer adalah alat yang paling tepat untuk tugas ini?

- karena pointer adalah variable khusus yang memungkinkan kita untuk menyimpan alamat suatu memori, sehingga untuk menyimpan alamat dari register kitaa harus menggunakan pointer

===============================================================

IO in EPS32 is organized by 2 parts (Digital Output case)

the router:

- IO_MUX: This component is responsible for routing a pin's output to a peripheral that is available on that specific pin. The IO_MUX has limitations, as not all pins are directly connected to every peripheral. If a pin has a direct connection, we can use it by configuring the IO_MUX

- GPIO Matrix: this part has same responsible with IO_MUX, but in GPIO Matrix we can connect any pin with any peripheral even the pin not directly connected to the peripheral. This gives us the flexibility to build what we want, but the trade-off is a slight decrease in speed.

the gate keeper:

- GPIO Register: After routing the path and selecting which peripheral to use with the IO_MUX or GPIO Matrix, we can then control the pin before it connects to the outside world using the GPIO Registers. These registers allow us to configure the pin as an input or output, set the logic level to HIGH or LOW (if configured as an output), and control properties like drive strength." (Note: "how much output" is better described as "drive strength" in technical terms).

for example pin 5 will use for SPI communication:

- first we will find out is pin 5 connected to the SPI peripheril directly
- if pin 5 connected to the SPI peripheril directly we can route pin 5 connected to the SPI peripheril using IO_MUX
- else if pin 5 not connected to the SPI peripheril directly we can route pin 5 connected to the SPI peripheril using GPIO MATRIX with trade off the speed wil decreased
- and then we control the pin 5 behavior using GPIO Register

===============================================================

Register to set pin act as an output & input:

- GPIO_ENABLE_REG : This register allows you to configure multiple pins as either inputs or outputs in a single operation.(lot of pin and condition(input or output) in one program)
- GPIO_ENABLE_W1TS_REG : This register allows you to safely set a single pin to act as an output without affecting other pins.(one pin one program)
- GPIO_ENABLE_W1TC_REG : This register allows you to safely set a single pin to act as an input without affecting other pins.(one pin one program)

===============================================================

Register to set HIGH or LOW output:

- GPIO_OUT_REG : this register allow you to set all of pin output level HIGH or LOW(lot of pin and condition(HIGH or LOW) in one program)
- GPIO_OUT_W1TS_REG : this register allow you to set only one output to give HIGH output(one pin one program)
- GPIO_OUT_W1TC_REG : this register allow you to set only one output to give LOW output(one pin one program)
