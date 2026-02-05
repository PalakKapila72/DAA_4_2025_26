#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int heap[MAX];
int heapSize = 0;

void heapifyDown(int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left] < heap[smallest])
        smallest = left;

    if (right < heapSize && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }
}

void heapifyUp(int i)
{
    while (i > 0 && heap[(i - 1) / 2] > heap[i])
    {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void insert(int val)
{
    if (heapSize == MAX)
    {
        cout << "Heap is full\n";
        return;
    }

    heap[heapSize] = val;
    heapSize++;

    heapifyUp(heapSize - 1);
}

void deleteMin()
{
    if (heapSize == 0)
    {
        cout << "Heap is empty\n";
        return;
    }

    heap[0] = heap[heapSize - 1];
    heapSize--;

    heapifyDown(0);
}

int searchElement(int val)
{
    for (int i = 0; i < heapSize; i++)
    {
        if (heap[i] == val)
            return i;
    }
    return -1;
}

void deleteElement(int val)
{
    int index = searchElement(val);

    if (index == -1)
    {
        cout << "Element not found\n";
        return;
    }

    heap[index] = heap[heapSize - 1];
    heapSize--;

    heapifyDown(index);
    heapifyUp(index);
}

void printHeap()
{
    for (int i = 0; i < heapSize; i++)
        cout << heap[i] << " ";

    cout << endl;
}

int main()
{
    insert(2);
    insert(4);
    insert(6);
    insert(1);

    printHeap();

    cout << searchElement(4) << endl;

    deleteElement(4);
    printHeap();

    deleteMin();
    printHeap();

    return 0;
}
