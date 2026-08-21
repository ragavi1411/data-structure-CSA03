#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push(int x) {
    if(top == MAX-1)
        printf("Stack Overflow\n");
    else
        stack[++top] = x;
}

void pop() {
    if(top == -1)
        printf("Stack Underflow\n");
    else
        printf("Popped: %d\n", stack[top--]);
}

void peek() {
    if(top == -1)
        printf("Stack Empty\n");
    else
        printf("Top: %d\n", stack[top]);
}

int main() {
    push(10);
    push(20);
    push(30);

    peek();
    pop();
    peek();

    return 0;
}
