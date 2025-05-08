#include "Header.h"

void init(Buku** head){

	if(*head != Nil){
		*head = Nil;
	}

}


Buku* buatNodeBuku(char judul[], int jumlah){

	Buku* temp = (Buku*) malloc(sizeof(Buku));
	strcpy(temp->judul, judul);
	temp->jumlah = jumlah;
	temp->first = Nil;
	temp->after = Nil;
	return temp;

}

bool isFull(Buku* temp){

	int i = 1;
	if(temp == Nil){
		return false;
	}
	while(temp->after != Nil){
		temp = temp->after;
		i++;
	} 
	return (i == N);

}

bool isValidBuku(Buku* temp, char judul[]){
	
	while(temp != Nil){
		if(strcmp(temp->judul, judul) == 0){
			return false;
		}
		temp = temp->after;
	}
	return true;	

}

void tambahBuku(Buku** head, Undo* undo, char judul[], int jumlah){

	if(isFull(*head)){
		printf("Tidak menambahkan buku baru karena sudah penuh\n");
		return;
	}
	
	if(!isValidBuku(*head, judul)){
		printf("Tidak bisa menambahkan buku %s karena sudah ada dalam daftar\n", judul);
		return;
	}
	
	if(*head == Nil){
		*head = buatNodeBuku(judul, jumlah);
		undo->top = buatNodeBuku(judul, jumlah);
		history.peminjam = buatNodeBuku(judul, jumlah);
		printf("Buku %s telah ditambahkan dalam daftar\n", judul);
		return;
	}

	Buku* temp = *head;
	Buku* tempundo = undo->top;
	Buku* tempHistory = history.peminjam;
	
	while(temp->after != Nil){
		temp = temp->after;
		tempundo = tempundo->after;
		tempHistory = tempHistory->after;
	}
	
	temp->after = buatNodeBuku(judul, jumlah);
	tempundo->after = buatNodeBuku(judul, jumlah);
	tempHistory->after = buatNodeBuku(judul, jumlah);
	printf("Buku %s telah ditambahkan dalam daftar\n", judul);

}

bool isEmptyBuku(Buku* temp){
	
	return temp->first == Nil? true : false;

}

Buku* getPosisiBuku(Buku* headTemp, int urutan){

	int i = 1;
	while(i < urutan && headTemp != Nil){
		headTemp = headTemp->after;
		i++;
	}
	return headTemp;
	

}

address buatNodeAntrian(infotype anggota, int prioritas){

	address newNode = (address) malloc(sizeof(ElmtList));
	strcpy(newNode->info, anggota);
	newNode->prioritas = prioritas;
	newNode->next = Nil;
	return newNode;

}

void pinjam(Buku* head, Undo* undo, int urutan, infotype anggota, int prioritas){
	
	Buku* headTemp = getPosisiBuku(head, urutan);
	Buku* topundo = getPosisiBuku(undo->top, urutan);
	address newNode = buatNodeAntrian(anggota, prioritas);
	
	if(headTemp->first  == Nil || prioritas > headTemp->first->prioritas){
		newNode->next = headTemp->first;
		headTemp->first = newNode;
		insertFirst(&(topundo->first), anggota, prioritas);
		printf("%s telah berhasil dimasukkan ke dalam antrian\n", anggota);
		return;
	}
	
	address temp = headTemp->first;
	while(temp->next != Nil && temp->next->prioritas >= prioritas){
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	insertFirst(&(topundo->first), anggota, prioritas);
	printf("%s telah berhasil dimasukkan ke dalam antrian\n", anggota);
	
}

void proses(Buku* headTemp, int urutan){
	
	Buku* selectedBook = getPosisiBuku(headTemp, urutan);
	Buku* selectedBookHistory = getPosisiBuku(history.peminjam, urutan);
	
	if(selectedBook->first == Nil){
		printf("Tidak ada antrian pada buku %s untuk diproses\n", selectedBook->judul);
		return;
	}
	
	while(selectedBook->jumlah > 0 && selectedBook->first != Nil){
		printf("Buku diberikan kepada %s\n", selectedBook->first->info);
		insertFirst(&(selectedBookHistory->first), selectedBook->first->info, selectedBook->first->prioritas);
		deleteFirst(&(selectedBook->first));
		selectedBook->jumlah -= 1;
	}	
	if(selectedBook->jumlah == 0){
		printf("Stok buku %s kosong. Harap menunggu buku tersebut dikembalikan\n", selectedBook->judul);
	}
	
	
}
address getPosisiPeminjam(address firstTemp, int urutan){

	int i = 1;
	while(i < urutan && firstTemp != Nil){
		firstTemp = firstTemp->next;
		i++;
	}
	return firstTemp;

}

void kembalikan(Buku* buku, int urutanBuku, int urutanOrang){
	
	Buku* selectedBook= getPosisiBuku(buku, urutanBuku);
	Buku* selectedBookHistory = getPosisiBuku(history.peminjam, urutanBuku);

	if(isEmptyBuku(selectedBookHistory)){
		printf("Tidak ada peminjam\n");
		return;
	}
	
	address peminjam = getPosisiPeminjam(selectedBookHistory->first, urutanOrang);
	printf("buku dikembalikan oleh %s\n", peminjam->info);
	selectedBook->jumlah += 1;
	printf("berhasil");
	deleteBetween(&(selectedBookHistory->first), peminjam);
	
}

void printAllNode(Buku* temp){
	
	if(temp == Nil){
		printf("Tidak ada buku\n");
		return;
	}
	int i = 1;
	address firstTemp;
	while(temp != Nil){
		int j = 1;
		printf("%d. ", i);
		printf("%s -> ", temp->judul);
		if(temp != Nil){
			firstTemp = temp->first;
			while(firstTemp != Nil){
				printf("%d. [%s] -> ", j, firstTemp->info);
				firstTemp = firstTemp->next;
				j++;
			}
		}
		temp = temp->after;
		printf("\n");
		i++;
	}
	
}

void hapusAntrian(Buku** head){
	
	if(*head == Nil){
		printf("Tidak ada buku\n");
		return;
	}
	
	Buku* delete;
	while(*head != Nil){
		keluar(&((*head)->first));
		delete = *head;
		*head = (*head)->after;
		free(delete);
	}
	
}

void keluar(address* first){
	
	while(*first != Nil){
		deleteLast(first);
	}

}

