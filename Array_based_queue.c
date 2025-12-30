#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

/* Enqueue operation */
void enqueue() {
    int x;
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
    } else {
        printf("Enter element: ");
        scanf("%d", &x);

        if (front == -1) {   // first element
            front = 0;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = x;
    }
}

/* Dequeue operation */
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);

        if (front == rear) {   // queue becomes empty
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

/* Display operation */
void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements:\n");
        i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    int choice;

    do {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("Exit\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}