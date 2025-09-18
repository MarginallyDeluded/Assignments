#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char *str) {
    strcpy(stack[++top], str);
}

char* pop() {
    return stack[top--];
}

int main() {
    char postfix[MAX], ch;
    printf("Enter Postfix: ");
    scanf("%s", postfix);

    for (int i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];
        if (isalnum(ch)) {
            char op[2] = {ch, '\0'};
            push(op);
        } else {
            char op1[MAX], op2[MAX], expr[MAX];
            strcpy(op1, pop());
            strcpy(op2, pop());
            sprintf(expr, "%c%s%s", ch, op2, op1);
            push(expr);
        }
    }

    printf("Prefix: %s\n", stack[top]);
    return 0;
}
