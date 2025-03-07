#include <stdio.h>
#include <stdbool.h>

void swap (int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

}

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {    
                swap (arr, j, j + 1);
                swapped  = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[5] = {5, 1, 4, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, size);

    return 0;
}