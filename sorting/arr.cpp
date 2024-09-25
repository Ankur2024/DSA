#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> temp (n);
    for (int i = 0; i < n; i++)
    {
        if(n == 1){
            return;
        }
        if(k == 0){
            return;
        }

        if( k > n){
            k = k % n;
        }
        if (nums.size() <= i + k)
        {
            temp[(i + k) - nums.size()] = nums[i];
        }
        else
        {
            temp[i + k] = nums[i];
        }
    }
    for (int i=0; i<n;i ++){
        nums[i] = temp[i];
    }
}

void printArr(vector<int> &arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec_1 = {-1};
    rotate(vec_1, 2);
    printArr(vec_1);
    vector<int> vec_2 = {1,2,3,4};
    rotate(vec_2, 9);
    printArr(vec_2);
    return 0;
}