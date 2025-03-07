#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct 
{
    char customers[MAX_SIZE][50];
    int front, back;
} Queue;

void InitializeQueue(Queue *queue) 
{
    queue->front = queue->back = -1;
}

int IsEmpty(Queue *queue) 
{
    return queue->front == -1;
}

int IsFull(Queue *queue) 
{
    return queue->back == MAX_SIZE - 1;
}

void Enqueue(Queue *queue, char *name) 
{
    if (IsFull(queue)) 
    {
        printf("Queue is full!\n");
        return;
    }
    if (IsEmpty(queue)) 
    {
        queue->front = 0;
    }
    queue->back++;
    strcpy(queue->customers[queue->back], name);
    printf("Customer added: %s\n", name);
}

void Dequeue(Queue *queue) 
{
    if (IsEmpty(queue)) 
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Customer served: %s\n", queue->customers[queue->front]);
    if (queue->front == queue->back) 
    {
        queue->front = queue->back = -1;
    } 
    else 
    {
        queue->front++;
    }
}

void ViewFront(Queue *queue) 
{
    if (IsEmpty(queue)) 
    {
        printf("Queue is empty!\n");
    } 
    else 
    {
        printf("Current customer: %s\n", queue->customers[queue->front]);
    }
}

int main() 
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    InitializeQueue(queue);
    
    Enqueue(queue, "Ivan");
    Enqueue(queue, "Maria");
    ViewFront(queue);
    Dequeue(queue);
    ViewFront(queue);
    Dequeue(queue);
    ViewFront(queue);

    free(queue);
    
    return 0;
}
