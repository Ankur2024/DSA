#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> &nums){
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

void rotateRight(vector<int> &nums, int k){
    int n = nums.size();
    k = k % n;
    vector<int> result(n);
    for(int i=0;i<n;i++){
        int index = (i + k) % n;  
        result[index] = nums[i];
    }
    printArr(result);
}

void rotateLeft(vector<int> &nums, int k){
    int n = nums.size();
    k = k % n;
    vector<int> result(n);
    for(int i=0;i<n;i++){
        int index = (i - k + n) % n;
        result[index] = nums[i]; 
    }
    printArr(result);
}


void rotateRightWithoutSpace(vector<int> nums, int k){
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    printArr(nums);
}
void rotateLeftWithoutSpace(vector<int> nums, int k){
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    reverse(nums.begin(), nums.end());
    printArr(nums);
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    cout<< "Rotation On Right" << endl;
    rotateRight(nums, 2);
    cout<< "Rotation On Left" << endl;
    rotateLeft(nums, 4);
    cout<< "Rotation On Right Without Extra Space" << endl;
    rotateRightWithoutSpace(nums, 2);
    cout<< "Rotation On Left Without Extra Space" << endl;
    rotateLeftWithoutSpace(nums, 4);
    return 0;
}