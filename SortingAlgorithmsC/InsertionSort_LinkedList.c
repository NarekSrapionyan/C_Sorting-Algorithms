// Sort a linked list using Insertion Sort.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertAtBegin(struct Node **start_ref, int data)
{
    struct Node *ptr1 = (struct Node*)malloc(sizeof(struct Node));
    ptr1 -> data = data;
    ptr1 -> next = *start_ref;
    *start_ref = ptr1;
}

void printList(struct Node *start)
{
    struct Node *temp = start;
    printf("\n");
    
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

struct Node* sortedInsert(struct Node *sorted, struct Node *newNode)
{
    if (sorted == NULL || sorted->data >= newNode->data)
    {
        newNode->next = sorted;
        return newNode;
    }

    struct Node *ptrl = sorted;

    while (ptrl->next != NULL && ptrl->next->data < newNode->data)
    {
        ptrl = ptrl->next;
    }

    newNode->next = ptrl->next;
    ptrl->next = newNode;

    return sorted;
}


void InsertionSort(struct Node **start_ref)
{
    struct Node *sorted = NULL;
    struct Node *ptrl = *start_ref;

    while (ptrl != NULL)
    {
        struct Node *next = ptrl->next;
        sorted = sortedInsert(sorted, ptrl);
        ptrl = next;
    }

    *start_ref = sorted;
}

int main()
{
    int arr[5] = {5, 1, 4, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node *start = NULL;

    for (int i = 0; i < n; i++)
    {
        insertAtBegin(&start, arr[i]);
    }

    printList(start);
    InsertionSort(&start);
    printList(start);

    return 0;
}
