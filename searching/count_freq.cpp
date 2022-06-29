#include <iostream>
#include <vector>
using namespace std;

// given a sorted array, count the occurences of a given key

int count_freq(vector<int> &A, int key){
    // total complexity is O(logn + logn) -> O(logn)
    // the approach is pretty simple
    //  find the first occurence and last occurence of the 
    // corresponding elements
    // between first_pos & last_pos, there are exactly
    // last_pos - first_pos + 1 elements
    int first_pos = -1, last_pos = -1;
    // find the first occurence of key
    // the focus is to move the search to the left in case of duplicates
    int low = 0, high = A.size()-1;
    while(low <= high){
        int mid = (low+high)/2;
        if((A[mid] == key) && ((A[mid] != A[mid-1] && mid > 0) || (mid==0))){
            first_pos = mid;
            break;
        } else if(A[mid] < key){
            low = mid+1;
        } else {
            // handles the case A[mid] == key and not the first occurence
            // and also when A[mid] > key
            // when high move to the left, the search also moves left
            high = mid-1;
        }
    }
    // repeat for last_pos
    // the focus in this case is to move the search to the right to find last 
    // occurence
    low = 0; 
    high = A.size()-1;
    while(low <= high){
        int mid = (low+high)/2;
        if((A[mid] == key) && ((A[mid] != A[mid+1] && mid < A.size()-1) || (mid==A.size()-1))){
            last_pos = mid;
            break;
        } else if(A[mid] > key){
            high = mid-1;
        } else {
            // handles the case when A[mid] < key
            // and A[mid] == key also
            low = mid+1;
        }
    }

    if(last_pos + first_pos >= 0){
        // return the exact number of occurences of key
        return (last_pos - first_pos + 1);
    }
    // there are no occurences of this element
    return 0;
}

int main(){
    int key = 4;
    vector<int> A = {1,2,3,3,3,3,3,4,4};
    cout << count_freq(A, key) << endl;
}