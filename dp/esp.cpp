#include <bits/stdc++.h>
using namespace std;
// equal sum partition problem
// given a set, can it be divided into two subsets with the same sum?
// arr = {1,2,3,6}
// ans - yes | {1,2,3}, {6}

// when we write subset code, we either take an element or leaving it
// in this case, when we take an element it belongs to set1
// and the ones we reject along any branch automatically belong to set2
// when n=0, all are seen we check if sum(set1) == sum(set2)
// int canMakeEqualSubsets(int n, vector<int> &arr, int sum)
// {
//     // think of the smallest input
//     if (n == 0)
//     {
//         // all elements considered along this branch
//         return sum == (accumulate(arr.begin(), arr.end(), 0) - sum);
//     }
//     // at each step we can take that elements
//     // and reject all others
//     // here there is no "target" or "W" to consider
//     // we can freely select or reject an element

//     // take
//     int take = canMakeEqualSubsets(n - 1, arr, sum - arr[n - 1]);
//     // not take this one
//     int not_take = canMakeEqualSubsets(n - 1, arr, sum);
//     return (take || not_take);
// }

// // changing variables are n and sum
// // all others are same so grid - dp[n+1][sum+1]
// static int dp[11][11];
// int canMakeEqualSubsetsMemo(int n, vector<int> &arr, int sum)
// {
//     if (n == 0)
//     {
//         // no recursive fn called
//         return (sum == accumulate(arr.begin(), arr.end(), 0) - sum);
//     }
//     if (dp[n][sum] != -1)
//     {
//         return dp[n][sum];
//     }
//     // here no target or W like knapsack
//     // is there so just handle one case where we have choice - take or not
//     return dp[n][sum] = canMakeEqualSubsetsMemo(n - 1, arr, sum - arr[n - 1]) || canMakeEqualSubsetsMemo(n - 1, arr, sum);
// }

// // assuming positive values
// // top down
// // for this we can think about base cases and then eliminate recursion
// // using already computed values
// int canMakeEqualSubsetsTopDown(int n, vector<int> &arr, int sum)
// {
// }

/*
    when we make subsets of equal sum say s1 and s2,
    essentially s1 == s2 = s
    so the sum has to be a even values = 2s

    we can just keep track of one variable and
    check if sum of that variable can be made == s
    somehow, the other sum will automatically be 2s - s = s
    so we can treat this problem as picking some elements and
    making their sum == s, like 0/1 knapsack

    W = s
    n = n
*/

int canMakeEqualSubsets(int n, vector<int> &arr, int sum)
{
    if (n == 0)
    {
        return (sum == 0);
    }

    // current element is larger than sum
    if (arr[n - 1] > sum)
    {
        // dont take
        return canMakeEqualSubsets(n - 1, arr, sum);
    }
    // either take or dont whichever gives ans
    return canMakeEqualSubsets(n - 1, arr, sum - arr[n - 1]) || canMakeEqualSubsets(n - 1, arr, sum);
}

int dp[20][20];
void print2D()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
}

/// changing vars = n, sum
int canMakeEqualSubsetsMemo(int n, vector<int> &arr, int sum)
{
    if (n == 0)
    {
        return sum == 0;
    }
    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    if (arr[n - 1] > sum)
    {
        // cant take this ele
        return dp[n][sum] = canMakeEqualSubsetsMemo(n - 1, arr, sum);
    }

    // else we have a choice
    return dp[n][sum] = canMakeEqualSubsetsMemo(n - 1, arr, sum - arr[n - 1]) || canMakeEqualSubsetsMemo(n - 1, arr, sum);
}

// this memo version makes top down really simple
int canMakeEqualSubsetsTopDown(int n, vector<int> &arr, int sum)
{
    // no recursion
    // handle base cases
    // if n == 0, only sum == 0 is possible
    // if sum == 0, then always possible
    // dp[0][0] = 1 (special case in first row)
    for (int i = 0; i < n + 1; i++)
    {
        // here sum = 0
        dp[i][0] = 1;
    }
    // i = 1, exclude special case dp[0][0]
    for (int i = 1; i < sum + 1; i++)
    {
        // with n = 0 ele, > 0 sum imposs
        dp[0][i] = 0;
    }
    // preprocessing done
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] > j)
            {
                // current ele value is > sum to get
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i][j - arr[i - 1]] || dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main()
{
    vector<int> arr = {1, 5, 11, 5};
    int sum = accumulate(arr.begin(), arr.end(), 0);
    memset(dp, -1, sizeof(dp));

    if (sum % 2 == 0)
    {
        // sum is n/2 as if we can have a subset of sum s
        // other subset has size = 2s - s = s auto
        // cout << canMakeEqualSubsets(arr.size(), arr, sum / 2) << endl;
        cout << canMakeEqualSubsetsTopDown(arr.size(), arr, sum / 2);
        print2D();
    }
    else
    {
        // odd no cannot be divided into two equal parts
        cout << "0" << endl;
    }
}