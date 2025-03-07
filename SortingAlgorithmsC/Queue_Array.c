#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_SIZE 50

typedef struct
{
    int elements[MAX_SIZE];
    int front;
    int back;
} Queue;

void initializeQueue(Queue *queue)
{
    queue->back = -1;
    queue->front = -1;
}

bool isEmpty(Queue *queue)
{
    return queue->back == -1 && queue->front == -1;
}

bool isFull(Queue *queue)
{
    return queue->back == MAX_SIZE -1;
}

void enqueue(Queue *queue, int newItem)
{
    if (isFull(queue))
    {
        printf("Queue is FULL: \n");
        return;
    }
    if (isEmpty(queue))
    {
        queue->front = 0;
    }
    queue->back++;
    queue->elements[queue->back] = newItem;
    printf("Enqueued: %d\n", newItem);
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is EMPTY: \n");
        exit(EXIT_FAILURE);
    }
    int removedValue = queue->elements[queue->front];
    if (queue->back == queue->front)
    {
        queue->back = -1;
        queue->front = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    printf("Dequeued: %d\n", removedValue);
    return removedValue;
}

int peek(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is EMPTY: \n");
        exit(EXIT_FAILURE);
    }
    return queue->elements[queue->front];
}

void displayQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is EMPTY: \n");
        return;
    }
    int i = queue->front;
    printf("Queue elements: ");
    while (i != queue->back)
    {
        printf("%d ", queue->elements[i]);
        i = i + 1;
    }
    printf("%d \n", queue->elements[i]);
}

int main()
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    initializeQueue(queue);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    displayQueue(queue);

    printf("Front element: %d \n", peek(queue));

    dequeue(queue);

    displayQueue(queue);

    printf("Front element: %d \n", peek(queue));

    free(queue);
    return 0;
}