#include "LinkedList.h"

void insertFirst(address *First, infotype anggota, int value){
	
	address P = (address) malloc(sizeof(ElmtList));
    strcpy(P->info, anggota);
    P->prioritas = value;
    next(P) = *First;
    *First = P;
    
}

void insertLast(address *First, infotype anggota, int value){
	address P = (address) malloc(sizeof(ElmtList));
	strcpy(info(P), anggota);
	P->prioritas = value;
    next(P) = Nil;
    
    if(*First == Nil){
    	*First = P;
	}else{
		address temp = *First;
		while(next(temp) != Nil){
			temp = next(temp); 
		}
		next(temp) = P;
	}
}

void deleteFirst(address *First){
	if(*First != Nil){
		address temp = next(*First);
		free(*First);
		*First = temp;
	}
}

void deleteLast(address *First){
	if(*First == Nil){
		return;
	}
	
	address temp = *First;
	if(next(*First) == Nil){
		free(*First);
		*First = Nil;
	}else{
		while (next(next(temp)) != Nil) {
            temp = next(temp);
        }

        free(next(temp));
        next(temp) = Nil;
	}
}

void deleteBetween(address* First, address selectedNode){
	if((*First) == selectedNode){
		(*First) = selectedNode->next;
		free(selectedNode);
		return;
	}

	address temp = *First;
	while(temp->next != selectedNode){
		temp = temp->next;
	}
	temp->next = selectedNode->next;
	free(selectedNode);
}

void printSemuaNode(address First){
    if (First == Nil) {
        printf("Kosong\n");
        return;
    }

    printf("{");
    address temp = First;
    printf("%s", info(temp));
    temp = next(temp);
    while (temp != Nil) {
        printf(", %s", info(temp));
        temp = next(temp);
    }
    printf("}\n");
}

