#ifndef Linkedlist_h
#define Linkedlist_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define info(P) (P)->info
#define next(P) (P)->next
#define first(P) (P).first
#define Nil NULL
#define N 5

typedef char infotype [20];
typedef struct tElmtlist *address;
typedef struct tElmtlist {
    infotype info;
    int prioritas;
    address next;
} ElmtList;

// Definisi struct buku untuk menyimpan informasi buku dan antrian peminjamnya
typedef struct Buku{
	char judul[10];
	int jumlah;
	address first;
}Buku;

// Definisi struct untuk menyimpan informasi untuk operasi undo
typedef struct{
	Buku* top;
}Undo;

// Definisi struct untuk menyimpan riwayat peminjaman
typedef struct{
	Buku* peminjam;
}History;
	
// Prosedur untuk menyisipkan node baru di awal linked list
void insertFirst(address *First, infotype anggota, int value);
// I.S. pointer First sudah terdefinisi, anggota dan nilai prioritas sudah disiapkan
// F.S. node baru ditambahkan di awal linked list

// Prosedur untuk menyisipkan node baru di akhir linked list
void insertLast(address *First, infotype anggota, int value);
// I.S. pointer First sudah terdefinisi, anggota dan nilai prioritas sudah disiapkan
// F.S. node baru ditambahkan di akhir linked list

// Prosedur untuk menghapus node pertama dari linked list
void deleteFirst(address *First);
// I.S. pointer First sudah terdefinisi dan linked list tidak kosong
// F.S. node pertama dihapus dari linked list dan memori dibebaskan

// Prosedur untuk menghapus node terakhir dari linked list
void deleteLast(address *First);
// I.S. pointer First sudah terdefinisi dan linked list tidak kosong
// F.S. node terakhir dihapus dari linked list dan memori dibebaskan

// Prosedur untuk menghapus node tertentu di tengah linked list
void deleteBetween(address* First, address selectedNode);
// I.S. pointer First dan node yang akan dihapus sudah terdefinisi
// F.S. node yang ditunjuk dihapus dari linked list dan memori dibebaskan

// Prosedur untuk menampilkan semua node dalam linked list
void printSemuaNode(address First);
// I.S. pointer First sudah terdefinisi
// F.S. semua elemen dalam linked list ditampilkan

#endif
