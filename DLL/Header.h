#include "LinkedList.h"

// Prosedur untuk menginisialisasi pointer head menjadi NULL
void init(Buku** head);
// I.S. pointer head sudah terdefinisi
// F.S. pointer head menjadi NULL/Nil

// Fungsi untuk membuat node buku baru
Buku* buatNodeBuku(char judul[], int jumlah);
// I.S. judul dan jumlah buku sudah disiapkan
// F.S. mengembalikan node buku baru dengan judul dan jumlah yang diberikan

// Fungsi untuk memeriksa apakah daftar buku sudah penuh
bool isFull(Buku* temp);
// I.S. pointer temp sudah terdefinisi
// F.S. mengembalikan true jika jumlah buku sudah mencapai batas maksimum (N), false jika belum

// Fungsi untuk memeriksa validitas buku berdasarkan judul
bool isValidBuku(Buku* temp, char judul[]);
// I.S. pointer temp dan judul buku sudah terdefinisi
// F.S. mengembalikan true jika judul buku belum ada dalam daftar, false jika sudah ada

// Prosedur untuk menambahkan buku baru ke dalam daftar
void tambahBuku(Buku** head, Undo* Undo, char judul[], int jumlah);
// I.S. pointer head, struktur Undo, judul dan jumlah buku sudah terdefinisi
// F.S. buku baru ditambahkan ke dalam daftar jika memenuhi semua syarat

// Fungsi untuk memeriksa apakah antrian peminjam buku kosong
bool isEmptyBuku(Buku* temp);
// I.S. pointer temp sudah terdefinisi
// F.S. mengembalikan true jika tidak ada antrian peminjam, false jika ada

// Fungsi untuk mendapatkan pointer ke buku pada urutan tertentu
Buku* getPosisiBuku(Buku* headTemp, int urutan);
// I.S. pointer headTemp dan urutan buku sudah terdefinisi
// F.S. mengembalikan pointer ke buku pada urutan yang diminta

// Fungsi untuk membuat node antrian peminjam baru
address buatNodeAntrian(infotype anggota, int prioritas);
// I.S. data anggota dan nilai prioritas sudah disiapkan
// F.S. mengembalikan node antrian peminjam baru

// Prosedur untuk mendaftarkan peminjaman buku
void pinjam(Buku* head, Undo* undo, int urutan, infotype anggota, int prioritas);
// I.S. pointer head, struktur Undo, urutan buku, data anggota dan prioritas sudah terdefinisi
// F.S. anggota ditambahkan ke dalam antrian peminjam buku sesuai dengan prioritasnya

// Prosedur untuk memproses antrian peminjaman buku
void proses(Buku* headTemp, int urutan);
// I.S. pointer headTemp dan urutan buku sudah terdefinisi
// F.S. antrian peminjaman diproses dan jumlah buku berkurang sesuai dengan yang dipinjam

// Fungsi untuk mendapatkan pointer ke peminjam pada urutan tertentu
address getPosisiPeminjam(address firstTemp, int urutan);
// I.S. pointer firstTemp dan urutan peminjam sudah terdefinisi
// F.S. mengembalikan pointer ke peminjam pada urutan yang diminta

// Prosedur untuk memproses pengembalian buku
void kembalikan(Buku* buku, int urutanBuku, int urutanOrang);
// I.S. pointer buku, urutan buku dan urutan peminjam sudah terdefinisi
// F.S. buku dikembalikan dan jumlah buku bertambah kembali

// Prosedur untuk menampilkan semua buku dan antrian peminjamnya
void printAllNode(Buku* temp);
// I.S. pointer temp sudah terdefinisi
// F.S. semua buku dan antrian peminjamnya ditampilkan

// Prosedur untuk menghapus semua antrian buku
void hapusAntrian(Buku** head);
// I.S. pointer head sudah terdefinisi
// F.S. semua buku dan antrian peminjam dihapus, memori dibebaskan

// Prosedur untuk menghapus seluruh antrian peminjam pada suatu buku
void keluar(address* first);
// I.S. pointer first sudah terdefinisi
// F.S. semua node dalam antrian peminjam dihapus, memori dibebaskan
