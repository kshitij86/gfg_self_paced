#include <vector>
#include <iostream>
using namespace std;

// find the peak element in an array
// peak - arr[i-1] < arr[i] > arr[i+1]

int find_peak_1(vector<int> &A){
    // O(N) time complexity
    int n = A.size();
    int res = -1;
    // if there is only one element
    // or the first element is the peak
    if((n == 1) || (A[0] >= A[1])){
        res = 0;
    }
    // if the last element is the peak
    if(A[n-2] <= A[n-1]){
        res = n-1;
    }
    // peaks are randomly present in a sorted array
    // simple linear search from the left will find the first peak
    // finds first peak from the left side
    // start at second because first is already done above
    // go till second last as last element has been checked for peak already
    for(int i=1; i<n-1; i++){
        if(A[i-1] < A[i] && A[i] > A[i+1]){
            res = i;
        }
    }
    return res;
}

int main(){
    vector<int> peak_1 = {1,2,3,4,5,6};
    cout << find_peak_1(peak_1) << endl;
}