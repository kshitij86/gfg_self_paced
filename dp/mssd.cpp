#include <bits/stdc++.h>
using namespace std;

// given an array, what is the minimum difference b / w two partitions of the array

int minSubsetSumDifference(int n, vector<int> &arr, int sum)
{
    if (n == 0)
    {
        return abs(sum - (accumulate(arr.begin(), arr.end(), 0) - sum));
    }
    // either take or not
    return min(minSubsetSumDifference(n - 1, arr, sum + arr[n - 1]), minSubsetSumDifference(n - 1, arr, sum));
}

// only absolute difference matters here
int dp[101][101];
int minSubsetSumDiffMemo(int n, vector<int> &arr, int sum)
{
    if (n == 0)
    {
        return abs(sum - (accumulate(arr.begin(), arr.end(), 0) - sum));
    }
    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    return dp[n][sum] = min(minSubsetSumDiffMemo(n - 1, arr, sum + arr[n - 1]), minSubsetSumDiffMemo(n - 1, arr, sum));
}

void print2D()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 24; j++)
        {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
}

/*
    similar to equal sum partiotion prob
    we need to minimize abs(s1 - s2)
    limit s1 = sum(arr)/2, so s1 <= sum(arr) - s1 always

    have to minimize = s2 - s1 =  (sum(arr) - s1) - s1
    = sum(arr) - 2*s1;

    can be solved like subset sum now
    the range of s1 can be = [0, sum(arr)] so this will be the size of dp

    dp[n+1][sum+1]
    the last row of dp array tells if current choice will give j as a sum or not

    eg, arr = [1,2,7]
    then sums can only be min_ele = [1,2,3,7,8,9] and we can run a loop over this and find
    diff = min(diff, sum(arr) - min_ele[i])
    return diff;

    0 1 2 3 4 5 -> any choice in this given set can only give 2 and 4 as a sum
    0 0 1 0 1 0

*/

int minSubsetSumDiffTopDown(int n, vector<int> &arr, int sum)
{
    // handle base cases
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i < sum + 1; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i <= sum / 2; i++)
    {
        // if a subset with this sum can exist
        if (dp[n][i] == 1)
        {
            ans = min(ans, sum - (2 * i));
        }
    }
    return ans;
}

int main()
{
    // expected = 1
    vector<int> arr = {1, 6, 5, 11};
    memset(dp, -1, sizeof(dp));

    cout << minSubsetSumDiffTopDown(arr.size(), arr, accumulate(arr.begin(), arr.end(), 0));
    print2D();
}