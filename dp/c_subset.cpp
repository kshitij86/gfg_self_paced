#include <bits/stdc++.h>
using namespace std;

// given an array, how many subsets of that array sum up to target

int countSubsetSum(int n, vector<int> &arr, int target)
{
    if (n == 0)
    {
        // returns either true or false, depending on the val of target
        return (target == 0);
    }
    // curr ele > target
    if (arr[n - 1] > target)
    {
        // cant take
        return countSubsetSum(n - 1, arr, target);
    }
    // else choice on take or not
    // it will get either 0 or 1 so they can be added
    // if a subset with target is there, we get 1 or else 0
    return countSubsetSum(n - 1, arr, target - arr[n - 1]) + countSubsetSum(n - 1, arr, target);
}

// chang. vars = n, target
int dp[101][101];
int countSubsetSumMemo(int n, vector<int> &arr, int target)
{
    if (n == 0)
    {
        return (target == 0);
    }
    if (dp[n][target] != -1)
    {
        return dp[n][target];
    }
    if (arr[n - 1] > target)
    {
        // one choice, dont take
        return dp[n][target] = countSubsetSumMemo(n - 1, arr, target);
    }
    return dp[n][target] = countSubsetSumMemo(n - 1, arr, target - arr[n - 1]) + countSubsetSumMemo(n - 1, arr, target);
}

void print2D()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
}

int countSubsetSumTopDown(int n, vector<int> &arr, int target)
{
    // handle base cases
    for (int i = 0; i < n + 1; i++)
    {
        // here target is zero so true
        dp[i][0] = 1;
    }
    for (int i = 1; i < target + 1; i++)
    {
        // with 0 elements, > 0 target imposs
        dp[0][i] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < target + 1; j++)
        {
            if (arr[i - 1] > j)
            {
                //  j controls the current target to get
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
        }
    }
    return dp[n][target];
}

int main()
{
    // int target = 10;
    // vector<int> arr = {2, 3, 5, 6, 8, 10};

    int target = 6;
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    memset(dp, -1, sizeof(dp));

    // cout << countSubsetSum(arr.size(), arr, target);
    // cout << countSubsetSumMemo(arr.size(), arr, target) << endl;
    cout << countSubsetSumTopDown(arr.size(), arr, target);

    // print2D();
}