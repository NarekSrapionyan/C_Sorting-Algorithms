// Sort a linked list using Selection Sort

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
    ptr1->data = data;
    ptr1->next = *start_ref;
    *start_ref = ptr1;
}

void printList(struct Node *start)
{
    struct Node *temp = start;
    printf("\n");
    
    while (temp != NULL)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
}

void Swap(struct Node *a, struct Node *b)
{
    int temp = a -> data;
    a -> data = b -> data;
    b -> data = temp;
}

void SelectionSort(struct Node *start)
{
    struct Node *ptrl = start;

    while (ptrl != NULL)
    {
        struct Node *minNode = ptrl;
        struct Node *ptr2 = ptrl->next;

        while (ptr2 != NULL)
        {
            if (ptr2->data < minNode->data)
            {
                minNode = ptr2;
            }
            ptr2 = ptr2->next;
        }

        if (minNode != ptrl)
        {
            Swap(ptrl, minNode);
        }

        ptrl = ptrl->next;
    }
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
    SelectionSort(start);
    printList(start);

    return 0;
}
