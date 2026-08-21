#include <stdio.h>
#include <ctype.h>

char stack[50];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int priority(char x) {
    if(x == '+' || x == '-') return 1;
    if(x == '*' || x == '/') return 2;
    return 0;
}

int main() {
    char exp[50], *p;

    printf("Enter infix expression: ");
    scanf("%s", exp);

    printf("Postfix: ");

    for(p = exp; *p != '\0'; p++) {
        if(isalnum(*p))
            printf("%c", *p);
        else if(*p == '(')
            push(*p);
        else if(*p == ')') {
            while(stack[top] != '(')
                printf("%c", pop());
            pop();
        }
        else {
            while(top != -1 && priority(stack[top]) >= priority(*p))
                printf("%c", pop());
            push(*p);
        }
    }

    while(top != -1)
        printf("%c", pop());

    return 0;
}
