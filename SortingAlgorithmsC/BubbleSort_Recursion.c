#include <stdio.h>
#include <stdbool.h>

void swap (int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

}

void bubbleSortRecursive(int arr[], int size) 
{
    if (size == 1) 
    {
        return;
    }

    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            swap(arr, i, i + 1);
    }

     bubbleSortRecursive(arr, size - 1);
}

int main()
{
    int arr[5] = {5, 1, 4, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubbleSortRecursive(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}