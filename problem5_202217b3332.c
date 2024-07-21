#include <stdio.h>
#include <stdlib.h>

#define n 5

void insert(int queue[], int *rear, int *x, int *j) {
    if (*rear == n) {
        printf("\nQueue is Full\n");
    } else {
        printf("\nEnter no %d: ", (*j)++);
        scanf("%d", &queue[(*rear)++]);
        (*x)--;
    }
}

void delete(int queue[], int *front, int *rear, int *x) {
    if (*front == *rear) {
        printf("\nQueue is Empty\n");
    } else {
        printf("\nDeleted Element is %d\n", queue[(*front)++]);
        (*x)++;
    }
}

void display(int queue[], int front, int rear) {
    if (front == rear) {
        printf("\nQueue is Empty\n");
    } else {
        printf("\nQueue Elements are:\n");
        for (int i = front; i < rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}

int main() {
    int queue[n], ch = 1, front = 0, rear = 0, j = 1, x = n;

    printf("Queue using Array");
    printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Exit");

    while (ch) {
        printf("\nEnter the Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert(queue, &rear, &x, &j);
                break;
            case 2:
                delete(queue, &front, &rear, &x);
                break;
            case 3:
                display(queue, front, rear);
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong Choice: please see the options\n");
        }
    }

    return 0;
}
