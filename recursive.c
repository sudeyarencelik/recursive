**2310206007 SUDE YAREN ÇELİK BİLGİSAYAR MÜHENDİSLİĞİ 2. ÖĞRETİM**
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void printReverse(struct Node* head) {
    if (head == NULL)
        return;
    printReverse(head->next);
    printf("%d -> ", head->data);
}


void freeList(struct Node** head) {
    if (*head == NULL)
        return;

    freeList(&(*head)->next);
    free(*head);
    *head = NULL;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}


int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printf("Sondan basa yazdirma: ");
    printReverse(head);
    printf("NULL\n");

    freeList(&head);

    if (head == NULL)
        printf("Liste tamamen silindi.\n");

    return 0;
}

