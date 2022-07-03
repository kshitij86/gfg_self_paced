#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// given an array of n integers and a number (window size) k, find the maximum sum of k consecutive inetegers

int max_sum_k_naive(vector<int> &A, int k){
    // naive approach is to start at every index and consider k elements
    // takes O(n*k) time and O(1) extra space
    // there is no need to go the last as there will always be k elements to the right of 
    //  current index only if we go upto index 
    // [1,2,3,4,5,6,7,8,9], k = 3 
    // 0 (1,2,3)
    // 1 (2,3,4)
    // 2 (3,4,5)
    // 3 (4,5,6)
    // 4 (5,6,7)
    // 5 (6,7,8)
    // 6 (7,8,9)
    // okay approach for small 'k' value but not for 'k' approx equal to n
    // leads to O(n^2) in the worst case
    int n = A.size();
    int max_sum = INT_MIN;
    for(int i=0; i<=n-k; i++){
        int sum_local = 0;
        for(int j=i; j<i+k; j++){
            sum_local += A[j];
        }
        max_sum = max(max_sum, sum_local);
    }
    return max_sum;
}

int max_sum_k_optimal(vector<int> &A, int k){
    // time can be saved by not constructing the window each time
    // but by noticing that each time in a window of size 'k'
    // one element is added and one element is removed
    // so we only ever need O(1) space for a sum variable
    // that we can add to and subtract from
    // [1,2,3,4,5], k = 3
    // sum_k = 6, max_sum = 6, i = 0
    // sum_k = 9, max_sum = 6 
    // O(n) time complexity
    int n = A.size();
    int sum_k = 0;
    // find the sum of the first k elements
    for(int i=0; i<k; i++){
        sum_k += A[i];
    }
    int max_sum = sum_k;
    // the iteration will still start at zero becaue we need to remove that element from the current sum
    // and set the element just outside the window using i starting at zero
    for(int i=0; i<=n-k; i++){
        // cout << sum_k << endl;
        max_sum = max(max_sum, sum_k);
        // remove first element from the sum and add the element just outside the window
        // cout << i + k << endl;
        sum_k -= A[i]; // first element of the window
        sum_k += A[i+k]; // add the element just outside the window
        // go for the next iteration
    }
    return max_sum;
}

int main(){
    // 112 + 89 = 201
    int k = 3;
    vector<int> A = {1,2,3,4,5};
    cout << max_sum_k_optimal(A, k) << endl;
}