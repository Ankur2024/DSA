#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int s, int e){
    int pivot = arr[s];
    int cnt = 0;
    for(int i=s+1;i<=e;i++){
        if(arr[i] <= pivot){
            cnt++;
        }
    }

    int pivotIndex = s+cnt;
    swap(arr[pivotIndex], arr[s]);

    int i=s;
    int j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i], arr[j]);
        }
    }


    return pivotIndex;
}

void quickSort(vector<int> &arr, int s, int e){
    if(s >= e) return;
    int p = partition(arr, s, e);
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);

}

int main(){
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    int s = 0;
    int e = n - 1;

    quickSort(arr, s, e);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}