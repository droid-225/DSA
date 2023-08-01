#include <stdio.h>

#define MAX_SIZE 10
int stack[MAX_SIZE];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX_SIZE - 1;
}

void push(int val) {
    if(isFull()) {
        printf("Stack Overflow!\n");
        return 0;
    }
    stack[++top] = val;
}

int pop() {
    if(isEmpty()) {
        printf("Stack Underflow!\n");
        return 0;
    }
    return stack[top--];
}

int peep() {
    if(isEmpty()) {
        printf("Stack Empty!\n");
        return;
    }
    return stack[top];
}

void change(int index, int val) {
    stack[index] = val;
}

void display() {
    int i;
    for(i = 0; i < MAX_SIZE; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    display();
    printf("Top Element: %d\n", peep());
    printf("Popped element: %d\n", pop());
    printf("\nAfter pop:\n");
    push(5);
    change(3, 4);
    display();
    printf("Top Element: %d\n", peep());
    return 0;
}
