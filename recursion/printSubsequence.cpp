#include <iostream>
#include <vector>
using namespace std;

void printSub(int ind, vector<int> &ds, int s, int sum, int arr[], int n){
    if(ind == n){
        if(s == sum){
            for(int i=0;i<ds.size();i++){
                cout << ds[i] << " ";
            }
            cout<<endl;
        }
        return;
    }
    ds.push_back(arr[ind]);
    s += arr[ind];
    printSub(ind+1, ds, s, sum, arr, n);
    ds.pop_back();
    s -= arr[ind];
    printSub(ind+1, ds, s, sum, arr, n);
}

int main(){
    int arr[] = {1, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 2;
    vector<int> ds;
    printSub(0, ds, 0, sum, arr, n);
    return 0;
}