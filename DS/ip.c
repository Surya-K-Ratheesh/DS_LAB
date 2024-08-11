#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void reverse(char *str);
void push(char ch);
void pop();
int isEmpty();
int isOperator(char ch);
int precedence(char ch);
void infixtoprefix(char *infix, char *prefix);


int main(){
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    printf("ENTER AN INFIX EXPRESSION: ");
    fegts(infix, MAX_SIZE, stdin);

    infixtoprefix(infix, prefix);

    printf("\nPREFIX EXPRESSION: %s\n",prefix);

    return 0;
}

void reverse(char *str){
    int len = strlen(str);

    for(int i = 0; i < len/2; i++){
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

void push(char ch){
    if(top == MAX_SIZE -1){
        printf("\nOVERFLOW: STACK IS FULL\n");
        return;
    }
    stack[++top] = ch;
}

void pop(){
    if(top == -1){
        printf("\nUNDERFLOW: STACK IS EMPTY\n");
        return '\0';
    }
    return stack[top--];
}

int isEmpty(){
    return top == -1;
}

int isOperator(char ch){
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int precedence(char ch){
    switch (ch){
        case '^' : 
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

void infixtoprefix(char *infix, char *prefix){
    // reverse(infix);

    // int i = 0, j = 0;
    // char ch;

    // while((ch = infix[i++]) != '\0'){
    //     if(isalnum(ch)){
    //         prefix[j++] = ch;
    //     }

    //     else if(ch == '('){
    //         while((ch = pop()) != ')' && ch != '\0'){
    //             prefix[j++] = ch;
    //         }
    //     }

    //     else if (ch == ')'){
    //         push(ch);
    //     }

    //     else if(isOperator(ch)){
    //         while(!isEmpty() && precedence(ch) < precedence(stack[top])){
    //             prefix[j++] = pop();
    //         }
    //         push(ch);
    //     }
    // }

    // while(!isEmpty()){
    //     prefix[j++] = pop();
    // }
    // prefix = '\0';
    // reverse(prefix);

    reverse(infix);

    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            prefix[j++] = ch;
        } else if (ch == '(') {
            while ((ch = pop()) != ')' && ch != '\0') {
                prefix[j++] = ch;
            }
        } else if (ch == ')') {
            push(ch);
        } else if (isOperator(ch)) {
            while (!isEmpty() && precedence(ch) < precedence(stack[top])) {
                prefix[j++] = pop();
            }
            push(ch);
        }
    }

    while (!isEmpty()) {
        prefix[j++] = pop();
    }
    prefix[j] = '\0'; // Add null terminator at the end
    reverse(prefix);
}