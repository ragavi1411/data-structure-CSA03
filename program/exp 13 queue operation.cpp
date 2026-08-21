#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if(rear == MAX-1)
        printf("Queue Full\n");
    else {
        if(front == -1) front = 0;
        queue[++rear] = x;
    }
}

void dequeue() {
    if(front == -1 || front > rear)
        printf("Queue Empty\n");
    else
        printf("Deleted: %d\n", queue[front++]);
}

void display() {
    int i;
    if(front == -1 || front > rear)
        printf("Queue Empty\n");
    else {
        printf("Queue: ");
        for(i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();
    dequeue();
    display();

    return 0;
}
