#include <bits/stdc++.h>
using namespace std;

// naive approache

int maxSum(int arr[], int n, int k)
{
    int max_sum = INT_MIN;

    for (int i = 0; i < n - k + 1; i++)
    {
        int current_sum = 0;
        for (int j = 0; j < k; j++)
        {
            current_sum = current_sum + arr[i + j];
            max_sum = max(max_sum, current_sum);
        }
    }

    return max_sum;
}

// sliding Window
int maxSumSlidingWindow(int arr[], int n, int k)
{
    if (n <= k)
    {
        cout << "Invalid" << endl;
        return -1;
    }
    int max_sum = 0;
    for(int i=0; i < k; i++){
        max_sum += arr[i];
    }

    int window_sum = max_sum;
    for(int i = k; i < n;i++){
        window_sum += arr[i] - arr[i - k];
        max_sum = max(max_sum, window_sum);
    }
    return max_sum;
}

int main()
{
    int arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSum(arr, n, k);
    cout << endl;
    cout << maxSumSlidingWindow(arr, n, k);
    return 0;
}