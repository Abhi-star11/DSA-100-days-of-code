#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void enqueue(int queue[], int *front, int *rear) {
    int val;
    if (*rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter value to enqueue: ");
    scanf("%d", &val);
    if (*front == -1) *front = 0;
    queue[++(*rear)] = val;
    printf("%d enqueued successfully\n", val);
}

void dequeue(int queue[], int *front, int *rear) {
    if (*front == -1 || *front > *rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d dequeued from queue\n", queue[(*front)++]);
    if (*front > *rear) {
        *front = -1;
        *rear = -1;
    }
}

void peek(int queue[], int front) {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

void display(int queue[], int front, int rear) {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue (front to rear): ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void search(int queue[], int front, int rear) {
    int val, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &val);
    for (int i = front; i <= rear; i++) {
        if (queue[i] == val) {
            printf("%d found at position %d from front\n", val, i - front + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("%d not found in queue\n", val);
    }
}

void sortQueue(int queue[], int front, int rear) {
    int i, j, temp;
    for (i = front; i <= rear; i++) {
        for (j = i + 1; j <= rear; j++) {
            if (queue[i] > queue[j]) {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
    printf("Queue sorted in ascending order\n");
    display(queue, front, rear);
}

void size(int front, int rear) {
    if (front == -1)
        printf("Size of queue: 0\n");
    else
        printf("Size of queue: %d\n", rear - front + 1);
}

void isEmpty(int front) {
    if (front == -1)
        printf("Queue is Empty\n");
    else
        printf("Queue is Not Empty\n");
}

void isFull(int rear) {
    if (rear == MAX - 1)
        printf("Queue is Full\n");
    else
        printf("Queue is Not Full\n");
}

void frontElement(int queue[], int front) {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

void rearElement(int queue[], int front, int rear) {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Rear element: %d\n", queue[rear]);
}

int main() {
    int queue[MAX];
    int front = -1, rear = -1;
    int choice;

    printf("  Queue Created Using Array\n");
    printf("  Max Size : %d\n", MAX);
    printf("  Front = %d, Rear = %d\n", front, rear);
    printf("  Queue is Ready to Use!\n");


    while (1) {
        printf("\n===== QUEUE USING ARRAY =====\n");
        printf("1.  Enqueue\n");
        printf("2.  Dequeue\n");
        printf("3.  Peek (Front Element)\n");
        printf("4.  Display\n");
        printf("5.  Search\n");
        printf("6.  Sort\n");
        printf("7.  Size\n");
        printf("8.  Is Empty?\n");
        printf("9.  Is Full?\n");
        printf("10. Front Element\n");
        printf("11. Rear Element\n");
        printf("0.  Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  enqueue(queue, &front, &rear); break;
            case 2:  dequeue(queue, &front, &rear); break;
            case 3:  peek(queue, front); break;
            case 4:  display(queue, front, rear); break;
            case 5:  search(queue, front, rear); break;
            case 6:  sortQueue(queue, front, rear); break;
            case 7:  size(front, rear); break;
            case 8:  isEmpty(front); break;
            case 9:  isFull(rear); break;
            case 10: frontElement(queue, front); break;
            case 11: rearElement(queue, front, rear); break;
            case 0:  printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
