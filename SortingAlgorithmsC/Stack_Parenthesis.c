// Task 1
// Add to the parenthesization checking program curly brackets '{' and '}'. 
// Check whether you can deal with the following expressions:
// (1) ( ( [ ] { ( ) } ) ) good
// (2) ( { [ ] } ) good
// (3) ( ) ( ] { } bad

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_SIZE 50

typedef struct
{
    char elements[MAX_SIZE];
    char top;
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
        printf("Stack overflow, can't push %c\n: ", newItem);
        return;
    }
    stack->elements[++stack->top] = newItem;
}

char pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is EMPTY: ");
        exit(EXIT_FAILURE);
    }
    return stack->elements[stack->top--]; 
}

bool isMatchingPair(char left, char right)
{
    return (left == '(' && right == ')') || 
           (left == '[' && right == ']') ||
           (left == '{' && right == '}');
}

bool isBalanced(char *expression)
{   
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    initialize(stack);

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(' || 
            expression[i] == '[' || 
            expression[i] == '{')
        {
            push(stack, expression[i]);
        }
        else if (expression[i] == ')' || 
                 expression[i] == ']' || 
                 expression[i] == '}')
        {
            if (isEmpty(stack) || !isMatchingPair(pop(stack), expression[i]))
            {
                free(stack);
                return false;
            }
        }
    }
    bool balanced = isEmpty(stack);
    free(stack);
    return balanced;
} 

int main() 
{
    int n;
    printf("Enter the number of expressions to check: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        char expr[MAX_SIZE];
        printf("Enter the parentheses expression: ");
        scanf("%s", expr);

        if (isBalanced(expr)) 
        {
            printf("Expression %d: %s is good\n", i + 1, expr);
        } 
        else 
        {
            printf("Expression %d: %s is bad\n", i + 1, expr);
        }
    }

    return 0;
}
