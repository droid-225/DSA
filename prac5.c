#include <stdio.h>

#define MAX_SIZE 5
int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int item) {
    if(front == -1 && rear == -1) { // if queue is empty
        front = 0;
        rear = 0;
        queue[rear] = item;
    }
    else if((rear + 1) % MAX_SIZE == front) { // if queue is full
        printf("Overflow!\n");
    }
    else {
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = item;
    }
}

void dequeue() {
    if(front == -1 && rear == -1) { // if queue is empty
        printf("Underflow!\n");
    }
    else if(front == rear) {
        printf("Dequeued Element: %d\n", queue[front]);
        front = -1;
        rear = -1;
    }
    else {
        printf("Dequeued Element: %d\n", queue[front]);
        front = (front + 1) % MAX_SIZE;
    }
}

void display() {
    int i = front;
    if(front == -1 && rear == -1) 
        printf("Queue is empty!\n");
    else {
        while(i <= rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX_SIZE;
        }
    }
}

int main() {
    int x = 0;
    int item;

    while(x != 4) {
        printf("\n");
        printf("1) Enqueue\n");
        printf("2) Dequeue\n");
        printf("3) Display\n");
        printf("4) Quit\n");
        scanf("%d", &x);

        switch(x) {
            case 1: 
                printf("Enter Item to Insert: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                printf("\n");
                break;
            case 4:
                printf("Goodbye!");
                break;
            default: 
                printf("Invalid Entry!");
                break;
        } 
    }

    return 0;
}