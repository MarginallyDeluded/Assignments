#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    char data[MAX];
    int top;
} Stack;

void init(Stack *s) { s->top = -1; }
int isEmpty(Stack *s) { return s->top == -1; }
int isFull(Stack *s) { return s->top == MAX-1; }
void push(Stack *s, char c) {
    if (!isFull(s)) s->data[++(s->top)] = c;
}
char pop(Stack *s) {
    if (isEmpty(s)) return '\0';
    return s->data[(s->top)--];
}
char peek(Stack *s) {
    if (isEmpty(s)) return '\0';
    return s->data[s->top];
}

int isOpening(char c) {
    return c == '(' || c == '{' || c == '[';
}
int isClosing(char c) {
    return c == ')' || c == '}' || c == ']';
}
int matches(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(const char *expr) {
    Stack s;
    init(&s);
    for (size_t i = 0; expr[i] != '\0'; ++i) {
        char c = expr[i];
        if (isOpening(c)) {
            push(&s, c);
        } else if (isClosing(c)) {
            if (isEmpty(&s)) return 0;       // closing without opening
            char op = pop(&s);
            if (!matches(op, c)) return 0;  // mismatched types
        }
        // ignore other characters
    }
    return isEmpty(&s); // true if no unmatched openings left
}

int main(void) {
    char input[1024];

    printf("Enter expression: ");
    if (!fgets(input, sizeof(input), stdin)) return 0;
    // remove trailing newline
    input[strcspn(input, "\n")] = '\0';

    if (isBalanced(input)) printf("Balanced\n");
    else printf("Not Balanced\n");

    return 0;
}
