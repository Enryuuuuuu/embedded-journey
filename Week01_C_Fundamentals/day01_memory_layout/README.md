SEGMENTASI MEMORI KONPUTER
Secara Umum memori komputer dibagi menjadi 2 yaitu ROM dan RAM
ROM digunakan untuk menyimpan data yang tidak berubah seperti bahasa mesin hasil kompilasi dari program yang kita buat
sedangkan pada RAM di pecah menjadi beberapa bagian yaitu:
Data segment: untuk menyimpan variable static atau global yang didefinisikan nilainya (!= 0)
BSS segement: untuk menyimpan variable static atau global yang tidak didefinisikan nilainya (nilainya akan diisi 0)
stack : untuk menyimpan variable local yang alamatnya tidak kita tentukan
heap : untuk menyimpan variable local yang alamatnya kita tentukan (new() dan delete() dalam cpp sedangkan malloc() dan free() dalam C)

variabel:
global: dapat diakses oleh semua fungsi dan file lain(dengan bantuan extern), lifetimenya selama program dieksekusi
static : hanya dapat diakses oleh fungsinya sendiri, nilainya akan tetap walaupun fungsi selesai dieksekusi
local: hanya dapat diakses oleh fungsinya sendiri, akan dihapus setelah fungsi seslesai dieksekusi

penggunaan heap harus hati hati karena setiap memori yang di alokasikan pada heap akan terus dipertahankan hingga memori dibebaskan. jika kita lupa membebaskan memori maka akan terjadi memory leak. selain itu juga dalam penggunaan heap ada ancaman fragmentasi memori dimana ketika memori dipecah menjadi beberapa bagian dan kita tidak lupa membebaskan memori yang sudah tidak dipakai akan ada kemungkinan dimana memori yang dibebaskan akan terbagi menjadi beberapa bagian kecil sehingga kita tidak bisa menggunakannya dalam satu kesatuan memori yang besar.

dalam penggunaan memori pada stack memori variabel pada fungsi main ditempatkan berbeda dengan fungsi lainnya. variabel fungsi main memiliki alamat yang lebih tinggi (lebih besar) dari pada alamat fungsi lain

saat sebuah variabel lokal(sebut saja varlok1) dari sebuah fungsi dibuat dan memakan memori dengan alamat a lalu fungsi tersebut selesai dieksekusi kemudian dieksekusi kembali, maka alamat yang dipakai oleh varlok1 besar kemungkinan alamat a lagi.

ketika fungsi varlok1 selesai di eksekusi lalu fungsi lain dengan variabel lokal lain(sebut saja varlok2) dieksekusi maka varlok2 akan menempati alamat a

saat mengeksekusi fungsi dimana varlok2 berada lalu sebelum fungsi itu berakhir kita mengeksekusi fungsi dengan varlok1, maka alamat a akan berisi varlok2 dan alamat b akan berisi varlok1
