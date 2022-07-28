#include <bits/stdc++.h>
using namespace std;

int coinChange1(int n, vector<int> &deno, int sum)
{
    if (n == 0)
    {
        // all coins considered, does it give sum?
        return (sum == 0);
    }
    if (deno[n - 1] > sum)
    {
        // coin bigger than sum; cant take
        return coinChange1(n - 1, deno, sum);
    }
    // unbounded knapsack
    return coinChange1(n, deno, sum - deno[n - 1]) + coinChange1(n - 1, deno, sum);
}

int dp[101][101];
int coinChange1Memo(int n, vector<int> &deno, int sum)
{
    if (n == 0)
    {
        return (sum == 0);
    }
    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    if (deno[n - 1] > sum)
    {
        return dp[n][sum] = coinChange1Memo(n - 1, deno, sum);
    }

    return dp[n][sum] = coinChange1Memo(n, deno, sum - deno[n - 1]) + coinChange1Memo(n - 1, deno, sum);
}

int coinChange1TopDown(int n, vector<int> &deno, int sum)
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
            if (deno[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                // unbounded knapsack
                dp[i][j] = dp[i][j - deno[i - 1]] + dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main()
{
    int sum = 5;
    vector<int> deno = {1, 2, 3};

    memset(dp, -1, sizeof(dp));

    cout << coinChange1TopDown(deno.size(), deno, sum);
}