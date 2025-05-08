#include "header.h"

// File body untuk logika struktur data queue

// Prosedur untuk menginisialisasi Teller->first dengan Nil
void init(address* p){
	*p = Nil;
}

// Function untuk mengecek apakah antrian teller sudah penuh
bool isFull(Teller A, Teller B, Teller C){
	return (queueLength(A) == MAX && queueLength(B) == MAX && queueLength(C) == MAX);
}

// Function untuk mengecek apakah antrian teller kosong
bool isEmpty(Teller teller){
	return (first(teller) == Nil);
}

// Function untuk mengecek jumlah antrian teller
int queueLength(Teller teller){
	int length = 0;
	while(first(teller) != Nil){
		length ++;
		first(teller) = next(first(teller));
	}
	return length;
}

// Function untuk mengecek teller mana yang memiliki antrian paling sedikit
Teller* shortestQueue(Teller *A, Teller *B, Teller *C){
    int lenA = queueLength(*A);
    int lenB = queueLength(*B);
    int lenC = queueLength(*C);
    
    if (lenA <= lenB && lenA <= lenC) {
    	return A;
	}else if (lenB <= lenA && lenB <= lenC){
		return B;
	}else{
		return C;
	}
}

// Prosedur untuk memasukkan antrian ke paling belakang
void queue(Teller *A, Teller *B, Teller *C, int *antrian){
	if (isFull(*A, *B, *C)){
        printf("Semua teller sedang penuh!\n");
        return;
    }
    Teller *shortest = shortestQueue(A, B, C);
    char tellerName;
    
    if (shortest == A){
    	tellerName = 'A';
	}else if (shortest == B){
		tellerName = 'B';
	}else{
		tellerName = 'C';
	} 
	
    insertLast(&(first(*shortest)), *antrian);
    printf("Antrian nomor %d telah ditambahkan ke Teller %c", *antrian, tellerName);
	*antrian = *antrian + 1; 
}

// Prosedut untuk memproses antrian dari paling depan
void dequeue(Teller *teller){
	if(isEmpty(*teller)){
		printf("Tidak ada antrian\n");
		return;
	}
	deleteFirst(&(first(*teller)));
	printf("Antrian berhasil diproses\n");
}

