#include <stdio.h>
#include <stdlib.h>

struct Node {
    int Data;
    struct Node *Next;
};

void Swap(struct Node *A, struct Node *B) {
    int Temp = A->Data;
    A->Data = B->Data;
    B->Data = Temp;
}

void Heapify(struct Node *Head, int N, int I) {
    int Largest = I;
    int Left = 2 * I + 1;
    int Right = 2 * I + 2;

    struct Node *Current = Head;
    for (int i = 0; i < I; i++) {
        if (Current == NULL) return;
        Current = Current->Next;
    }
    struct Node *LargestNode = Current;

    struct Node *LeftNode = Head;
    for (int i = 0; i < Left; i++) {
        if (LeftNode == NULL) return;
        LeftNode = LeftNode->Next;
    }

    struct Node *RightNode = Head;
    for (int i = 0; i < Right; i++) {
        if (RightNode == NULL) return;
        RightNode = RightNode->Next;
    }

    if (Left < N && LeftNode->Data > LargestNode->Data) {
        Largest = Left;
        LargestNode = LeftNode;
    }

    if (Right < N && RightNode->Data > LargestNode->Data) {
        Largest = Right;
        LargestNode = RightNode;
    }

    if (Largest != I) {
        Swap(Current, LargestNode);
        Heapify(Head, N, Largest);
    }
}

void HeapSort(struct Node *Head, int N) {
    for (int I = N / 2 - 1; I >= 0; I--) {
        Heapify(Head, N, I);
    }

    for (int I = N - 1; I > 0; I--) {
        struct Node *LastNode = Head;
        for (int J = 0; J < I; J++) {
            LastNode = LastNode->Next;
        }
        Swap(Head, LastNode);
        Heapify(Head, I, 0);
    }
}

void Push(struct Node **Head, int Data) {
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    NewNode->Data = Data;
    NewNode->Next = *Head;
    *Head = NewNode;
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

int GetLength(struct Node *Head) {
    int Count = 0;
    while (Head) { Count++; Head = Head->Next; }
    return Count;
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
    int N = GetLength(Head);
    HeapSort(Head, N);
    PrintList(Head);
    return 0;
}