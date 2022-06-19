#include <bits/stdc++.h>
using namespace std;

int max_sum_naive(vector<int> &A){
    int n = A.size();
    int max_global = INT_MIN;
    // O(N^3)
    // consider each subarray and find it sum
    // maintain a global maximum
    for(int i=1; i<=n; i++){
        // i = 1
        for(int j=0; j<=n-i; j++){
            int l = i + j - 1;
            int max_local = 0;
            for(int k=j; k<=l; k++){
                max_local += A[k];
            }            // cout << max_local << endl;
            // one subarray is considered
            max_global = max(max_global, max_local);
        }
    }
    return max_global;
}


int kadane_self(vector<int> &A){
    int max_global = INT_MIN, sum_local = 0;
    for(int i=0; i<A.size(); i++){
        if(A[i] > 0){
            sum_local += A[i];
        } else {
            sum_local = 0;
        }
        max_global = max(sum_local, max_global);
    }
    return max_global;
}

int kadane(vector<int> &A){
    // the ides of kadane is simple
    // maintain two values, one for local sum
    // and one for global sum
    // [5,-1,2,10,-4]
    // m = 5, res = 5, i=1
    // m=5, res=5, i=2
    int res = A[0];   
    int maxEnding = A[0];
    for(int i=1; i<A.size(); i++){
        maxEnding = max(maxEnding + A[i], A[i]);
        res = max(res, maxEnding);
    }
    return res;
}  

int main(){ 
    vector<int> A = {-5,1,-2,3-1,2,-2};
    cout << kadane_self(A) << endl;
    cout << kadane(A) << endl;
}