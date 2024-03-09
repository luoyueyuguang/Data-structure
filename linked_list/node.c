#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void show_link(Node* l)
{
    printf("%d\n", l -> data);
    while(l->next != NULL)
    {
        l = l -> next;
        printf("%d\n", l -> data);
    }
}

void tail_insert(Node** l, Node* a)
{
    Node* temp = *l; 
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = a;
}

void head_insert(Node** l, Node* b)
{
    b -> next = *l;
    *l = b; 
}

void any_insert(Node**l, Node* c, int index)
{
    if(index == 0){
        head_insert(l, c);
    }
    Node* temp = *l;
    for(int i = 0; i < index - 1 && temp != NULL; i++){
        temp = temp -> next;
    }
    c -> next = temp -> next;
    temp -> next = c;
}

void delete(Node** l, int index)
{

    Node* temp = *l;
    if(index == 0){
        *l = (*l) -> next;
        free(temp);
        return;
    }
    for(int i = 0; i < index - 1 && temp != NULL; i++){
        temp = temp -> next;
    }
    Node* temp1 = temp -> next;
    temp -> next = temp1 -> next;
    free(temp1);
}

int main()
{
    Node* A = (Node*)malloc(sizeof(Node));
    A -> next = NULL;
    A -> data = 2;
    show_link(A);

    printf("tail insert\n");
    Node* a = (Node*)malloc(sizeof(Node));
    a -> next = NULL;
    a -> data = 3;
    tail_insert(&A, a);
    show_link(A);

    printf("head insert\n");
    Node* b = (Node*)malloc(sizeof(Node));
    b -> next = NULL;
    b -> data = 1;
    head_insert(&A, b);
    show_link(A);

    printf("any insert\n");
    Node* c = (Node*)malloc(sizeof(Node));
    c -> next = NULL;
    c -> data = 4;
    Node* d = (Node*)malloc(sizeof(Node));
    d -> next = NULL;
    d -> data = 5;
    any_insert(&A, c, 1);
    any_insert(&A, d, 3);
    show_link(A);

    printf("delete\n");
    delete(&A, 0);
    show_link(A);
    printf("delete2\n");
    delete(&A, 2);
    show_link(A);
}

