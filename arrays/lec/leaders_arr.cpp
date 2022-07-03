#include <vector>
#include <cmath>
#include <climits>
#include <iostream>
using namespace std;

/**
 * a leader is an element at index i such that
 * A[i] > A[j], for all j > i
 * simply, all elements to the right of A[i]
 * should be smaller than A[i]
 * 
 * A = [1,2,23,3,3,4]
 * 
 * Leaders -> [23, 4]
 * (4 is trivially a leader)
 * 
 * Return all leaders of an array
 */

void print_array(vector<int> &A){
    for(auto i: A){
        cout << i << " ";
    }
    cout << endl;
}

vector<int> leaders_naive(vector<int> &A){
    // O(N^2) approach
    vector<int> res;
    res.push_back(A[A.size()-1]);
    // two loop approach
    for(int i=0; i<A.size()-1; i++){
        bool is_leader = true;
        for(int j=i+1; j<A.size(); j++){
            if(A[i] <= A[j]){
                is_leader = false;
            }
        }
        if(is_leader){
            res.push_back(A[i]);
        }
    }
    return res;
}

vector<int> leaders_optimal(vector<int> &A){
    vector<int> res;
    int max_right = A[A.size()-1];
    res.push_back(max_right);

    // if A[i] > max(A[j]) for all j > i, then we are done
    // so we need to only find the maximum element in right subarray
    // start at the second last element and trverse backwards
    // O(N) time solution
    for(int i=A.size()-2; i>=0; i--){
        if(A[i] > max_right){
            max_right = A[i];
            res.push_back(A[i]);
        }
    }
    return res;
}

// if we want leaders in the order from left to right then result of above 
// can be reversed

int main(){
    vector<int> A = {7,10,4,3,6,5,2}, B = {5,5,5,5};

    vector<int> r1 = leaders_naive(A);
    print_array(r1);

    vector<int> r2 = leaders_optimal(A);
    print_array(r2);
}