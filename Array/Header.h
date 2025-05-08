#include "LinkedList.h"

// Prosedur untuk menginisialisasi array buku
void init(Buku** array);
// I.S. array buku telah dialokasikan
// F.S. semua elemen array diinisialisasi dengan nilai Nil

// Fungsi untuk membuat node buku baru
Buku* buatNodeBuku(char judul[], int jumlah);
// I.S. judul dan jumlah buku sudah disiapkan
// F.S. mengembalikan pointer ke node buku baru yang sudah diinisialisasi

// Fungsi untuk memeriksa validitas judul buku (belum ada di daftar)
bool isValidBuku(Buku** array, char judul[]);
// I.S. array buku dan judul buku yang akan dicek sudah disiapkan
// F.S. mengembalikan true jika judul buku belum ada dalam array, false jika sudah ada

// Prosedur untuk menambahkan buku baru ke dalam array
void tambahBuku(Buku** array, Buku** peminjam, char judul[], int jumlah);
// I.S. array buku, array peminjam, judul dan jumlah buku sudah disiapkan
// F.S. buku baru ditambahkan ke array jika judul valid dan array belum penuh

// Fungsi untuk memeriksa apakah antrian peminjam buku kosong
bool isEmptyBuku(Buku* temp);
// I.S. pointer ke node buku sudah terdefinisi
// F.S. mengembalikan true jika antrian peminjam kosong, false jika tidak

// Fungsi untuk membuat node antrian peminjam baru
address buatNodeAntrian(infotype anggota, int prioritas);
// I.S. informasi anggota dan nilai prioritas sudah disiapkan
// F.S. mengembalikan pointer ke node antrian baru yang sudah diinisialisasi

// Prosedur untuk menambahkan peminjam ke dalam antrian sesuai prioritas
void pinjam(Buku* selectedBook, infotype anggota, int prioritas);
// I.S. pointer ke buku yang dipilih, informasi anggota, dan prioritas sudah disiapkan
// F.S. anggota ditambahkan ke dalam antrian peminjam sesuai dengan nilai prioritasnya

// Prosedur untuk memproses antrian peminjaman buku
void proses(Buku* selectedBook, Buku* selectedBookPeminjam);
// I.S. pointer ke buku yang dipilih dan pointer ke buku peminjam sudah terdefinisi
// F.S. buku diberikan kepada peminjam dalam antrian sesuai prioritas dan stok yang tersedia

// Fungsi untuk mendapatkan posisi peminjam berdasarkan urutan
address getPosisiPeminjam(address firstTemp, int urutan);
// I.S. pointer ke awal linked list dan urutan peminjam sudah disiapkan
// F.S. mengembalikan pointer ke node peminjam pada urutan yang ditentukan

// Prosedur untuk mengembalikan buku yang dipinjam
void kembalikan(Buku* selectedBook, Buku* selectedBookHistory, int urutanOrang);
// I.S. pointer ke buku yang dipilih, pointer ke riwayat peminjaman, dan urutan orang sudah disiapkan
// F.S. buku dikembalikan dan stok buku ditambah, peminjam dihapus dari daftar peminjaman

// Prosedur untuk menampilkan semua buku beserta antrian peminjamnya
void printAllNode(Buku** array);
// I.S. array buku sudah terdefinisi
// F.S. semua buku beserta antrian peminjamnya ditampilkan

// Prosedur untuk menghapus semua antrian buku
void hapusAntrian(Buku** array);
// I.S. array buku sudah terdefinisi
// F.S. semua antrian pada tiap buku dihapus dan memori dibebaskan

// Prosedur untuk menghapus semua node dalam satu antrian buku
void keluar(address* first);
// I.S. pointer ke awal linked list sudah terdefinisi
// F.S. semua node dalam linked list dihapus dan memori dibebaskan
