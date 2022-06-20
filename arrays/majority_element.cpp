#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// return the majority element if it exists
// majority element is one that should appear more than 
// floor(A.size()/2) times
// return -1 if it does not exist

int majority_naive(vector<int> &A){
    // O(N) approach with O(max_element) extra space
    // much of the space is wasted in case of sparse array
    // not optimal as it uses extra space
    int largest = *max_element(A.begin(), A.end());
    vector<int> freq(largest, 0);

    for(int i=0; i<A.size(); i++){
        freq[A[i]]++;
    }
    int majority = A.size()/2;
    for(int i=0; i<freq.size(); i++){
        if(freq[i] > majority){
            return i;
        }
    }
    return -1;
}

int majority_optimal(vector<int> &A){
    // Moore's voting algoithm - O(N) with O(1) space
    // https://www.geeksforgeeks.org/boyer-moore-majority-voting-algorithm/
    // it has two variables res and count
    // res points to the index of the majority element
    // it has two phases
    // PHASE - 1 will find out the index of the majority element
    // PHASE - 2 will verify if the element found in PHASE - 1 is majority or not
    // it is not guaranteed to return the first index of majority element
    
    // PHASE  - 1
    int res = 0; // the index of majority, assumed first element in beginning
    int count = 1; // the count of said majority element
    for(int i=1; i<A.size(); i++){
        if(A[res] == A[i]){
            count++;
        } else {
            count--;
        }
        if(count == 0) {
            // reset the index and count
            res = i;
            count = 0;
        }

    }

    // PHASE - 2
    // res now has the majority element index, if it exists
    count = 0;
    for(int i=0; i<A.size(); i++){
        if(A[res] == A[i]){
            count++;
        }
    }
    if(count  > (A.size()/2)){
        // return the index of majority
        return res;
    }
    // if no majority exists
    return -1;
}


int main(){
    // 1 is the majority
    vector<int> A = {1,1,1,1,1,1,1};
    // cout << majority_naive(A) << endl;
    cout << majority_optimal(A) << endl;
}