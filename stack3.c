#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
int stack[MAX];
int top = -1;

void push(char c) {
    if(top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    } 
    stack[++top] = c;
}

int pop() {
    if(top == -1) {
        printf("Stack Underflow!\n");
    }
    return stack[top--];
}

int peek() {
    if(top == -1) {
        return -1;
    }

    return stack[top];
}

void decode(char *str, char *result) {
    int size = strlen(str);
    int curr = 1;
    int j = 0; // result string index

    for(int i = 0; i < size; i++) {
        push(curr);
        curr++;

        if(i == size || str[i] == 'I') {
            while(top != -1) {
                result[j++] = pop() + '0';
            }
        }
    }

    result[j++] = '\0';
}


int main() {

    char str[MAX] = "IIDDIDID";
    char result[MAX];
    decode(str,result);
    printf("OUTPUT : %s\n",result);

    return 0;
}

// Sequence: IIDDIDID
// Output: 125437698
