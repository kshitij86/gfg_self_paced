#include <bits/stdc++.h>
using namespace std;

// assign some sign to all elements (+/-) so that it may sum up to target

// simple approach, difficult to memoize
// int targetSum(int n, vector<int> &arr, int target)
// {
//     // smol input
//     if (n == 0)
//     {
//         return target == 0;
//     }

//     // give +
//     int pos = targetSum(n - 1, arr, target + arr[n - 1]);
//     // give -
//     int neg = targetSum(n - 1, arr, target - arr[n - 1]);

//     return pos + neg;
// }

/*
    eg,
    arr = 1,1,2,3
    t = 1

    ways of assigning signs to array elements = 3
    -1+1-2+3 = 1
    +1-1-2+3 = 1
    +1+1+2-3 = 1

    if seen closely, it can be related with sum(arr)
                    sum(arr)
                    /     \
                +1+1+3     -2

                    sum(arr)
                    /    \
                +1+3      -2-1

    so it can be seen that if removing some subset of elements from total sum gives the target, that is a valid way
    notes: the target does not have to be zero

    and since we are subtracting from sum(arr), that can be the range of dp grid

    again this question can be simplified further:
    we have to find the subset that when subtracted from sum(arr) gives target, so

    sum(arr) - s1 = target
    sum(arr) - target = s1

    so in simple words, find all subsets that have sum = sum(arr) - target
    this means when this subset is removed from total sum, we will definitely get target value

    this is now count subset sum for sum = (sum(arr) - target)

    this is an approach but not always correct

    it will not count this case - +1+1+2-3 = 1

                    sum(arr)
                    /    \
                +1+3      -2-1

    we can see that we are dividing array into two subsets with difference as given difference
    the two sets are for + and -. if we pick an element and place it in + set,
    then the rejected ones automatically belong to the other set

    (1+3) - (2+1) = 1

    s2 - s1 = target
    sum(arr) - s1 - s1 = sum(arr) - 2*s1 = target
    s1 = (sum(arr) - target)/2 = rd2

    so if we can get subset sum as rd2, we can have a valid assgn of signs to these numbers
    such that they can give target???


    interesting to notice is that the division of numbers always add upto same value in a set - 4, 3 in this case

*/

// simpl rec
int targetSum(int n, vector<int> &arr, int rd2)
{
    // smallest input, all seen
    if (n == 0)
    {
        return rd2 == 0;
    }

    if (arr[n - 1] > rd2)
    {
        // cant take
        return targetSum(n - 1, arr, rd2);
    }
    // choice of 0/1
    return targetSum(n - 1, arr, rd2 - arr[n - 1]) + targetSum(n - 1, arr, rd2);
}

// chang. vars = n, rd2
// dp[n+1][rd2+1]
int dp[100][100];
int targetSumMemo(int n, vector<int> &arr, int rd2)
{
    if (n == 0)
    {
        return rd2 == 0;
    }
    if (dp[n][rd2] != -1)
    {
        return dp[n][rd2];
    }
    if (arr[n - 1] > rd2)
    {
        // cant take
        return dp[n][rd2] = targetSumMemo(n - 1, arr, rd2);
    }
    return dp[n][rd2] = targetSumMemo(n - 1, arr, rd2 - arr[n - 1]) + targetSumMemo(n - 1, arr, rd2);
}

int targetSumTopDown(int n, vector<int> &arr, int rd2)
{
    // handle base cases
    for (int i = 0; i < n + 1; i++)
    {
        // take no ele
        dp[i][0] = 1;
    }
    for (int i = 1; i < rd2 + 1; i++)
    {
        // can make sum > 0 using n == 0
        dp[0][i] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < rd2 + 1; j++)
        {
            // j controls the current sum value
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

int main()
{
    int target = 1;
    vector<int> arr = {1, 1, 2, 3};
    int rd2 = (accumulate(arr.begin(), arr.end(), 0) - target) / 2;

    memset(dp, -1, sizeof(dp));

    // cout << targetSum(arr.size(), arr, rd2);
    // cout << targetSumMemo(arr.size(), arr, rd2);
    cout << targetSumTopDown(arr.size(), arr, rd2);
    // print2D();
}