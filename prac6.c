#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;

void insertAtFront(int newData) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node*));
    ptr -> data = newData;
    ptr -> next = head;
    head = ptr;
}

void insertAtEnd(int newData) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node*));
    struct Node *temp;
    ptr -> data = newData;

    if(head == NULL) {
        ptr -> next = NULL;
        head = ptr;
    }
    else {
        temp = head;
        while(temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = ptr;
        ptr -> next = NULL;
    }
}

void deleteFirst() {
    if(head == NULL)
        printf("List is Empty!");
    else
        head = head -> next;
}

void deleteBefore(int pos) {
    struct Node *curr, *prev;
    curr = head;
    int i = 0;

    if(head == NULL)
        printf("List is Empty!");
    else if(pos <= 2) {
        head = head -> next;
    }
    else {
        while(i != pos - 2 && curr -> next != NULL) {
            prev = curr;
            curr = curr -> next;
            i++;
        }
        prev -> next = curr -> next;
    }
}

void deleteAt(int pos) {
    struct Node *curr, *prev;
    curr = head;
    int i = 0;

    if(head == NULL)
        printf("List is Empty!");
    else if(pos <= 1) {
        head = head -> next;
    }
    else {
        while(i != pos - 1 && curr -> next != NULL) {
            prev = curr;
            curr = curr -> next;
            i++;
        }
        prev -> next = curr -> next;
    }
}

void display() {
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main() {
    insertAtFront(3);
    insertAtFront(2);
    insertAtFront(1);
    insertAtEnd(4);
    insertAtEnd(5);
    display();
    deleteFirst();
    display();
    deleteBefore(3);
    display();
    deleteAt(1);
    display();

    return 0;
}