#include "Validator.h"
#include <ctype.h> // Untuk isdigit()

// Fungsi untuk membersihkan buffer input
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Fungsi untuk validasi input angka
int validateNumberInput(const char* prompt, int* valid) {
    char input[20];
    printf("%s", prompt);
    scanf("%19s", input);
    int i;
    // Cek apakah semua karakter adalah digit
    for (i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i])) {
            printf("Input tidak valid. Silakan masukkan ulang.\n");
            clearInputBuffer();
            *valid = 0;
            return -1;
        }
    }
    
    *valid = 1;
    return atoi(input);
}

// Fungsi untuk mengecek apakah ada buku yang tersedia
bool adaBuku(Buku* head) {
    return head != NULL;
}

// Fungsi untuk mengecek apakah ada antrian peminjam
bool adaAntrian(Buku* head) {
    Buku* current = head;
    while (current != NULL) {
        if (current->first != NULL) {
            return true;
        }
        current = current->after;
    }
    return false;
}

// Fungsi untuk mengecek apakah ada peminjam di history
bool adaPeminjam(Buku* historyHead) {
    if (historyHead == NULL) return false;
    
    Buku* current = historyHead;
    while (current != NULL) {
        if (current->first != NULL) {
            return true;
        }
        current = current->after;
    }
    return false;
}
