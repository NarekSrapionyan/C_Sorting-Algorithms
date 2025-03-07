#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[50];
    int grade;
} 
Student;

void swap(Student *students, int i, int j)
{
    Student temp = students[i];
    students[i] = students[j];
    students[j] = temp;
}

void bubbleSort(Student students[], int n, int *comparisonCount, int *swapCount)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            (*comparisonCount)++;
            if (students[j].grade > students[j + 1].grade || 
            (students[j].grade == students[j + 1].grade && 
            strcmp(students[j].name, students[j + 1].name) > 0))
            {
                swap(students, j, j + 1);
                (*swapCount)++;
            }
        }
    }
}

void printStudents(Student students[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s: %d\n", students[i].name, students[i].grade);
    }
}

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    Student students[n];
    
    for (int i = 0; i < n; i++)
    {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter grade of student %d: ", i + 1);
        scanf("%d", &students[i].grade);
    }

    int comparisonCount = 0;
    int swapCount = 0;

    bubbleSort(students, n, &comparisonCount, &swapCount);
    printStudents(students, n);
    printf("Number of comparisons: %d\n", comparisonCount);
    printf("Number of swaps: %d\n", swapCount);

    return 0;
}
