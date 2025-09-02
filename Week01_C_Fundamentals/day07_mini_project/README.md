Tujuan Proyek
Proyek "Smart LED Array Controller" ini dirancang sebagai puncak pembelajaran dari fondasi bahasa C untuk sistem tertanam. Tujuannya adalah untuk mensimulasikan firmware sederhana berbasis command-line yang mengintegrasikan berbagai konsep kunci dalam satu program yang fungsional dan kohesif.

Proyek ini secara spesifik menerapkan:

Manajemen Status menggunakan uint8_t sebagai register virtual untuk 8 LED.

Operasi Bitwise (|, &, ~, ^) sebagai mekanisme level rendah untuk memanipulasi status LED secara individual.

Struktur Data Logis menggunakan struct untuk membungkus data dan perilaku sebuah perintah.

Arsitektur Callback menggunakan function pointer untuk menciptakan sistem yang fleksibel dan skalabel, di mana logika eksekusi dipisahkan dari logika pengambilan keputusan.

Penanganan Input dengan mem-parsing perintah dan argumen dari pengguna untuk interaksi real-time.

=================================================================================

NOTE: Pastikan untuk membaca dokumentasi terlebih dulu jika menemukan fungsi atau sintak baru
