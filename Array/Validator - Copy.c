#include "Validator.h"
#include <ctype.h> // Untuk isdigit()

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int validateNumberInput(const char* prompt, int* valid) {
    char input[20];
    printf("%s", prompt);
    scanf("%19s", input);
    int i;
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

// Periksa apakah ada buku di dalam array
bool adaBuku(Buku* array[]) {
	int i;
    for (i = 0; i < N; i++) {
        if (array[i] != NULL) {
            return true;
        }
    }
    return false;
}

// Periksa apakah ada antrian peminjam dalam semua buku
bool adaAntrian(Buku* array[]) {
    int i;
	for (i = 0; i < N; i++) {
        if (array[i] != NULL && array[i]->first != NULL) {
            return true;
        }
    }
    return false;
}

// Periksa apakah ada peminjam di histori
bool adaPeminjam(Buku* array[]) {
	int i;
    for (i = 0; i < N; i++) {
        if (array[i] != NULL) {
        	if(array[i]->first != NULL){
        		return true;	
			}
        }
    }
    return false;
}

