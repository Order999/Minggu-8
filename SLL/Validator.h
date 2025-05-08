#ifndef Validator_h
#define Validator_h
#include "LinkedList.h"

// Prosedur untuk membersihkan buffer input
void clearInputBuffer();
// I.S. buffer input mungkin mengandung karakter yang belum dibaca
// F.S. buffer input dibersihkan dari semua karakter yang tersisa

// Fungsi untuk validasi input angka
int validateNumberInput(const char* prompt, int* valid);
// I.S. pesan prompt dan pointer valid sudah terdefinisi
// F.S. mengembalikan input user sebagai integer jika valid, mengubah *valid menjadi 1 jika input valid atau 0 jika tidak valid

// Fungsi untuk mengecek apakah ada buku dalam daftar
bool adaBuku(Buku* head);
// I.S. pointer head buku sudah terdefinisi
// F.S. mengembalikan true jika ada minimal satu buku dalam daftar, false jika kosong

// Fungsi untuk mengecek apakah ada antrian peminjam
bool adaAntrian();
// I.S. pointer global dataAntrian sudah terdefinisi
// F.S. mengembalikan true jika ada minimal satu antrian peminjam, false jika kosong

// Fungsi untuk mengecek apakah ada peminjam dalam history
bool adaPeminjam();
// I.S. pointer global dataPeminjam sudah terdefinisi
// F.S. mengembalikan true jika ada minimal satu peminjam dalam history, false jika kosong

#endif
