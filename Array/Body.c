#include "Header.h"

void init(Buku** array){

	int i = 0;
	while(i < N){
		array[i] = Nil;
		i++;
	}

}


Buku* buatNodeBuku(char judul[], int jumlah){

	Buku* temp = (Buku*) malloc(sizeof(Buku));
	strcpy(temp->judul, judul);
	temp->jumlah = jumlah;
	temp->first = Nil;
	return temp;

}


bool isValidBuku(Buku** array, char judul[]){
	
	int i = 0;
	while(i < N){
		if(array[i] != Nil && strcmp(array[i]->judul, judul) == 0){
			return false;
		}
		i++;
	}
	return true;	

}

void tambahBuku(Buku** array, Buku** peminjam, char judul[], int jumlah){
	
	if(!isValidBuku(array, judul)){
		printf("Tidak bisa menambahkan buku %s karena sudah ada dalam daftar\n", judul);
		return;
	}
	
	int i = 0;
	while(i < N){
		if(array[i] == Nil){
			array[i] = buatNodeBuku(judul, jumlah);
			peminjam[i] = buatNodeBuku(judul, jumlah);
			printf("Buku %s telah ditambahkan dalam daftar\n", judul);
			return;
		}
		i++;
	}
	printf("Tidak bisa menambahkan buku %s, karena array sudah penuh\n", judul);

}

bool isEmptyBuku(Buku* temp){
	
	return temp->first == Nil? true : false;

}

address buatNodeAntrian(infotype anggota, int prioritas){

	address newNode = (address) malloc(sizeof(ElmtList));
	strcpy(newNode->info, anggota);
	newNode->prioritas = prioritas;
	newNode->next = Nil;
	return newNode;

}

void pinjam(Buku* selectedBook, infotype anggota, int prioritas){
	
	address newNode = buatNodeAntrian(anggota, prioritas);
	
	if(isEmptyBuku(selectedBook) || prioritas > selectedBook->first->prioritas){
		newNode->next = selectedBook->first;
		selectedBook->first = newNode;
		printf("%s telah berhasil dimasukkan ke dalam antrian\n", anggota);
		return;
	}
	
	address temp = selectedBook->first;
	while(temp->next != Nil && temp->next->prioritas >= prioritas){
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	printf("%s telah berhasil dimasukkan ke dalam antrian\n", anggota);
	
}

void proses(Buku* selectedBook, Buku* selectedBookPeminjam){
	
	if(isEmptyBuku(selectedBook)){
		printf("Tidak ada antrian pada buku %s untuk diproses\n", selectedBook->judul);
		return;
	}
	
	while(selectedBook->jumlah > 0 && !isEmptyBuku(selectedBook)){
		printf("Buku diberikan kepada %s\n", selectedBook->first->info);
		insertFirst(&(selectedBookPeminjam->first), selectedBook->first->info, selectedBook->first->prioritas);
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

void kembalikan(Buku* selectedBook, Buku* selectedBookHistory, int urutanOrang){

	if(isEmptyBuku(selectedBookHistory)){
		printf("Tidak ada peminjam\n");
		return;
	}
	
	address peminjam = getPosisiPeminjam(selectedBookHistory->first, urutanOrang);
	printf("buku dikembalikan oleh %s\n", peminjam->info);
	selectedBook->jumlah += 1;
	deleteBetween(&(selectedBookHistory->first), peminjam);
	
}

void printAllNode(Buku** array){
	 
	int container [N];
	int i = 0;
	while(i < N){
		if(array[i] != Nil){
			container[i] = 1;
			int j = 1;
			address firstTemp = array[i]->first;
			printf("%d. ", i+1);
			printf("%s -> ", array[i]->judul);
			while(firstTemp != Nil){	
				printf("%d. [%s] -> ", j, firstTemp->info);
				firstTemp = firstTemp->next;
				j++;
			}
		}
		else{
			container[i] = 0;
		}
		i++;
		printf("\n");
	}
	int x;
	int semuaKosong = 1;
    for(x = 0; x < N; x++){
        if(container[x] == 1){
            semuaKosong = 0;
            break;
		}
	}
        
	if(semuaKosong){
		printf("Tidak ada buku\n");
		return;
	}
	
}

void hapusAntrian(Buku** array){
	int container[N];
	int i = 0;
	int semuaKosong = 1;
    for(i = 0; i < N; i++){
        if(container[i] == 1){
            semuaKosong = 0;
            break;
		}
		i++;
	}
        
	if(semuaKosong){
		return;
	}
	
	i = 0;
	while(i < N){
		if(array[i] != Nil){
			keluar(&(array[i]->first));
			free(array[i]);
		}
		i++;
	}
	
}

void keluar(address* first){
	
	while(*first != Nil){
		deleteLast(first);
	}

}

