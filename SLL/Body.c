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

Antrian* buatPointerAntrian(){
	
	Antrian* temp = (Antrian*) malloc(sizeof(Antrian)); 
	temp->tambah = Nil;
	temp->first = Nil;
	temp->jumlahAntrian = 0;
	return temp;
	
}

void insertNewPointerAntrian(){
	
	if(dataAntrian == Nil){
		dataAntrian = buatPointerAntrian();
		dataPeminjam = buatPointerAntrian();
		return;
	}
	
	Antrian* temp1;
	Antrian* temp2;
	temp1 = dataAntrian;
	temp2 = dataPeminjam;
	while(temp1->tambah != Nil && temp2->tambah != Nil){
		temp1 = temp1->tambah;
		temp2 = temp2->tambah;
	}
	
	temp1->tambah = buatPointerAntrian();
	temp2->tambah = buatPointerAntrian();
	
}

void tambahBuku(Buku** head, char judul[], int jumlah){

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
		history.peminjam = buatNodeBuku(judul, jumlah);
		insertNewPointerAntrian();
		printf("Buku %s telah ditambahkan dalam daftar\n", judul);
		return;
	}

	Buku* temp = *head;
	Buku* tempHistory = history.peminjam;
	
	while(temp->after != Nil){
		temp = temp->after;
		tempHistory = tempHistory->after;
	}
	
	temp->after = buatNodeBuku(judul, jumlah);
	tempHistory->after = buatNodeBuku(judul, jumlah);
	insertNewPointerAntrian();
	printf("Buku %s telah ditambahkan dalam daftar\n", judul);

}

bool isEmptyBuku(Buku* temp){
	return temp == Nil;
}

Buku* getPosisiBuku(Buku* headTemp, int urutan){

	int i = 1;
	while(i < urutan && headTemp != Nil){
		headTemp = headTemp->after;
		i++;
	}
	return headTemp;
	
}

Antrian* getPosisiAntrian(Antrian* tempAntrian, int urutan){

	int i = 1;
	while(i < urutan && tempAntrian != Nil){
		tempAntrian = tempAntrian->tambah;
		i++;
	}
	return tempAntrian;

}

address buatNodeAntrian(infotype anggota, int prioritas){

	address newNode = (address) malloc(sizeof(ElmtList));
	strcpy(newNode->info, anggota);
	newNode->prioritas = prioritas;
	newNode->next = Nil;
	return newNode;

}

void pinjam(Buku* head, int urutan, infotype anggota, int prioritas){
	
	Antrian* selectedAntrian = getPosisiAntrian(dataAntrian, urutan);
	address newNode = buatNodeAntrian(anggota, prioritas);

	if(selectedAntrian == Nil) {
		printf("Antrian tidak ditemukan!\n");
		return;
	}

	// Jika antrian kosong
	if(selectedAntrian->first == Nil){
		newNode->buku = getPosisiBuku(head, urutan);
		selectedAntrian->first = newNode;
		selectedAntrian->jumlahAntrian = 1;
		printf("%s telah berhasil dimasukkan ke dalam antrian\n", anggota);
		return;
	}
	
	
	// Sisipkan sebelum node dengan prioritas sama/lebih besar
	address prev = NULL;
	address curr = selectedAntrian->first;
	
	if(selectedAntrian->jumlahAntrian == 1){
		if(curr->prioritas < prioritas){
			newNode->buku = curr->buku;
			curr->next = newNode;
			selectedAntrian->jumlahAntrian += 1;
		}else{
			newNode->next = curr;
			selectedAntrian->first = newNode;
			selectedAntrian->jumlahAntrian += 1;
		}
		printf("%s telah berhasil dimasukkan ke dalam antrian\n", anggota);
		printf("Jumlah Antrian sekarang : %d\n", selectedAntrian->jumlahAntrian);
		
		return;
	}
	
	int count = 1;
	while(count < selectedAntrian->jumlahAntrian && curr->prioritas < prioritas) {
		prev = curr;
		curr = curr->next;
		count++;
	}
	
	// Sisipkan node baru
	if(prev == NULL){
		// Masukkan di awal
		newNode->next = selectedAntrian->first;
		selectedAntrian->first = newNode;
	} else {
		if(count == selectedAntrian->jumlahAntrian){
			if(curr->prioritas < prioritas){
				newNode->buku = curr->buku;
				curr->next = newNode;
			}else{
				newNode->next = curr;
				prev->next = newNode;
			}
		}else{
			newNode->next = curr;
			prev->next = newNode;
		}
	}
	selectedAntrian->jumlahAntrian += 1;
	printf("%s telah berhasil dimasukkan ke dalam antrian\n", anggota);
	printf("Jumlah Antrian sekarang : %d\n", selectedAntrian->jumlahAntrian);
}

void insertPeminjam(Buku* head, int urutan, infotype anggota, int prioritas){
	
	Antrian* selectedPeminjam = getPosisiAntrian(dataAntrian, urutan);
	address newNode = buatNodeAntrian(anggota, prioritas);
	
	if(selectedPeminjam->first == Nil){
		selectedPeminjam->first = newNode;
		newNode->buku = getPosisiBuku(head, urutan);
		selectedPeminjam->jumlahAntrian += 1;
		return;
	}
	
	insertFirst(&(selectedPeminjam->first), anggota, prioritas);
	selectedPeminjam->jumlahAntrian += 1;

}

void proses(Buku* headTemp, int urutan){
	
	Buku* selectedBook = getPosisiBuku(headTemp, urutan);
	Antrian* selectedAntrian = getPosisiAntrian(dataAntrian, urutan);
	Antrian* selectedPeminjam = getPosisiAntrian(dataPeminjam, urutan);
	
	if(selectedAntrian->first == Nil){
		printf("Tidak ada antrian pada buku %s untuk diproses\n", selectedBook->judul);
		return;
	}	
	
	address newNode; 
	
	while(selectedBook->jumlah > 0 && selectedAntrian->jumlahAntrian > 0){	
		if(selectedAntrian->jumlahAntrian == 1){
			newNode = buatNodeAntrian(selectedAntrian->first->info, selectedAntrian->first->prioritas);
			if(selectedPeminjam->first == Nil){
				newNode->buku = getPosisiBuku(headTemp, urutan);
				selectedPeminjam->first = newNode;
			}else{
				newNode->next = selectedPeminjam->first;
				selectedPeminjam->first = newNode;
			}
			printf("Buku diberikan kepada %s\n", selectedAntrian->first->info);
			free(selectedAntrian->first);
			selectedAntrian->first = Nil;
			selectedBook->jumlah -= 1;
			selectedAntrian->jumlahAntrian -= 1;
			selectedPeminjam->jumlahAntrian += 1;
			return;
		}
		int count = 1;
		address temp = selectedAntrian->first;
		address prev = Nil;
		while(count < selectedAntrian->jumlahAntrian){
			prev = temp;
			temp = temp->next;
			count++;
		}
		newNode = buatNodeAntrian(temp->info, temp->prioritas);
		if(selectedPeminjam->first == Nil){
			newNode->buku = getPosisiBuku(headTemp, urutan);
			selectedPeminjam->first = newNode;
		}else{
			newNode->next = selectedPeminjam->first;
			selectedPeminjam->first = newNode;
		}
		
		printf("Buku diberikan kepada %s\n", temp->info);
		prev->buku = temp->buku;
		free(temp);
		
		selectedBook->jumlah -= 1;
		selectedAntrian->jumlahAntrian -= 1;
		selectedPeminjam->jumlahAntrian += 1;
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
	
	Buku* selectedBook = getPosisiBuku(buku, urutanBuku);
	Antrian* selectedPeminjam = getPosisiAntrian(dataPeminjam, urutanBuku);

	if(selectedPeminjam->first == Nil){
		printf("Tidak ada peminjam\n");
		return;
	}
	
	address peminjam = getPosisiPeminjam(selectedPeminjam->first, urutanOrang);
	printf("buku dikembalikan oleh %s\n", peminjam->info);
	
	if(selectedPeminjam->jumlahAntrian == 1){
		free(peminjam);
		selectedPeminjam->first = Nil;
	}else{
		int count = 1;
		address	curr = selectedPeminjam->first;
		address prev = Nil;
		while(count < urutanOrang && count < selectedPeminjam->jumlahAntrian){
			prev = curr;
			curr->next;
			count++;
		}
		
		if(count = 1){
			selectedPeminjam->first = curr->next;
			free(curr);
		}else if(count < selectedPeminjam->jumlahAntrian){
			deleteBetween(&(selectedPeminjam->first), curr);
		}else{
			prev->buku = curr->buku;
			free(curr);
		}
	}
	selectedPeminjam->jumlahAntrian -= 1;
	selectedBook->jumlah += 1;
	
}

void printAllNode(Buku* head, Antrian* temp){
	
	if(temp == Nil){
		printf("Tidak ada buku\n");
		return;
	}
	
	int i = 1;
	address firstTemp;
	while(temp != Nil){
		Buku* selectedBook = getPosisiBuku(head, i);
		int j = 1;
		firstTemp = temp->first;
		if(firstTemp == Nil){
			printf("Kosong -> ");
			printf("[%d. %s]", i, selectedBook->judul);
			
		}else{
			while(j <= temp->jumlahAntrian){
				printf("%d. [%s] -> ", j, firstTemp->info);
				if(j < temp->jumlahAntrian){
					firstTemp = firstTemp->next;
				}
				j++;
			}
			printf("[%d. %s]", i, firstTemp->buku->judul);
		}
		
		temp = temp->tambah;
		printf("\n");
		i++;
	}
	
}

void hapusAntrian(Antrian* temp){
	
	if(temp == Nil){
		return;
	}
	
	Antrian* prev;
	while(temp != Nil){
		keluar(&(temp->first), temp->jumlahAntrian);
		prev = temp;
		temp = temp->tambah;
		free(prev);
	}
	
}

void hapusBuku(Buku** head){
	
	if(*head == Nil){
		printf("Tidak ada buku\n");
		return;
	}
	
	Buku* delete;
	while(*head != Nil){
		delete = *head;
		*head = (*head)->after;
		free(delete);
	}		
	
}

void keluar(address* first, int jumlahBuku){
	
	int count = 1;
	address prev;
	if(jumlahBuku == 1){
		free(*first);
		return;
	}
	
	while(count <= jumlahBuku){
		address prev = *first;
		if(count < jumlahBuku){
			*first = (*first)->next;
		}
		free(prev);
		count++;
	}
}

