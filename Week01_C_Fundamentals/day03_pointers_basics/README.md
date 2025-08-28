## pretest

1. Jika Anda memiliki int var = 42; dan kemudian Anda menulis int _p_var = &var;. Apa tipe data dari p_var dan apa nilai yang disimpannya?
   Jawaban 1: "tipenya int dan nilai yang disimpan adalah alamat dari var"
   Evaluasi: Hampir sempurna. Tipe data p_var secara teknis adalah "pointer ke int" atau int _. Nilai yang disimpannya benar sekali, yaitu alamat memori dari var.

2. Dengan variabel yang sama di atas, manakah dari ekspresi C berikut yang akan menghasilkan kembali nilai 42: p*var, &var, \_p_var, atau &p_var?
   Jawaban 2: "p_var"
   Evaluasi: Tepat. Operator * (dereference) adalah cara untuk "mengambil nilai" dari alamat yang ditunjuk oleh pointer.

3. Rencana Anda menyebutkan bahwa menginisialisasi pointer ke NULL adalah praktik yang baik. Menurut Anda, mengapa ini penting? Bahaya apa yang coba kita hindari?
   Jawaban 3: "karena pointer berisi alamat suatu variabel jika kita salah memasukan nilai bisa jadi kita salah mengakses suatu alamat. dengan mengisikan null kita menghindari supaya pointer diberi nilai yang tidak jelas oleh kompiler"
   Evaluasi: Sangat Tepat. Penjelasan Anda luar biasa. Pointer yang tidak diinisialisasi (disebut juga wild pointer) akan berisi alamat "sampah" yang acak. Mencoba mengakses atau menulis ke alamat acak tersebut adalah salah satu bug paling berbahaya dalam C. Dengan menginisialisasi ke NULL, kita memberinya nilai yang aman dan kita bisa dengan mudah memeriksa (if (pointer != NULL)) apakah pointer tersebut sudah menunjuk ke alamat yang valid sebelum digunakan.

===========================================
pass-by-value

memberikan variable ke sebuah fungsi dengan menyalin isi dari variabel tersebut dan memasukannya ke fungsi bukan memasukan langsung variable kedalam fungsi.

===========================================
pass_by_reference

memberikan alamat variabel kedalam fungsi dan memerintahkan fungsi untuk mengakses nilai variabel yang ada pada alamat tersebut.

===========================================
pointer dapat kita gunakan untuk mengakses nilai dari array. dengan melakukan aritmatika pada pointer yang merujuk ke suatu array kita sama saja sedang merekayasa elemen array mana yang ingin kamu tunjuk.

pointer yang menunjuk suatu array akan menunjuk alamat dari elemen array ke 0, jika kita menambah pointer dengan 1, maka dengan itu kita menunjuk alamat dari elemen array ke 1. pada pointer_and_arrays.c saya mengakses sebuah array int, dari sudut pandang memory, ketika pointer ditambah dengan 1 itu artinya saya menunjuk 4 blok (bytes) setelah alamat array awal. hal ini karena pada perangkat ini int memiliki ukuran 4 bytes.

- berdasarkan program pointer_and_arrays.c :
  data_log: Dianggap sebagai alamat dari elemen pertama.
- data_log[1]: Dianggap sebagai nilai dari elemen kedua.
- &data_log[1]: Dianggap sebagai alamat dari elemen kedua.

==============================================
percobaan const pada pointer

- case 1: const int \* p_nilai
  Apa yang Konstan: Nilai yang ditunjuk oleh pointer adalah konstan. Anda tidak bisa mengubah nilai variabel melalui pointer ini. Jika Anda mencoba \*p_nilai = 50;, Anda akan mendapatkan error kompilasi.

  Apa yang Boleh Diubah: Anda bebas mengubah alamat yang disimpan di pointer. Seperti yang Anda buktikan di kode, p_nilai = &object2; berjalan dengan baik. Anda juga bisa mengubah nilai variabel object1 secara langsung (object1 = 30;), tetapi tidak melalui \*p_nilai.

- case 2: int \* const p_nilai
  Apa yang Konstan: Alamat yang disimpan di pointer adalah konstan. Setelah diinisialisasi (= &object1;), Anda tidak bisa lagi mengubah p_nilai untuk menunjuk ke alamat lain. Inilah sebabnya p_nilai = &object2; memberikan Anda error.

  Apa yang Boleh Diubah: Anda bebas mengubah nilai yang ditunjuk oleh pointer. Jika Anda menambahkan baris \*p_nilai = 50;, kode tersebut akan berjalan dengan baik.

- case 3: const int \* const p_nilai
  Apa yang Konstan: Semuanya konstan. Baik alamat yang disimpan di pointer maupun nilai yang ditunjuk oleh pointer tidak bisa diubah melalui pointer ini.

  Apa yang Boleh Diubah: Tidak ada. Anda akan mendapatkan error jika mencoba p_nilai = &object2; dan juga akan mendapatkan error jika mencoba \*p_nilai = 50;.

trik untuk membaca deklarasi ini adalah dengan membacanya dari kanan ke kiri:

- int _ const p_nilai; -> p_nilai adalah const (konstan) _ (pointer) ke int. Jadi, pointernya yang konstan.
- const int _ p_nilai; -> p_nilai adalah _ (pointer) ke int yang const (konstan). Jadi, integernya yang konstan.
