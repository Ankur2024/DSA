#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
public:
    int arr[100];
    int size = 0;
    MaxHeap(){
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
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

    void deleteFromHeap(){
        if(size == 0) return;
        arr[1] = arr[size];
        size--;

        //take root node to correct position
        int i = 1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;
            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }else {
                return;
            }
        } 
    }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest!= i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    int size = n;
    while(size > 1){
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}

int main()
{
    MaxHeap h;
    h.insert(50);
    h.insert(55);
    h.insert(40);
    h.insert(24);
    h.insert(10);
    h.print();
    h.deleteFromHeap();
    h.print();
    int arr[6] = {-1, 54, 53, 55, 52, 30};
    int n = 5;
    for(int i=n/2;i>0;i--){
        heapify(arr, n, i);
    }
    cout << "Printing the array now" << endl;
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }cout<< endl;

    cout << "Heap Sort" <<endl;
    heapSort(arr, n);
    cout << "Sorted array: \n";
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }cout<< endl;
    return 0;
}