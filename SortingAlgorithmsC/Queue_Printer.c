#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 50

typedef struct {
    char documents[MAX_SIZE][100];
    int front, back;
} PrinterQueue;

void InitializeQueue(PrinterQueue *queue)
{
    queue->front = -1;
    queue->back = -1;
}

bool IsEmpty(PrinterQueue *queue)
{
    return queue->back == -1 && queue->front == -1;
}

bool IsFull(PrinterQueue *queue)
{
    return queue->back == MAX_SIZE - 1;
}

void AddDocument(PrinterQueue *queue, char *document)
{
    if (IsFull(queue))
    {
        printf("Printer queue is FULL\n");
        return;
    }
    if (IsEmpty(queue))
    {
        queue->front = 0;
    }
    queue->back++;
    strcpy(queue->documents[queue->back], document);
    printf("Added document: %s\n", document);
}

void PrintDocument(PrinterQueue *queue)
{
    if (IsEmpty(queue))
    {
        printf("Printer queue is EMPTY\n");
        return;
    }
    printf("Printing document: %s\n", queue->documents[queue->front]);
    if (queue->front == queue->back)
    {
        queue->front = -1;
        queue->back = -1;
    }
    else
    {
        queue->front++;
    }
}

void DisplayQueue(PrinterQueue *queue)
{
    if (IsEmpty(queue))
    {
        printf("Printer queue is EMPTY\n");
        return;
    }
    printf("Current Printer Queue:\n");
    for (int i = queue->front; i <= queue->back; i++)
    {
        printf("%s\n", queue->documents[i]);
    }
}

int main()
{
    PrinterQueue *queue = (PrinterQueue*)malloc(sizeof(PrinterQueue));
    InitializeQueue(queue);
    
    AddDocument(queue, "report.pdf");
    AddDocument(queue, "thesis.docx");
    DisplayQueue(queue);
    
    PrintDocument(queue);
    DisplayQueue(queue);
    
    PrintDocument(queue);
    DisplayQueue(queue);

    free(queue);
    
    return 0;
}
