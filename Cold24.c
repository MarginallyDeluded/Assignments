#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
int precedence(char c) {
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return -1;
}

int main() {
    char infix[MAX], postfix[MAX];
    int k = 0;
    printf("Enter Infix: ");
    scanf("%s", infix);

    for(int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if(isalnum(ch)) {
            postfix[k++] = ch;
        }
        else if(ch == '(') {
            push(ch);
        }
        else if(ch == ')') {
            while(top != -1 && stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        else {
            while(top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    while(top != -1) postfix[k++] = pop();
    postfix[k] = '\0';

    printf("Postfix: %s\n", postfix);
    return 0;
}
