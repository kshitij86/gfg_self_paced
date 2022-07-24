// Given an array of integers and a target, find out if there exists a subset in the array such that it sums to the given target.
#include <bits/stdc++.h>
using namespace std;

// no memoized
int doesSubsetExist(int n, vector<int> &arr, int target)
{
    if (n < 0)
    {
        return target == 0;
    }
    // if element is larger than target
    if (arr[n - 1] > target)
    {
        // dont take
        return doesSubsetExist(n - 1, arr, target);
    }
    // take element or leave it
    int take = doesSubsetExist(n - 1, arr, target - arr[n - 1]);
    int not_take = doesSubsetExist(n - 1, arr, target);

    return (take || not_take);
}

// changing vars = idx, target
// memoized version
int dp[101][101];
int doesSubsetExistMemo(int n, vector<int> &arr, int target)
{
    if (n < 0)
    {
        return target == 0;
    }
    if (dp[n][target] != -1)
    {
        // if already computed, just return
        return dp[n][target];
    }
    if (arr[n - 1] > target)
    {
        return dp[n][target] = doesSubsetExistMemo(n - 1, arr, target);
    }
    // here 2 choices - take or leave
    return dp[n][target] = doesSubsetExistMemo(n - 1, arr, target - arr[n - 1]) || doesSubsetExistMemo(n - 1, arr, target);
}

void print2D()
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
}

// top down version
// dp grid size is same - dp[i+1][target+1]
int doesSubsetExistTopDown(int n, vector<int> &arr, int target)
{
    // handle base cases
    // here base cases are different
    // first col means target = 0
    // which can be achieved with picking no ele
    // so answer is always true
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }
    // in the first row except the first ele
    // all targets are > 0 and in that row
    // number of ele is zero
    // so it is never possible to get a sum > 0
    // with 0 ele
    // answer is always false
    for (int i = 1; i < target + 1; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < target + 1; j++)
        {
            if (arr[i - 1] > j)
            {
                // take the possibility without this ele
                // as it is > target
                // if j is intact, nothing is added to sum
                // and current ele is ignored
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                // here arr[n-1] <= target
                // so we have choice to take it or leave it
                // TODO: [j- arr[i-1]] says can we achieve given the target
                // j using the value arr[n-1]
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
        }
    }
    return dp[n][target];
}

int main()
{
    int target = 25;
    vector<int> arr = {2, 3, 7, 8, 10};

    memset(dp, -1, sizeof(dp));

    cout << doesSubsetExistTopDown(arr.size(), arr, target);
}