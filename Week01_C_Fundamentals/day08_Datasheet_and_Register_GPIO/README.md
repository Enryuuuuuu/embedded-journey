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

- IO_MUX: this part responsible for routing pin output(hardware) to the peripheral that available in that pin. if we are using IO_MUX we have limitation that not all pin have some peripheral that directly connected, if the pin has a peripheral that directly connected we can use this peripheral by setting IO_MUX

- GPIO Matrix: this part has same responsible with IO_MUX, but in GPIO Matrix we can connect any pin with any peripheral even the pin not directly connected to the peripheral. this give us a flexibilities to built what we want with this esp32 but as a trade off the speed wil decreased.

the gate keeper:

- GPIO Register: after we are routing the path which peripheral we will use on a pin using IO_MUX or GPIO Matrix, next we can control the gate before it really connected to the outside world using GPIO Register, in this register we can control the pin to act as an output or input, giving logic HIGH or LOW (if the pin act as an OUTPUT), and controlling how much output do you want to produce.

for example pin 5 will use for SPI communication:

- first we will find out is pin 5 connected to the SPI peripheril directly
- if pin 5 connected to the SPI peripheril directly we can route pin 5 connected to the SPI peripheril using IO_MUX
- else if pin 5 not connected to the SPI peripheril directly we can route pin 5 connected to the SPI peripheril using GPIO MATRIX with trade off the speed wil decreased
- and then we control the pin 5 behavior using GPIO Register

===============================================================

Register to set pin act as an output & input:

- GPIO_ENABLE_REG : this register allow you to set all of pin that available in this register as output or input at once(lot of pin and condition(input or output) in one program)
- GPIO_ENABLE_W1TS_REG : this register allow you to set only one register to act as output (one pin one program)
- GPIO_ENABLE_W1TC_REG : this register allow you to set only one register to act as input (one pin one program)

===============================================================

Register to set HIGH or LOW output:

- GPIO_OUT_REG : this register allow you to set all of pin output level HIGH or LOW(lot of pin and condition(HIGH or LOW) in one program)
- GPIO_OUT_W1TS_REG : this register allow you to set only one output to give HIGH output(one pin one program)
- GPIO_OUT_W1TC_REG : this register allow you to set only one output to give LOW output(one pin one program)
