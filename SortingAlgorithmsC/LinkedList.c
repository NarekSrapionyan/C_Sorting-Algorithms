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

void printLinkedList(struct Node *start)
{
    struct Node *current = start;

    while (current != NULL)
    {
        printf("%d ", current -> data);
        current = current -> next;
    }

}

int main()
{
    int arr[5] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node *start = NULL;

    for (int i = 0; i < n; i++)
    {
        insertAtBegin(&start, arr[i]);
    }
    printLinkedList(start);

    return 0;
}
