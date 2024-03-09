#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void head_insert(int x, Node** l)
{
    Node* nnode = createNode(x);
    if(*l == NULL) {
        *l = nnode;
        return;
    }
    (*l) -> prev = nnode;
    nnode -> next = *l;
    *l = nnode;
}

void tail_insert(int x, Node** l)
{
    Node* nnode = createNode(x);
    if(*l == NULL) {
        *l = nnode;
        return;
    }
    Node* temp = *l;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nnode;
    nnode->prev = temp;
}

void show(Node* l)
{
    while(l != NULL) {
        printf("%d\n", l->data);
        l = l->next;
    }
}

void show_reverse(Node* l)
{
    if(l == NULL) {
        return;
    }
    while(l->next != NULL) {
        l = l->next;
    }
    while(l != NULL) {
        printf("%d\n", l->data);
        l = l->prev;
    }
}    

int main(){
    Node* a = createNode(1);
    head_insert(2, &a);
    tail_insert(3, &a);
    show(a);
    printf("\n");
    show_reverse(a);
}
    
