#ifndef header_h
#define header_h
#include "LinkedList.h"
#define MAX 5

// File header untuk modul logika struktur data queue

void init(Teller *teller);
bool isFull(Teller A, Teller B, Teller C);
bool isEmpty(Teller teller);
int queueLength(Teller teller);
Teller* shortestQueue(Teller *A, Teller *B, Teller *C);
void queue(Teller *A, Teller *B, Teller *C, int *antrian);
void dequeue(Teller *teller);

#endif


