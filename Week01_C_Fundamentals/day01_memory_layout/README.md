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
