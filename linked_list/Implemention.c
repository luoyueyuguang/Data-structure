//
// Created by luoyue on 2023/8/17.
//
#include <stdio.h>
#include <stdlib.h>
typedef int e_type;
typedef struct Node Node;
struct Node{
    e_type data;
    struct Node* next;
};
void Insert(Node** head, e_type x)
{
    struct Node *temp = (Node *)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> next = NULL;
    if(*head != NULL) temp -> next = *head;
    *head = temp;
}
void Print(Node* head)//打印列表
{

    while(head != NULL)
    {
        printf("%d", head -> data);
        head = head->next;
    }
}
int main()
{
    struct Node* head = NULL;
    int n, i;
    e_type x;
    scanf_s("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf_s("%d", &x);
        Insert(&head, x);
        Print(head);
    }
}

/*
void Insert(Node** head, int x)
{
    Node* temp = (Node*) malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> next = NULL;
    if(*head != NULL) temp -> next = *head;
    *head = temp;
}
 */