#include <vector>
#include <iostream>
using namespace std;

// an array is sorted and is then rotated
// in this we don't know how many times the array is sorted
// we can observe a special property

int search_rotated_sorted_1(vector<int> &A, int key){
    int n = A.size();
    // in a rortated sorted array, find the point where 
    // it has been rotated
    // here arr[i+1] is the first element of the array
    // use binary search for this as well
    // using binary search to figure out which 
    // half to search in
    // in a rotated sorted array, one half (n/2) of the array will
    // always be sorted
    // so find out that half and apply search to it
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(A[mid] == key){
            return mid;
        } else if(A[low] < A[mid]){
            // in this case the left half is sorted
            // for the current subarray
            if(A[low] < key && key <= A[mid]){
                // the key lies in the range [low, mid]
                high = mid-1;
            } else {
                // it lies in a subarray to the right
                low = mid+1;
            }
        } else {
            // in this case definitely the right array is sorted
            if(A[mid] < key && key <= A[high]){
                // key lies in the range [mid, high]
                low = mid+1;
            } else {
                // it lies in a subarray to the left
                high = mid-1;
            }
        }
    }
    return -1;
}

int main(){
    int key = 4;
    vector<int> A = {4,5,1,2,3};
    cout << search_rotated_sorted_1(A, key) << endl;
}