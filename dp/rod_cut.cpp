#include <bits/stdc++.h>
using namespace std;

// how to divide a rod into several parts so that
// we can get maximum profit
// this is different from 0/1 knapsack as we can have multiple instances
// of the same length

// eg, 8 = 3 + 3 + 2
// so this is an example of unbounded knapsack
// everything else is same

int rodCut(int n, vector<int> &cost, int len)
{
    // cout << n << "  " << len << endl;
    // either only 0 length is possible or
    // rod has 0 length
    // len >= 1
    if (n == 0 || len == 0)
    {
        return 0;
    }
    if (n > len)
    {
        // this length is too big
        // than current size of rod
        return rodCut(n - 1, cost, len);
    }
    // take this profit and consider this instance again
    // or not anymore
    return max(cost[n - 1] + rodCut(n, cost, len - n), rodCut(n - 1, cost, len));
}

int dp[101][101];
int rodCutMemo(int n, vector<int> &cost, int len)
{
    // simply memoize the recursive calls
    if (n == 0 || len == 0)
    {
        return 0;
    }
    if (dp[n][len] != -1)
    {
        return dp[n][len];
    }
    if (n > len)
    {
        // cant take the item
        return dp[n][len] = rodCutMemo(n - 1, cost, len);
    }
    return dp[n][len] = max(cost[n - 1] + rodCutMemo(n, cost, len - n), rodCutMemo(n - 1, cost, len));
}

void print2D()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
}

int rodCutTopDown(int n, vector<int> &cost, int len)
{
    // handle base cases
    // square grid
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < len + 1; j++)
        {
            if (i > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(cost[i - 1] + dp[i][j - i], dp[i - 1][j]);
            }
        }
    }
    return dp[n][len];
}

int main()
{
    int len = 8;
    vector<int> cost = {1, 5, 8, 9, 10, 17, 17, 20};

    memset(dp, -1, sizeof(dp));

    // cout << rodCut(len, cost, len) << endl;
    // cout << rodCutMemo(len, cost, len);
    cout << rodCutTopDown(len, cost, len) << endl;
    // print2D();
}