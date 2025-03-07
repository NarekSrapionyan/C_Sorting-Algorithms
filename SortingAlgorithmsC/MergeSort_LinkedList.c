#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void insertAtBegin(Node **start_ref, int data)
{
    Node *ptr = (Node*)malloc(sizeof(Node));
    ptr->data = data; 
    ptr->next = *start_ref;  
    *start_ref = ptr; 
}

void printLinkedList(Node *start)
{
    Node *current = start;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next; 
    }
    printf("\n");
}


Node *merge(Node* left, Node* right)
{
    if (left == NULL) 
        return right;
    if (right == NULL) 
        return left;
    
    Node *result; 

    if (left->data <= right->data)
    {
        result = left;
        result->next = merge(left->next, right);
    }
    else
    {
        result = right;
        result->next = merge(left, right->next); 
    }
    
    return result;
}

void splitList(Node* source, Node** frontRef, Node** backRef)
{
    Node *slow = source;
    Node *fast = source->next; 

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void MergeSort(Node **headRef)
{
    if (*headRef == NULL || (*headRef)->next == NULL)
        return;

    Node *a, *b;

    splitList(*headRef, &a, &b);

    MergeSort(&a); 
    MergeSort(&b); 

    *headRef = merge(a, b);
}

int main()
{
    Node *start = NULL;

    int arr[] = {5, 1, 4, 2, 8}; 
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++)
    {
        insertAtBegin(&start, arr[i]);
    }

    printf("Unsorted List:\n");
    printLinkedList(start);

    MergeSort(&start);

    printf("Sorted List after LinkedList MergeSort: \n");
    printLinkedList(start);

    return 0;
}