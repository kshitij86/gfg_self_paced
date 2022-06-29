#include <iostream>
#include <vector>
using namespace std;

// find the last occurence of the element in O(logn) time

int idx_last_1(vector<int> &A, int key){
    // works perfectly in O(logn) time
    int low = 0, high = A.size()-1;
    while(low <= high){
        int mid = (low+high)/2;
        if((A[mid] == key) && ((A[mid] != A[mid+1] && mid < A.size()-1) || (mid == A.size()-1))){
            return mid;
        } else if(A[mid] > key){
            high = mid-1;
        } else {
            // in the case of same elements thesearch space is moved to the right
            low = mid+1;
        }
    }
    return -1;
}

int main(){
    // expected answer = 5
    int key = 5;
    vector<int> A = {1,2,3,3,3,3};
    // naive approach will start from right
    // optimal applied modification of binary search
    cout << idx_last_1(A, key) << endl;
}