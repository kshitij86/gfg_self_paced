#include <vector>
#include <iostream>
using namespace std;

/** Time complexity - O(logn) 
 */

int bin_search_iter(vector<int> &A, int key){
    int low = 0, high = A.size()-1;
    // equal to is important because when element is found
    // they will point to same index
    while(low <= high){
        int mid = (low + high)/2;
        if(A[mid] == key){
            // if found returns here
            return mid;
        } else if(A[mid] > key){
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    // not found here
    return -1;
}

int bin_search_recur(vector<int> &A, int low, int high, int key){

    // if low has crossed high then element is not in array
    if(low <= high) {
        int mid = (low + high)/2;
        if(A[mid] == key){
            return mid;
        } else if(A[mid] > key){
            return bin_search_recur(A, low, mid-1, key);  
        } else if(A[mid] < key){
            return bin_search_recur(A, mid+1, high, key);
        }
    }
    // not found so return -1
    return -1;
}

int main(){
    int key = 10;
    vector<int> A = {1,2,3,4,5,6,7,8};
    // cout << bin_search_iter(A, key) << endl;
    cout << bin_search_recur(A, 0, A.size()-1, key) << endl;
}