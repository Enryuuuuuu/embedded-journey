| (OR): Digunakan untuk MENYALAKAN bit. Jika salah satu bit (di variabel atau di mask) adalah 1, hasilnya 1.
0b1010 | 0b0100 -> 0b1110 (Lampu baru dinyalakan tanpa mematikan yang sudah nyala).

& (AND): Digunakan untuk MEMERIKSA atau MEMATIKAN bit. Hasilnya hanya 1 jika kedua bit (di variabel dan di mask) adalah 1.
0b1010 & 0b1100 -> 0b1000 (Hanya lampu yang sama-sama nyala yang tetap nyala).

^ (XOR): Digunakan untuk MEMBALIK status bit. Hasilnya 1 jika bitnya berbeda, dan 0 jika bitnya sama.
0b1010 ^ 0b1100 -> 0b0110 (Lampu yang statusnya sama akan mati, yang beda akan nyala).

~ (NOT): Membalik SEMUA bit. Semua 1 menjadi 0, dan semua 0 menjadi 1.
~0b10101010 -> 0b01010101

<< (Left Shift): Menggeser semua bit ke kiri. Ini adalah cara cepat untuk perkalian dengan pangkat 2.
0b00000001 << 3 -> 0b00001000 (Angka 1 digeser ke kiri 3 kali, menjadi 8).

> > (Right Shift): Menggeser semua bit ke kanan. Ini adalah cara cepat untuk pembagian dengan pangkat 2.
> > 0b00001000 >> 3 -> 0b00000001 (Angka 8 digeser ke kanan 3 kali, menjadi 1).
