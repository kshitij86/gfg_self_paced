#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

int is_sorted_naive(vector<int> arr){
    /**
     * this will take each element and check if there is a larger element to the right
     * if there is, then the array is not sorted
     * else it is sorted
     * 
     * the catch is that this array takes two loops - in one loop more than 
     * optimal approach
     */

    // O(N^2) approach
    for(int i=0; i<arr.size()-1; i++){
        for(int j= i+1; j<arr.size(); j++){
            if(arr[i] > arr[j])
                return false;
        }
    }
    return true; 
}

int is_sorted_optimal(vector<int> arr){
    // check if array is sorted in one pass of the array
    // we assume that input can contain duplicates, so
    // we are verifying that the array is in non-decreasing order
    /**
     * if for all i, 0 <= i <= arr.size()-1 the followijng condition holds
     * arr[i] <= arr[i+1], then we can say that the array is sorted
     * 
     */

    // O(N) time solution
    // go only until the second last element to avoid comaprison with
    // garbage values
    for(int i=0; i<arr.size()-1; i++){
        // > to check for non-decreasing order
        // which means that <= is allowed
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;

}

int main(){
    vector<int> arr = {1,5,3,3,4};
    cout << is_sorted_naive(arr) << endl;    
    cout << is_sorted_optimal(arr) << endl;    
}