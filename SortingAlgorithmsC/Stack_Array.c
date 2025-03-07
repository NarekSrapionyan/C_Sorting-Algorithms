#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 50

typedef struct
{
    int arr[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack *stack)
{
    stack->top = -1;
}

bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

bool isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int newItem)
{
    if (isFull(stack))
    {
        printf("Stack overflow, can't push %d\n", newItem);
        return;
    }
    stack->arr[++stack->top] = newItem;
}

int pop(Stack *stack)
{
    if(isEmpty(stack))
    {
        printf("Stack underflow, can't pop from the stack: \n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top--];
}

int peek(Stack *stack)
{
    if(isEmpty(stack))
    {
        printf("The stack is empty, can't peek. \n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top];
}

void displayStack(Stack *stack)
{
    if(isEmpty(stack))
    {
        printf("The stack is empty: \n");
        return;
    }

    printf("Stack elements: \n");
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main()
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));

    initializeStack(stack);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    displayStack(stack);

    printf("Popped element: %d\n", pop(stack));

    displayStack(stack);

    printf("Top element: %d\n", peek(stack));

    return 0;
}