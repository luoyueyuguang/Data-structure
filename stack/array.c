#include <stdio.h>
#include <stdlib.h>

typedef struct stack{ 
    int *arr;
    int top;
    int size;
    void (*push)(struct stack *, int);
    int (*pop)(struct stack *);
} stack;

void push(stack *s, int data) {
    if (s->top == s->size - 1) {
        int *temp = (int *)malloc(2 * s->size * sizeof(int));
        for (int i = 0; i < s->size; i++) {
            temp[i] = s->arr[i];
        }
        free(s->arr);
        s->arr = temp;
        s->size *= 2;
    }
    s->arr[++s->top] = data;
}

int pop(stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

void display(stack *s) {
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    stack s;
    s.size = 2;
    s.top = -1;
    s.push = push;
    s.pop = pop;
    s.arr = (int *)malloc(s.size * sizeof(int));
    s.push(&s, 1);
    s.push(&s, 2);
    s.push(&s, 3);
    display(&s);
    printf("%d\n", s.pop(&s));
    display(&s);
}
    
