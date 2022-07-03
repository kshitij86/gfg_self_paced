#include <vector>
#include <iostream>
using namespace std;

int idx_first_naive(vector<int> &A, int key){
    // linear search to report the first index
    for(int i=0; i<A.size(); i++){
        if(A[i] == key){
            // first occurence at index i
            return i;
        }
    }
    // not found
    return -1;
}

int idx_first_2(vector<int> &A, int key){
    // this method is no improvement as it still take O(N) time
    // first apply binary search to get to the key (any occurence)
    // traverse left until the key is not found, this is the first occurence
    int low = 0, high = A.size()-1, res = -1;
    // O(logn)
    while(low <= high){
        int mid = (low+high)/2;
        if(A[mid] == key){
            res = mid;
            break;
        } else if(A[mid] > key){
            high = mid-1;
        } else if(A[mid] < key){
            low = mid+1;
        }
    }
    // if key exists in the array
    if(res != -1){
        while((A[res] == A[res-1]) && (res >= 0)){
            res--;
        }
        return res;
    }
    return -1;
}

int idx_first_optimal_iter(vector<int> &A, int key){
    // takes O(logn) time
    // idea is to keep applying binary search even after the element is found
    // until the first ocurrence is not found
    // recursive code will work
    int low = 0, high = A.size()-1;
    while(low <= high){
        int mid = (low+high)/2;
        // either mid = 0, in which case no need to check mid-1
        // else A[mid-1] != A[mid] in any case 
        if(((A[mid] == key) && (mid > 0) && (A[mid-1] != A[mid])) || (A[mid] == key && mid == 0)){
            return mid;
        } else if(A[mid] < key){
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    // the element 
    return -1;
}

int idx_first_optimal_recursive(vector<int> &A, int key, int low, int high){
    // same as optimal but recursive code
    if(low <= high){
        int mid = (low+high)/2;
        if((A[mid] == key) && ((A[mid-1] != A[mid] && mid > 0) || (mid==0))){
           return mid; 
        } else if(A[mid] < key){
            return idx_first_optimal_recursive(A, key, mid+1, high);
        } else {
            return idx_first_optimal_recursive(A, key, low, mid-1);
        }
    }
    return -1;
}

int main(){
    int key = 10;
    // array is in non-decreasing order
    vector<int> A = {10,10,10,10};
    cout << idx_first_optimal_recursive(A, key, 0, A.size()-1) << endl;
}