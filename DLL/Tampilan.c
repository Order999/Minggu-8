#include "Tampilan.h"

void tampilanMenu23(Buku* headTemp){

    if(headTemp == Nil){
        printf("Tidak ada buku\n");
        return;
    }
    
    int i = 1;
    while(headTemp != Nil){
        printf("%d. %s\n", i, headTemp->judul);
        headTemp = headTemp->after;
        i++;
    }

}


