// Task 4
// Converting a Decimal Number to Binary
// Use a stack to convert a decimal number into the binary system.
// Example:
//    Input: 25
//    Output: "11001"
// Algorithm:
// 1. Divide the number by 2.
// 2. Store the remainders in a stack.
// 3. Print the remainders in reverse order to get the binary representation.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 50

typedef struct
{
    int elements[MAX_SIZE];
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

void push(Stack *stack, int newItem)
{
    if (isFull(stack))
    {
        printf("Stack is FULL \n");
        return;
    }
    stack->elements[++stack->top] = newItem;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is EMPTY \n");
        exit(EXIT_FAILURE);
    }
    return stack->elements[stack->top--];
}

void decimalToBinary(int num)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    initialize(stack);

    while (num > 0)
    {
        push(stack, num % 2);
        num = num / 2;
    }

    printf("Binary number: ");
    while (!isEmpty(stack))
    {
        printf("%d", pop(stack));
    }
    printf("\n");

    free(stack);
}

int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    printf("Original number: %d\n", num);
    decimalToBinary(num);

    return 0;
}
