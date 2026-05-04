#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* buatNode(int nilai){
    Node* baru = (Node*)malloc(sizeof(Node));
    baru-> data = nilai;
    baru-> next = NULL;
    return baru; 
}

void tambahBelakang(Node** head, int nilai){
    Node* baru = buatNode(nilai);
    if(*head == NULL){
        *head  = baru;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp-> next = baru;
}

Node* gabungList(Node* list1, Node* list2){
    Node* hasil = NULL;
    Node* tail = NULL;

    while (list1 != NULL && list2!= NULL){
        Node* pilih;
        if(list1-> data <= list2->data){
            pilih=list1;
            list1 = list1-> next;
        } else {
            pilih=list2;
            list2 = list2->next;
        }

        pilih->next = NULL;

        if (hasil==NULL){
            hasil = pilih;
            tail = pilih;
        } else{
            tail->next = pilih;
            tail = pilih;
        }
    }
    if  (list1 != NULL){
        if (hasil == NULL){
            hasil = list1;
        } else {
            tail -> next = list1;
        }
    }

    if (list2 != NULL){
        if (hasil == NULL){
            hasil = list2;
        } else{
            tail ->next = list2;
        }
    }
    
    return hasil;
}

void printList(Node* head){
    if (head == NULL){
        printf("MERGED EMPTY\n");
        return;
    }
    printf("MERGED");

    while (head != NULL){
        printf(" %d", head->data);
        head = head -> next;
    }
    printf("\n");
}

void hapusMemori(Node*head){
    Node* temp;

    while (head!= NULL){
        temp = head;
        head = head -> next;
        free (temp);
    }
}

int main(){
    Node* list1 = NULL;
    Node* list2 = NULL;
    Node* hasil = NULL;

    int N, M;
    int nilai;

    scanf("%d", &N);

    for (int i=0; i<N; i++){
        scanf ("%d", &nilai);
        tambahBelakang(&list1, nilai);
    }

    scanf("%d", &M);

    for (int i = 0; i<M; i++){
        scanf("%d", &nilai);
        tambahBelakang(&list2, nilai);
    }

    hasil = gabungList(list1, list2);
    printList(hasil);
    hapusMemori(hasil);
    return 0;
}
