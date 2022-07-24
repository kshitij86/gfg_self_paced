#include <bits/stdc++.h>
using namespace std;

int knapsack_recursive(int wt[], int prof[], int W, int n)
{
    // for base condition
    // think of the smallest valid input
    // if there are no items or the knapsack is full
    // it gives zero profit
    if (n == 0 || W == 0)
    {
        return 0;
    }
    // always recursion will be called for a smaller input the current call
    if (wt[n - 1] > W)
    {
        return knapsack_recursive(wt, prof, W, n - 1);
    }
    // guaranteed that wt[n-1] <= W
    // take current item and add its profit
    int take = prof[n - 1] + knapsack_recursive(wt, prof, W - wt[n - 1], n - 1);

    // don't take item
    int not_take = knapsack_recursive(wt, prof, W, n - 1);

    return max(take, not_take);
}

// for size of matrix, think which inputs change
// here n and W chnage so size of matrix depends on these
static int t[11][11];
int knapsack_memo(int wt[], int prof[], int W, int n)
{
    // smallest input possible
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (t[n][W] != -1)
    {
        return t[n][W];
    }
    if (wt[n - 1] > W)
    {
        return t[n][W] = knapsack_memo(wt, prof, W, n - 1);
    }

    int take = prof[n - 1] + knapsack_memo(wt, prof, W - wt[n - 1], n - 1);
    int not_take = knapsack_memo(wt, prof, W, n - 1);

    return t[n][W] = max(take, not_take);
}

// top down approach
// smaller problem to bigger ones
static int dp[11][11];
int knapsack_top_down(int wt[], int prof[], int W, int n)
{
    // initialize for the case n == 0 || W == 0
    for (int i = 0; i < 11; i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    // each cell in the matrix is a subproblem
    // there are n+1 rows corresponding to items
    // there are W+1 rows corresponding to the weight
    // in this loop i will control the rows
    // j will control columns
    // if(j <= W)
    // dp[i][j] = max(prof[i-1] + dp[i-1][W-j], dp[i-1][j])
    // else dp[i][j] = dp[i-1][j]
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            // j is current knapsack capacity
            // i is the item being condsidered
            // subtracting something from j means putting an item
            // in the bag with that much weight
            if (wt[i - 1] <= j)
            {
                // pick maximum in this case
                int take = prof[i - 1] + dp[i - 1][j - wt[i - 1]];
                int not_take = dp[i - 1][j];
                dp[i][j] = max(take, not_take);
            }
            else
            {
                // nothing subtracted from j as
                // nothing is put in the bag
                // cant take
                // will have profit as much as last item considered
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}

void print2d()
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int wt[4] = {1, 3, 4, 7};
    int prof[4] = {5, 3, 4, 8};
    int W = 8;

    memset(t, -1, sizeof(t));
    memset(dp, -1, sizeof(dp));

    cout << knapsack_top_down(wt, prof, W, 4) << endl;
    // print2d();
}