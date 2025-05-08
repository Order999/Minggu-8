#ifndef Validator_h
#define Validator_h
#include "LinkedList.h"

// Prosedur untuk membersihkan buffer input setelah pembacaan input
void clearInputBuffer();
// I.S. buffer input mungkin masih berisi karakter sisa
// F.S. buffer input kosong dan siap menerima input baru

// Fungsi untuk memvalidasi input berupa angka
int validateNumberInput(const char* prompt, int* valid);
// I.S. prompt dan pointer valid sudah terdefinisi
// F.S. mengembalikan nilai numerik jika input valid dan mengubah *valid menjadi 1,
//      mengembalikan -1 dan mengubah *valid menjadi 0 jika input tidak valid

// Fungsi untuk memeriksa apakah ada buku dalam daftar
bool adaBuku(Buku* head);
// I.S. pointer head sudah terdefinisi
// F.S. mengembalikan true jika ada buku dalam daftar, false jika tidak ada

// Fungsi untuk memeriksa apakah ada antrian peminjam pada semua buku
bool adaAntrian(Buku* head);
// I.S. pointer head sudah terdefinisi
// F.S. mengembalikan true jika ada antrian peminjam pada setidaknya satu buku, false jika tidak ada

// Fungsi untuk memeriksa apakah ada peminjam di dalam history
bool adaPeminjam(Buku* historyHead);
// I.S. pointer historyHead sudah terdefinisi
// F.S. mengembalikan true jika ada peminjam dalam history, false jika tidak ada

#endif
