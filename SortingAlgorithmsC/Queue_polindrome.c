#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    return queue->back == MAX_SIZE - 1;
}

void enqueue(Queue *queue, int newItem)
{
    if (isFull(queue))
    {
        printf("Queue is FULL\n");
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

void displayQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is EMPTY\n");
        return;
    }
    
    for (int i = queue->front; i <= queue->back; i++)
    {
        printf("%d ", queue->elements[i]);
    }
    printf("\n");
}

bool isPalindrome(Queue *queue)
{
    if (isEmpty(queue))
    {
        return false;
    }
    
    int start = queue->front;
    int end = queue->back;
    while (start < end)
    {
        if (queue->elements[start] != queue->elements[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main()
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    initializeQueue(queue);
    
    int n, value;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) 
    {
        printf("Enter element: ");
        scanf("%d", &value);
        enqueue(queue, value);
    }
    
    printf("Queue contents: ");
    displayQueue(queue);
    
    if (isPalindrome(queue)) 
    {
        printf("The queue is a palindrome.\n");
    } 
    else 
    {
        printf("The queue is not a palindrome.\n");
    }
    
    free(queue);
    return 0;
}
