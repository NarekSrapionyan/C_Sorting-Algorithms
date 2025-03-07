#include <stdio.h>
#include <stdlib.h>

struct Node {
    int Data;
    struct Node *Next;
};

void Push(struct Node **Head, int Data) {
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    NewNode->Data = Data;
    NewNode->Next = *Head;
    *Head = NewNode;
}

struct Node *Partition(struct Node *Head, struct Node *End, struct Node **NewHead, struct Node **NewEnd) {
    struct Node *Pivot = End, *Prev = NULL, *Current = Head, *Tail = Pivot;
    struct Node *TempHead = NULL, *TempTail = NULL;
    while (Current != Pivot) {
        struct Node *Next = Current->Next;
        if (Current->Data < Pivot->Data) {
            if (!TempHead) TempHead = Current;
            TempTail = Current;
        } else {
            if (Prev) Prev->Next = Current->Next;
            Tail->Next = Current;
            Tail = Current;
        }
        Prev = Current;
        Current = Next;
    }
    Tail->Next = NULL;
    *NewHead = TempHead ? TempHead : Pivot;
    *NewEnd = Tail;
    return Pivot;
}

struct Node *QuickSortRecur(struct Node *Head, struct Node *End) {
    if (!Head || Head == End) return Head;
    struct Node *NewHead = NULL, *NewEnd = NULL;
    struct Node *Pivot = Partition(Head, End, &NewHead, &NewEnd);
    if (NewHead != Pivot) {
        struct Node *Temp = NewHead;
        while (Temp->Next != Pivot) Temp = Temp->Next;
        Temp->Next = NULL;
        NewHead = QuickSortRecur(NewHead, Temp);
        struct Node *Tail = NewHead;
        while (Tail->Next) Tail = Tail->Next;
        Tail->Next = Pivot;
    }
    Pivot->Next = QuickSortRecur(Pivot->Next, NewEnd);
    return NewHead;
}

void QuickSort(struct Node **Head) {
    struct Node *End = *Head;
    if (!End) return;
    while (End->Next) End = End->Next;
    *Head = QuickSortRecur(*Head, End);
}

void PrintList(struct Node *Head) {
    printf("[");
    while (Head) {
        printf("%d", Head->Data);
        Head = Head->Next;
        if (Head) printf(", ");
    }
    printf("]\n");
}

int main() {
    struct Node *Head = NULL;
    Push(&Head, 3);
    Push(&Head, 1);
    Push(&Head, 4);
    Push(&Head, 1);
    Push(&Head, 5);
    Push(&Head, 9);
    Push(&Head, 2);
    Push(&Head, 6);
    printf("Before Sorting: ");
    PrintList(Head);
    QuickSort(&Head);
    printf("After Sorting: ");
    PrintList(Head);
    return 0;
}
