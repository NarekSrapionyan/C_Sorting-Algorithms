#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node *createNode(int data)
{   
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void forwardTraversal(Node *head)
{
    Node *temp = head;
    while(temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void backwardTraversal(Node *tail)
{
    Node *temp = tail;
    while(temp)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    Node *head = createNode(1);
    Node *second = createNode(2);
    Node *third = createNode(3);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    forwardTraversal(head);
    backwardTraversal(third);

    return 0;
}
