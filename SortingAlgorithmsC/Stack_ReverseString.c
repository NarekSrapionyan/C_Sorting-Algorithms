// Task 2
// Write a function that reverses a string by pushing and popping its letters on a stack. 
// stack = {"H" "E" "L" "L" "O"}
// reversed = {"O" "L" "L" "E" "H"}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 50

typedef struct 
{
    char name[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack)
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

void push(Stack *stack, char newItem)
{
    if (isFull(stack))
    {
        printf("Stack is FULL: \n");
        return;
    }
    stack->name[++stack->top] = newItem;
}

char pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is EMPTY: \n");
        exit(EXIT_FAILURE);
    }
    return stack->name[stack->top--];
}

void reversedStr(char *name)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    initialize(stack);

    for (int i = 0; name[i] != '\0'; i++)
    {
        push(stack, name[i]);
    }

    for (int i = 0; name[i] != '\0'; i++)
    {
        name[i] = pop(stack);
    }
    free(stack);
}

int main()
{
    char name[MAX_SIZE];
    printf("Enter the name: ");
    scanf("%s", name);

    printf("The original string: %s\n", name);
    reversedStr(name);
    printf("The reversed string: %s\n", name);
    return 0;
}
