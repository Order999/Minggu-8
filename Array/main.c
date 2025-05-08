#include "LinkedList.h"

int main(int argc, char *argv[]) {
	// Array bertipe pointer of struct Buku untuk menyimpan data antrian
    Buku* buku[N];
    
    // Array bertipe pointer of struct Buku untuk menyimpan data peminjam
    Buku* peminjam[N];
    
	init(buku); init(peminjam);
    int choice;

    do {
        system("cls");
        printf("===Menu===\n");
        printf("1. Tambah Buku\n");
        printf("2. Pinjam\n");
        printf("3. Proses\n");
        printf("4. Kembalikan\n");
        printf("5. Keluar\n");
        printf("Antrian saat ini:\n");
        printAllNode(buku);
        printf("\nMasukkan Pilihan : ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: {
                system("cls");
                char judul[20];
                int jumlah;
                int valid = 0;
                
                // Input judul buku
                printf("Masukkan judul buku: ");
                clearInputBuffer();
                fgets(judul, sizeof(judul), stdin);
                judul[strcspn(judul, "\n")] = '\0'; // Hapus newline
                
                // Validasi input jumlah
                do {
                    jumlah = validateNumberInput("Jumlah: ", &valid);
                    if (!valid) {
                        continue; // Ulangi input jumlah
                    }
                } while (!valid);
                
                tambahBuku(buku, peminjam, judul, jumlah);
                break;
            }
            case 2: {
                system("cls");
                
                if (!adaBuku(buku)) {
                    printf("Tidak ada buku\n");
                    break;
                }
                
                int pilihan, prioritas;
                char nama[20];
                int valid = 0;
                
                printAllNode(buku);
                
                // Validasi nomor buku
                do {
                    pilihan = validateNumberInput("Masukkan nomor buku yang ingin dipinjam: ", &valid);
                    if (!valid) continue;
                    
                    if (pilihan < 1 || pilihan > N-1 || buku[pilihan-1] == Nil) {
                        printf("Nomor buku tidak valid. Silakan masukkan ulang.\n");
                        valid = 0;
                    }
                } while (!valid);
                
                // Input nama
                printf("Masukkan nama peminjam: ");
                clearInputBuffer();
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = '\0';
                
                // Validasi prioritas
                do {
                    prioritas = validateNumberInput("1. Masyarakat Umum\n2. Mahasiswa\n3. Dosen\nMasukkan prioritas: ", &valid);
                    if (!valid) continue;

                    if(prioritas < 1 || prioritas > 3){
                        printf("Pilihan tidak valid. Silakan masukkan ulang.\n");
                        valid = 0;
                    }
                } while (!valid);
                
                pinjam(buku[pilihan-1], nama, prioritas);
                break;
            }
            case 3: {
                system("cls");
                
                if (!adaBuku(buku)) {
                    printf("Tidak ada antrian untuk diproses\n");
                    break;
                }
                
                if (!adaAntrian(buku)) {
                    printf("Tidak ada antrian untuk diproses\n");
                    break;
                }
                
                int pilihan;
                int valid = 0;
                
                printAllNode(buku);
                
                // Validasi nomor buku
                do {
                    pilihan = validateNumberInput("Masukkan nomor buku yang ingin diproses: ", &valid);
                    if (!valid) continue;
                    
                    if (pilihan < 1 || pilihan > N-1 || buku[pilihan-1] == Nil) {
                        printf("Nomor buku tidak valid. Silakan masukkan ulang.\n");
                        valid = 0;
                    }
                } while (!valid);
                
                proses(buku[pilihan-1], peminjam[pilihan-1]);
                break;
            }
            case 4: {
                system("cls");
                
                if (!adaPeminjam(peminjam)){
                    printf("Tidak ada peminjam\n");
                    break;
                }
                
                int pilihanBuku, pilihanOrang;
                int valid = 0;
                
                printAllNode(peminjam);
                
                // Validasi nomor buku
                do {
                    pilihanBuku = validateNumberInput("Masukkan nomor buku yang ingin dikembalikan: ", &valid);
                    if (!valid) continue;
                    
                    // Cek apakah nomor buku valid
                    if (pilihanBuku < 1 || pilihanBuku > N-1 || peminjam[pilihanBuku-1] == Nil) {
                        printf("Nomor buku tidak valid. Silakan masukkan ulang.\n");
                        valid = 0;
                    }
                } while (!valid);
                
                // Validasi nomor orang
                do {
                    pilihanOrang = validateNumberInput("Masukkan nomor peminjam buku: ", &valid);
                    if (!valid) continue;
                    
                    // Cek apakah nomor orang valid
                    address currentBook = peminjam[pilihanBuku-1]->first;
                    int personCount = 0;
                    while (currentBook != NULL) {
                        personCount++;
                        currentBook = currentBook->next;
                        
                    }
                    if (pilihanOrang < 1 || pilihanOrang > personCount) {
                        printf("Nomor peminjam tidak valid. Silakan masukkan ulang.\n");
                        valid = 0;
                    }
                } while (!valid);
                
                kembalikan(buku[pilihanBuku-1], peminjam[pilihanBuku-1], pilihanOrang);
                break;
            }
            case 5: {
                hapusAntrian(buku);
                hapusAntrian(peminjam);
                break;
            }
            default:
                printf("Pilihan tidak valid");
        }
        if(choice != 5){
        	printf("\nTekan enter untuk melanjutkan...");
	        while(getchar() != '\n'); // Membersihkan buffer input
	    	getchar();
		}
    } while(choice != 5);
    
    return 0;
}
 
