#include "LinkedList.h"

int main(int argc, char *argv[]) {
    Buku* head;
    init(&head); init(&(history.peminjam));
    dataAntrian = Nil; dataPeminjam = Nil;
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
        printAllNode(head, dataAntrian);
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
                
                tambahBuku(&head, judul, jumlah);
                break;
            }
            case 2: {
                system("cls");
                if (!adaBuku(head)) {
                    printf("Tidak ada buku\n");
                    break;
                }
                
                int pilihan, prioritas;
                char nama[20];
                int valid = 0;
                
                printAllNode(head, dataAntrian);
                
                // Validasi nomor buku
                do {
                    pilihan = validateNumberInput("Masukkan nomor buku yang ingin dipinjam: ", &valid);
                    if (!valid) continue;
                    
                    // Cek apakah nomor buku valid
                    Buku* current = head;
                    int count = 0;
                    while (current != NULL) {
                        count++;
                        current = current->after;
                    }
                    
                    if (pilihan < 1 || pilihan > count) {
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
                
                pinjam(head, pilihan, nama, prioritas);
                break;
            }
            case 3: {
                system("cls");
                
                if (!adaBuku(head)) {
                    printf("Tidak ada antrian untuk diproses\n");
                    break;
                }
                
                if (!adaAntrian()) {
                    printf("Tidak ada antrian untuk diproses\n");
                    break;
                }
                
                int pilihan;
                int valid = 0;
                
                printAllNode(head, dataAntrian);
                
                // Validasi nomor buku
                do {
                    pilihan = validateNumberInput("Masukkan nomor buku yang ingin diproses: ", &valid);
                    if (!valid) continue;
                    
                    // Cek apakah nomor buku valid
                    Buku* current = head;
                    int count = 0;
                    while (current != NULL) {
                        count++;
                        current = current->after;
                    }
                    
                    if (pilihan < 1 || pilihan > count) {
                        printf("Nomor buku tidak valid. Silakan masukkan ulang.\n");
                        valid = 0;
                    }
                } while (!valid);
                
                proses(head, pilihan);
                break;
            }
            case 4: {
                system("cls");
                
                if (!adaPeminjam(history.peminjam)) {
                    printf("Tidak ada peminjam\n");
                    break;
                }
                
                int pilihanBuku, pilihanOrang;
                int valid = 0;
                
                printAllNode(head, dataPeminjam);
                
                // Validasi nomor buku
                do {
                    pilihanBuku = validateNumberInput("Masukkan nomor buku yang ingin dikembalikan: ", &valid);
                    if (!valid) continue;
                    
                    // Cek apakah nomor buku valid
                    Buku* currentBook = history.peminjam;
                    int bookCount = 0;
                    while (currentBook != NULL) {
                        bookCount++;
                        currentBook = currentBook->after;
                    }
                    
                    if (pilihanBuku < 1 || pilihanBuku > bookCount) {
                        printf("Nomor buku tidak valid. Silakan masukkan ulang.\n");
                        valid = 0;
                    }
                } while (!valid);
                
                // Validasi nomor orang
                do {
                    pilihanOrang = validateNumberInput("Masukkan nomor peminjam buku: ", &valid);
                    if (!valid) continue;
                    
                    Antrian* selectedPeminjam = getPosisiAntrian(dataPeminjam, pilihanBuku);
                    if (pilihanOrang < 1 || pilihanOrang > selectedPeminjam->jumlahAntrian) {
                        printf("Nomor peminjam tidak valid. Silakan masukkan ulang.\n");
                        valid = 0;
                    }
                } while (!valid);
                
                kembalikan(head, pilihanBuku, pilihanOrang);
                break;
            }
            case 5: {
                hapusAntrian(dataAntrian); hapusAntrian(dataPeminjam);
                hapusBuku(&head); hapusBuku(&(history.peminjam));
                break;
            }
            default:
                printf("Pilihan tidak valid");
        }
        printf("\nTekan enter untuk melanjutkan...");
        while(getchar() != '\n'); // Membersihkan buffer input
    	getchar();

    } while(choice != 5);
    
    return 0;
}
