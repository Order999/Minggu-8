#ifndef Validator_h
#define Validator_h
#include "LinkedList.h"

// Prosedur untuk membersihkan buffer input
void clearInputBuffer();
// I.S. buffer input mungkin berisi karakter yang tidak diinginkan
// F.S. buffer input dibersihkan dari karakter yang tersisa

// Fungsi untuk memvalidasi input berupa angka
int validateNumberInput(const char* prompt, int* valid);
// I.S. prompt untuk ditampilkan dan pointer ke variabel status valid sudah disiapkan
// F.S. mengembalikan angka yang diinput jika valid, mengubah nilai *valid menjadi 1 jika input valid,
//      atau 0 jika input tidak valid dan mengembalikan -1

// Fungsi untuk memeriksa apakah ada buku dalam array
bool adaBuku(Buku* array[]);
// I.S. array buku sudah terdefinisi
// F.S. mengembalikan true jika terdapat minimal satu buku dalam array, false jika array kosong

// Fungsi untuk memeriksa apakah ada antrian peminjam dalam semua buku
bool adaAntrian(Buku* array[]);
// I.S. array buku sudah terdefinisi
// F.S. mengembalikan true jika terdapat minimal satu antrian peminjam dalam salah satu buku,
//      false jika tidak ada antrian peminjam di semua buku

// Fungsi untuk memeriksa apakah ada peminjam di dalam histori
bool adaPeminjam(Buku* array[]);
// I.S. array buku peminjam sudah terdefinisi
// F.S. mengembalikan true jika terdapat minimal satu peminjam dalam histori,
//      false jika tidak ada peminjam di semua buku
#endif
