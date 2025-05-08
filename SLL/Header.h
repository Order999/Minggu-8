#ifndef HEADER_H
#define HEADER_H
#include "LinkedList.h"

// Prosedur yang digunakan untuk menginisialisasi pointer awal struct Buku dengan NULL
void init(Buku** head);
// I.S. pointer baru saja dibuat dan belum diniinisialisasi dengan NULL
// F.S. pointer diisi dengan NULL

// Fungsi yang digunakan untuk membuat node buku baru
Buku* buatNodeBuku(char judul[], int jumlah);
// I.S. parameter judul dan jumlah sudah terdefinisi
// F.S. mengembalikan pointer ke node buku baru dengan judul dan jumlah yang diberikan

// Fungsi untuk memeriksa apakah jumlah buku sudah mencapai maksimum (N)
bool isFull(Buku* temp);
// I.S. pointer ke buku head sudah terdefinisi
// F.S. mengembalikan true jika jumlah buku sudah mencapai N, false jika belum

// Fungsi untuk memeriksa validitas buku (tidak ada duplikat judul)
bool isValidBuku(Buku* temp, char judul[]);
// I.S. pointer ke buku dan judul buku baru sudah terdefinisi
// F.S. mengembalikan true jika judul buku belum ada dalam daftar, false jika sudah ada

// Fungsi untuk membuat pointer antrian baru
Antrian* buatPointerAntrian();
// I.S. -
// F.S. mengembalikan pointer ke struktur Antrian baru yang sudah diinisialisasi

// Prosedur untuk menambahkan pointer antrian baru di akhir dataAntrian dan dataPeminjam
void insertNewPointerAntrian();
// I.S. pointer global dataAntrian dan dataPeminjam sudah ada
// F.S. pointer antrian baru ditambahkan di akhir dataAntrian dan dataPeminjam

// Prosedur untuk menambahkan buku baru ke dalam daftar
void tambahBuku(Buku** head, char judul[], int jumlah);
// I.S. pointer ke head buku, judul dan jumlah buku baru sudah terdefinisi
// F.S. buku baru ditambahkan ke dalam daftar jika memenuhi syarat

// Fungsi untuk memeriksa apakah daftar buku kosong
bool isEmptyBuku(Buku* temp);
// I.S. pointer ke buku sudah terdefinisi
// F.S. mengembalikan true jika daftar buku kosong, false jika tidak

// Fungsi untuk mendapatkan pointer ke buku pada urutan tertentu
Buku* getPosisiBuku(Buku* headTemp, int urutan);
// I.S. pointer ke head buku dan urutan buku yang dicari sudah terdefinisi
// F.S. mengembalikan pointer ke buku pada urutan yang diminta

// Fungsi untuk mendapatkan pointer ke antrian pada urutan tertentu
Antrian* getPosisiAntrian(Antrian* tempAntrian, int urutan);
// I.S. pointer ke antrian awal dan urutan antrian yang dicari sudah terdefinisi
// F.S. mengembalikan pointer ke antrian pada urutan yang diminta

// Fungsi untuk membuat node antrian baru
address buatNodeAntrian(infotype anggota, int prioritas);
// I.S. nama anggota dan prioritas sudah terdefinisi
// F.S. mengembalikan pointer ke node antrian baru dengan info dan prioritas yang diberikan

// Prosedur untuk menambahkan peminjam ke dalam antrian buku
void pinjam(Buku* head, int urutan, infotype anggota, int prioritas);
// I.S. pointer head buku, urutan buku, nama anggota, dan prioritas sudah terdefinisi
// F.S. anggota ditambahkan ke dalam antrian sesuai prioritas

// Prosedur untuk menambahkan peminjam ke dalam daftar peminjam buku
void insertPeminjam(Buku* head, int urutan, infotype anggota, int prioritas);
// I.S. pointer head buku, urutan buku, nama anggota, dan prioritas sudah terdefinisi
// F.S. anggota ditambahkan ke dalam daftar peminjam

// Prosedur untuk memproses antrian peminjaman buku
void proses(Buku* headTemp, int urutan);
// I.S. pointer head buku dan urutan buku yang akan diproses sudah terdefinisi
// F.S. peminjam teratas dalam antrian dipindahkan ke daftar peminjam jika stok buku tersedia

// Fungsi untuk mendapatkan posisi peminjam pada urutan tertentu
address getPosisiPeminjam(address firstTemp, int urutan);
// I.S. pointer ke node pertama peminjam dan urutan peminjam yang dicari sudah terdefinisi
// F.S. mengembalikan pointer ke peminjam pada urutan yang diminta

// Prosedur untuk mengembalikan buku yang dipinjam
void kembalikan(Buku* buku, int urutanBuku, int urutanOrang);
// I.S. pointer ke buku, urutan buku, dan urutan peminjam sudah terdefinisi
// F.S. buku dikembalikan, peminjam dihapus dari daftar peminjam, stok buku bertambah

// Prosedur untuk menampilkan semua antrian buku
void printAllNode(Buku* head, Antrian* temp);
// I.S. pointer head buku dan pointer antrian sudah terdefinisi
// F.S. daftar antrian untuk setiap buku ditampilkan

// Prosedur untuk menghapus semua antrian
void hapusAntrian(Antrian* temp);
// I.S. pointer ke antrian sudah terdefinisi
// F.S. semua node dalam antrian dihapus dan memori dibebaskan

// Prosedur untuk menghapus semua buku
void hapusBuku(Buku** head);
// I.S. pointer ke head buku sudah terdefinisi
// F.S. semua node buku dihapus dan memori dibebaskan

// Prosedur untuk menghapus semua node dalam sebuah antrian
void keluar(address* first, int jumlahBuku);
// I.S. pointer ke node pertama dan jumlah buku sudah terdefinisi
// F.S. semua node dalam antrian dihapus dan memori dibebaskan

#endif
