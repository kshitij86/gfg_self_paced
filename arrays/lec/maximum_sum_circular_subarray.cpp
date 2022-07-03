#include <iostream>
#include <vector>
using namespace std;

int max_circular_naive(vector<int> &A){
    // O(N^2) approach
    int n = A.size();
    // res is the global maximum that stores final result
    // the maximum sum across all subarrays
    int res = A[0];
    for(int i=0; i<n; i++){
        // curr_max only stores maximum sum of 
        // any subarray starting at i
        int curr_max = A[i];
        // curr_sum just adds elements regardless
        int curr_sum = A[i];
        // this loop just adds the number of elements other than the current i
        /**
         * if we are in the middle of the array, we can skip to the circular part using (i+j)%n
         * 
         * [1,2,3,4,5], all subarrays (normal or circular) starting ar 3 are -> 
         * NORMAL: 
         * [3] (2-2)
         * [3,4] (2-3)
         * [3,4,5] (2-4)
         * CIRCULAR:
         * [3,4,5,1] (2-0) backwards because circular
         * [3,4,5,1,2] (2-1) backwards because circular
         */
        for(int j=1; j<n; j++){
            // ensures wrapping around od the array
            int idx = (i+j) % n;
            // add current element to sum no matter what
            curr_sum += A[idx];
            // check if adding any number really gives any maximum
            curr_max = max(curr_max, curr_sum);
        }
        // whether the sum of any subarray starting at i is maximum than 
        // the current answer or not
        res = max(res, curr_max);
    }
    return res;
}

int max_circular_optimal(vector<int> &A){
    int n = A.size();
    // O(N) time complexity
    // to find the maximum sum of all normal subrrays
    // kadane's algo can be used for both the halves
    // normal subarrays and circular subarrays
    int max_ending_here = A[0], max_so_far = A[0], total = A[0];
    for(int i=1; i<n; i++){
        total += A[i];
        // this means that either you continue the sum (max_ending_here += A[i])
        // else start a new sum here and set it to A[i]
        // so that all sums starting from this element can be considered
        max_ending_here = max(max_ending_here + A[i], A[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    // this is done to handle the case when everything is negative
    // then circular subarray that will give minimum sum is same as 
    // entire array, and bith sums will total give zero
    // so if all elements are negative then it is guaranteed that 
    // kadane's on normal == kadane's on circular 
    if(max_so_far < 0){
        return max_so_far; 
    }
    // next step is to apply kadane's to find the minimum sum subarray which is present
    // if from the total sum the minimum sum subarray is removed, then we get maximum 
    // circular array sum
    // total contains the total array sum of the array not considering the sign of the integers
    int min_ending_here = A[0]; // the minimum starting at index i
    int min_so_far = A[0]; // the total minimum over all elements 
    for(int i=1; i<n; i++){
        // check if adding a new element gives smaller value or 
        // the element starting here gives a smaller one
        // 8 + -2 > -11 (min value is -11)
        min_ending_here = min(A[i] + min_ending_here, A[i]);
        min_so_far = min(min_ending_here, min_so_far);
    }
    int circular_sum = total - min_so_far;
    return max(circular_sum, max_so_far);
}

int main(){
    // maximum sum subarray is {arr[0], arr[arr.size()-1]} = 5  
    vector<int> A = {-5, -3};
    cout << max_circular_optimal(A) << endl;
}