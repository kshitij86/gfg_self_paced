#include <bits/stdc++.h>
using namespace std;

// how many pairs of subset have given diff as their difference?
/*
    rec and bu will be easy
    td will use mssd approach
*/

// rec
// col = collected sum
// int countSubsetsWithDiff(int n, vector<int> &arr, int diff, int col)
// {
//     // smallest inp
//     if (n == 0)
//     {
//         // all ele along this branch considered
//         return (abs(col - (accumulate(arr.begin(), arr.end(), 0) - col)) == diff);
//     }

//     // choice, take or not
//     // total subsets with diff = sum of choices
//     return countSubsetsWithDiff(n - 1, arr, diff, col + arr[n - 1]) + countSubsetsWithDiff(n - 1, arr, diff, col);
// }

// rec + logic
/*
    we have to find all subsets with differnece as diff
    so basically,

    s2 - s1 = diff
    sum(arr) - s1 - s1 = diff
    sum(arr) - 2*s1 = diff
    so, s1 = (sum(arr) - diff)/2 = rd2;

    this is same as count subset sum for target = rd2

    counting how many subsets have sum as rd2 will give count of subsets with given diff

    genius!!!
*/
int countSubsetsWithDiff(int n, vector<int> &arr, int rd2)
{
    if (n == 0)
    {
        return rd2 == 0;
    }
    if (arr[n - 1] > rd2)
    {
        return countSubsetsWithDiff(n - 1, arr, rd2);
    }
    return countSubsetsWithDiff(n - 1, arr, rd2 - arr[n - 1]) + countSubsetsWithDiff(n - 1, arr, rd2);
}

int dp[20][20];
int countSubsetsWithDiffMemo(int n, vector<int> &arr, int rd2)
{
    if (n == 0)
    {
        return (rd2 == 0);
    }
    if (dp[n][rd2] != -1)
    {
        return dp[n][rd2];
    }
    // larger element
    if (arr[n - 1] > rd2)
    {
        // not take arr[n-1]
        return dp[n][rd2] = countSubsetsWithDiffMemo(n - 1, arr, rd2);
    }
    return dp[n][rd2] = countSubsetsWithDiffMemo(n - 1, arr, rd2 - arr[n - 1]) + countSubsetsWithDiffMemo(n - 1, arr, rd2);
}

void print2D()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
}

// top down is the same as count subset sum
int countSubsetsWithDiffTopDown(int n, vector<int> &arr, int rd2)
{
    // handle base cases
    for (int i = 0; i < n + 1; i++)
    {
        // here we have target = 0
        dp[i][0] = 1;
    }
    for (int i = 1; i < rd2 + 1; i++)
    {
        // target > 0 not possible with n = 0
        dp[0][i] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < rd2 + 1; j++)
        {
            // ele > j
            if (arr[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
        }
    }
    return dp[n][rd2];
}

int main()
{
    int diff = 1;
    vector<int> arr = {1, 1, 2, 3};
    int rd2 = ((accumulate(arr.begin(), arr.end(), 0) - diff) / 2);

    // dp
    memset(dp, -1, sizeof(dp));

    cout << countSubsetsWithDiffTopDown(arr.size(), arr, rd2);
    print2D();
}