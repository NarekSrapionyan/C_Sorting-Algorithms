#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertB(struct Node **start_ref, int data)
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

void BubbleSort(struct Node *start)
{
    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    if (start == NULL)
        return;

    do 
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1 -> next != lptr)
        {
            if (ptr1 -> data > ptr1 -> next -> data)
            {
                Swap(ptr1, ptr1 -> next);
                swapped = 1;
            }
            ptr1 = ptr1 -> next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

int main()
{
    int arr[5] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node *start = NULL;

    for (int i = 0; i < n; i++)
    {
        insertB(&start, arr[i]);
    }

    printList(start);
    BubbleSort(start);
    printList(start);

    return 0;
}
