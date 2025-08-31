Enum (Enumeration)

mendefinisikan angka dengan kata yang merepresentasikan angka tersebut. ini akan meningkatkan aspek keamanan dan keterbacaan dari program kita. contohnya:

Bayangkan kita sedang membuat program untuk mengontrol sebuah kipas angin yang memiliki empat kecepatan: OFF, LOW, MEDIUM, HIGH. jika menggunakan enum untuk merepresentasikan empat mode kecepatan ini dengan kata seperti OFF, LOW, MEDIUM, HIGH akan membuat program kita jadi lebih jelas untuk dibaca oleh orang lain. contohnya if (kecepatan == MEDIUM) akan lebih mudah dimengerti dibanding if (kecepatan == 2).

penulisan enum:

enum TrafficLightState {
OFF, // Compiler akan menganggap ini sebagai 0
LOW, // Compiler akan menganggap ini sebagai 1
MEDIUM, // Compiler akan menganggap ini sebagai 2
HIGH // Compiler aka menganggap ini sebagai 3
};

jika semua anggota enum tidak diberi nilai maka kompiler akan memasukan nilai mulai dari 0 dan angka selanjutnya ditambah 1. jika hanya satu anggota saja yang tidak diberi nilai maka kompiler akan memberi nilai anggota tersebut dengan nilai sebelumnya ditambah 1

=============================================================================================================
malloc() (memory allocation)

sebuah fungsi untuk meminta sistem menyediakan memory di heap(masih bagian dari RAM). output fungsi ini adalah pointer yang mengarah ke awal dari blok memory dengan ukuran yang kita minta. jika ukuran memory yang kita minta tidak tersedia dalam heap maka malloc() akan mengirimkan pointer NULL. oleh karena kita sebelum menggunakan pointer dari malloc() pastikan untuk selalu memeriksa apakah pointernya NULL atau tidak.

malloc() akan mengirimkan NULL ketika memori tidak memiliki cukup ruang di heap untuk permintaan kita. hal ini bisa terjadi karena beberapa hal seperti memori penuh atau memori tersegmentasi.

memori tersegmentasi adalah kejadian dimana kita memiliki cukup memory secara total, tapi memori tersebut terbagi menjadi bagian bagian kecil sehingga tidak bisa dipakai sebagai satu kesatuan.

setiap pemanggilan malloc() harus dipasangkan dnegan pemanggilan free(). free() digunakan untuk membebaskan memori yang telah di alokasikan.

jika kita tidak membebaskan memori yang kita alokasikan setelah kita selesai menggunakan memori tersebut memori kita akan penuh dan program kita akan crash.

=============================================================================================================

aturan operator . dan ->
-Jika Anda memiliki variabel struct itu sendiri, gunakan operator titik (.).
-Jika Anda memiliki sebuah pointer ke struct, gunakan operator panah (->).
