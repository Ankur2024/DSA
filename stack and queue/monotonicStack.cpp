#include <bits/stdc++.h>
using namespace std;

vector<int> monotonicIncreasing(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() > nums[i])
        {
            st.pop();
        }
        st.push(nums[i]);
    }
    while (!st.empty())
    {
        result.insert(result.begin(), st.top());
        st.pop();
    }

    return result;
}

vector<int> monotonicDecreasing(vector<int>& nums){
    int n = nums.size();
    stack<int> st;
    vector<int> result(n);

    for(int i=0;i<n;i++){
        while (!st.empty() && st.top() < nums[i])
        {
            st.pop();
        }
        if(!st.empty()){
            result[i] = st.top();
        }
        else{
            result[i] = -1;
        }
        st.push(nums[i]);
    }
    return result;
}

int main()
{
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6};
    vector<int> result1 = monotonicIncreasing(nums);
    cout << "Monotonic increasing stack: ";
    for (int num : result1)
    {
        cout << num << " ";
    }
    cout << endl;

     vector<int> result2 = monotonicDecreasing(nums);

    cout << "Monotonic decreasing stack: ";
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}