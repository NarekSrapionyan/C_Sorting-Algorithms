// Task 3
// Write a program that removes consecutive duplicate characters from a string.
// Example:
// Input: "aabbccddeee"
// Output: "abcde"
// Use a stack to compare the current character with the previous one.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 50

typedef struct 
{
    char elements[MAX_SIZE];
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
    stack->elements[++stack->top] = newItem;
}

void removeConsecutiveDublicates(char *str)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    initialize(stack);
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isEmpty(stack) || stack->elements[stack->top] != str[i])
        {
            push(stack, str[i]);
            str[index++] = str[i];
        }
    } 
    str[index] = '\0';
    free(stack);
}

int main()
{
    char str[MAX_SIZE];

    printf("Enter the string: ");
    scanf("%s", str);

    printf("Original String: %s\n", str);
    removeConsecutiveDublicates(str);
    printf("String after removing consecutive dublicates: %s", str);

    return 0;
}