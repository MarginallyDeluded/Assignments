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
    char prefix[MAX], ch;
    printf("Enter Prefix: ");
    scanf("%s", prefix);

    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        ch = prefix[i];
        if (isalnum(ch)) {
            char op[2] = {ch, '\0'};
            push(op);
        } else {
            char op1[MAX], op2[MAX], expr[MAX];
            strcpy(op1, pop());
            strcpy(op2, pop());
            sprintf(expr, "(%s%c%s)", op1, ch, op2);
            push(expr);
        }
    }

    printf("Infix: %s\n", stack[top]);
    return 0;
}
