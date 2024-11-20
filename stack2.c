#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;



void push(char c) {
    if(top == MAX - 1) {
        printf("Stack overflow!\n");
    }
    
    stack[++top] = c;
}

char pop() {
    if(top == -1) {
        printf("Stack Underflow!\n");
    }

    return stack[top--];
}

char peek() {
    if(top == -1) {
        return '\0';
    }

    return stack[top];
}

int isValid(char str[]) {
   for(int i = 0; str[i] != '\0'; i++) {
    if( str[i] == '(' || str[i] == '[' || str[i] == '{') {
        push(str[i]);
    }
    else if(top != -1 && (str[i] == ')' || str[i] == ']' || str[i] == '}')) {
        if(peek() == '(' && str[i] != ')') return 0;
        if(peek() == '[' && str[i] != ']') return 0;
        if(peek() == '{' && str[i] != '}') return 0;
        pop();
    }
   } 
    if(top == -1) {
        return 1;
    } else {
        return 0;
    }

}


int main() {

    if(isValid("()()()")) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }
    return 0;
}