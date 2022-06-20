#include <iostream>
#include <vector>
using namespace std;

// objective is to return the size of the longest even odd subarray
// which has alternating even-odd elements
// optimal approach based ion kadane's algorithm

int is_alternating(vector<int> &A, int left, int right){
    if((right - left + 1) < 2){
        return 1;
    } else if((right - left + 1) == 2){
        // e, o
        // o, e
        int f = A[0]%2;
        int l = A[1]%2;
        return f^l;
    }
    // [e,o,e,o,]
    /**
     * If first index is even, all even indexes should be even
     * else all odd indexes should be even numbers
     */
    int even_idx_parity = A[0] % 2, odd_idx_parity = A[1]%2;
    for(int i=0; i<A.size(); i++){
        if(i%2 == 0 && A[i]%2 != even_idx_parity){
            return 0;;
        }
        if(i%2 != 0 && A[i]%2 != odd_idx_parity){
            return 0;
        }
    }
    return 1;
}

int even_odd_naive1(vector<int> &A){
    // O(N^3) approach considers all subarrays
    int max_size = 1;
    for(int i=0; i<A.size(); i++){
        for(int j=i; j<A.size(); j++){
            // from this i to this j, there is a subarray
            // check if it is alternating even odd
            if(is_alternating(A, i, j)){
                // 0 3 -> 3 - 0 + 1 = 4
                int size_subarray = j - i + 1;
                max_size = max(max_size, size_subarray);
            }
        }
    }
    return max_size;
}

int even_odd_naive2(vector<int> &A){
    // O(N^2), does not use extra loop to figure out 
    // alternating array
    int res = 1;
    for(int i=0; i<A.size()-1; i++){
        int curr = 1;
        for(int j=i+1; j<A.size(); j++){
            if((A[j-1]%2==0 && A[j]%2!=0) || (A[j-1]%2!=0 && A[j]%2==0)){
                // it is an alternating sequence
                curr++;
            }
            // if not curr is not going to get updated
        }
        res = max(curr, res);
    }
    return res;
}

int even_odd_optimal(vector<int> &A){
    //
    // optimal approach is based on Kadane's algo
    // at each index we either start a new subarray
    // or we extend the previous one
    int res = 1, curr = 1; // minimum size is 1
    for(int i=1; i<A.size(); i++){
        // check for alternating
        if((A[i-1]%2==0 && A[i]%2!=0) || (A[i-1]%2!=0 && A[i]%2==0)){
            // if includign this element still gives an aklternating sequence
            // extend previous sequence
            curr++;
        } else {
            // if not alternating then only one element is part of the 
            // alternating sequence, meaning only the current element is part of this 
            // sequence

            curr = 1;
        }
        res = max(res, curr);
    }
    return res;
}

int main(){
    vector<int> A = {1,2,3,4,5,6,7,9};
    cout << even_odd_naive2(A) << endl;
}