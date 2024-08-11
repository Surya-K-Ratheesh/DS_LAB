#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int precedence(char ch) {
    switch (ch) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void push(char ch) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = ch;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        return '\0';
    }
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

void reverse(char *str) { // In-place string reversal
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

void infixToPrefix(char *infix, char *prefix) {
    reverse(infix); // Reverse infix to treat it like a postfix expression
    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) { // Operand
            prefix[j++] = ch;
        } else if (ch == ')') {
            push(ch);
        } else if (ch == '(') {
            while ((ch = pop()) != ')' && ch != '\0') {
                prefix[j++] = ch;
            }
        } else if (isOperator(ch)) {
            while (!isEmpty() && precedence(ch) < precedence(stack[top])) {
                prefix[j++] = pop();
            }
            push(ch);
        }
    }

    while (!isEmpty()) { // Pop remaining operators
        prefix[j++] = pop();
    }
    prefix[j] = '\0'; // Null terminate the prefix expression
    reverse(prefix); // Reverse back to obtain the actual prefix expression
}

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}