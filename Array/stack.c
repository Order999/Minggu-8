#include "stack.h"

// Prosedur yang digunakan untuk membuat node baru dengan value info sisa dari pembagian bilangan desimal dengan 2 menggunakan struktur data stack
void push(Buku* buku, infotype anggota, int prioritas){
	
	insertFirst(&(buku->first), anggota, prioritas);

}

// Prosedur yang digunakan mengolah data teratas pada struktur data stack
void pop(Buku* buku){
	
	deleteFirst(&(buku->first));
	
}
