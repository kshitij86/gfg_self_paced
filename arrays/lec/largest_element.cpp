#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
using namespace std;

int largest_element_optimal(vector<int> arr){
    // optimal O(N) approach
    // set the largest element to the smallest value possible so when the 
    // larger value is found, it gets easily updated
    int maxe = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        // this is better than writing the if condition
        maxe = max(maxe, arr[i]);
    }
    return maxe;
}


int main(){
    int n = 10;
    vector<int> arr;
    for(int i=0; i<n; i++){
        arr.push_back(i);
    }

    cout << largest_element_optimal(arr) << endl;
}