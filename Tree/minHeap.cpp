#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[smallest] > arr[left])
    {
        smallest = left;
    }
    if (right <= n && arr[smallest] > arr[right])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

class MinHeap
{
public:
    int arr[100];
    int size;
    int capacity;
    MinHeap()
    {
        arr[0] = -1;
        size = 0;
        capacity = 100;
    }
    void insert(int val)
    {
        if (size >= capacity)
        {
            cout << "Heap is full. Cannot insert element" << endl;
            return;
        }
        size++;
        arr[size] = val;
        int index = size;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] > arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    friend void heapify(int arr[], int n, int i);

    void deleteFromHeap()
    {
        if (size == 0)
            return;
        arr[1] = arr[size];
        size--;
        heapify(arr, size, 1);
    }
};

void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[1], arr[size]);

        size--;

        heapify(arr, size, 1);
    }
}
int main()
{
    MinHeap h;
    h.insert(1);
    h.insert(3);
    h.insert(9);
    h.insert(8);
    h.insert(6);
    h.insert(2);
    h.print();
    h.deleteFromHeap();
    h.print();
    int arr[6] = {-1, 54, 53, 55, 52, 30};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    cout << "Printing the array now" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Heap Sort" << endl;
    heapSort(arr, n);
    cout << "Sorted array: \n";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}