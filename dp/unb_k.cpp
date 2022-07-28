#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int n, vector<int> &wt, vector<int> &val, int W)
{
    if (n == 0 || W == 0)
    {
        // 0 profit if no items or 0 capacity
        return 0;
    }
    if (wt[n - 1] > W)
    {
        // cant take this item (first time or cant take anymore instances)
        return unboundedKnapsack(n - 1, wt, val, W);
    }

    // here when taking, that item can be taken more times
    // so n value does cannot change
    // if we pick more than capcaity, wt[n-1] > W will stop it
    // but if item is not taken, it will never be taken
    // take the max of either choice, take or not
    return max(val[n - 1] + unboundedKnapsack(n, wt, val, W - wt[n - 1]), unboundedKnapsack(n - 1, wt, val, W));
}

int dp[101][101];
int unboundedKnapsackMemo(int n, vector<int> &wt, vector<int> &val, int W)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }
    if (wt[n - 1] > W)
    {
        return dp[n][W] = unboundedKnapsackMemo(n - 1, wt, val, W);
    }
    return dp[n][W] = max(val[n - 1] + unboundedKnapsackMemo(n, wt, val, W - wt[n - 1]), unboundedKnapsackMemo(n - 1, wt, val, W));
}

void print2D()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
}

int unboundedKnapsackTopDown(int n, vector<int> &wt, vector<int> &val, int W)
{
    // handle base cases
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i < W + 1; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                // only change i-1 -> i
                // take values only from the current row, means this item has been taken multiple times
                // and we are not considering prev item
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int W = 10;
    vector<int> wt = {1, 2};
    vector<int> val = {10, 20};

    // dp
    memset(dp, -1, sizeof(dp));

    cout << unboundedKnapsackTopDown(wt.size(), wt, val, W) << endl;
    // print2D();
}