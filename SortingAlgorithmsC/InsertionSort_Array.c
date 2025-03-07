#include <stdio.h>

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
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
    int arr[6] = {5, 1, 4, 2, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n);
    InsertionSort(arr, n);
    printArray(arr, n);

    return 0;
}
