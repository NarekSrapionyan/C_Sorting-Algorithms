// Implement Selection Sort using Recursion

#include <stdio.h>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int FindMinIndex(int arr[], int start, int n)
{
    int minIndex = start;

    for (int i = start + 1; i < n; i++)
    {
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
    }

    return minIndex;
}

void SelectionSortRecursive(int arr[], int start, int n)
{
    if (start >= n - 1)
    {
        return;
    }

    int minIndex = FindMinIndex(arr, start, n);

    if (minIndex != start)
    {
        Swap(&arr[start], &arr[minIndex]);
    }

    SelectionSortRecursive(arr, start + 1, n);
}

void printArray(int arr[], int n)
{
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[5] = {5, 1, 4, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n);
    SelectionSortRecursive(arr, 0, n);
    printArray(arr, n);

    return 0;
}
