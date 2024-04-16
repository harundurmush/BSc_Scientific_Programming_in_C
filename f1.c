#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct Node_std {
    int L_id;
    char L_Name[N];
    char L_Surname[N];
    struct Node_std* next;
} Node_std;

Node_std* insert_and_sort(Node_std* head, int id, char name[], char surname[]);
void printlist(Node_std* head);

int main()
{
    int i;
    int id[N];
    char* Name[N];
    char* Surname[N];
    Node_std* headOF = NULL;

    id[0] = 220206048, Name[0] = "CELIL", Surname[0] = "ATAS";
    id[1] = 230206037, Name[1] = "HAKAN", Surname[1] = "KARA";
    id[2] = 220206032, Name[2] = "ENES", Surname[2] = "MUTLUER";
    id[3] = 230206002, Name[3] = "NIHAL", Surname[3] = "PARLAK";
    id[4] = 240206010, Name[4] = "ZUBEYDE", Surname[4] = "ULUOZ";
    id[5] = 220206012, Name[5] = "MEHMET", Surname[5] = "OKKA";
    id[6] = 230206056, Name[6] = "CEMIL", Surname[6] = "DEMIR";
    id[7] = 230206011, Name[7] = "ELIF", Surname[7] = "GENCER";
    id[8] = 240206011, Name[8] = "MEHMET", Surname[8] = "KOTTAS";
    id[9] = 240206001, Name[9] = "ZELIHA", Surname[9] = "ULUOZ";

    for (i = 0; i < N; i++) {
        headOF = insert_and_sort(headOF, id[i], Name[i], Surname[i]);
    }

    printlist(headOF);

    Node_std* current = headOF;
    while (current != NULL) {
        Node_std* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

Node_std* insert_and_sort(Node_std* head, int id, char name[], char surname[]) {
    Node_std* new_node = (Node_std*)malloc(sizeof(Node_std));
    new_node->L_id = id;
    strcpy(new_node->L_Name, name);
    strcpy(new_node->L_Surname, surname);
    new_node->next = NULL;

    if (head == NULL || id < head->L_id) {
        new_node->next = head;
        return new_node;
    }

    Node_std* current = head;
    while (current->next != NULL && current->next->L_id < id) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;

    return head;
}

void printlist(Node_std* head) {
    Node_std* current = head;
    while (current != NULL) {
        printf("%d - %s %s\n", current->L_id, current->L_Name, current->L_Surname);
        current = current->next;
    }
}
