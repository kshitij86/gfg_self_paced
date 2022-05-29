#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
using namespace std;

int second_largest_naive(vector<int> &arr){
    /**
     * this method finds the largest element first
     * and then tries to find the element which is largest in the array
     * but not equal to the largest, meaning the second largest
     * 
     * 
     * In the worst case, the second largest does not exist
     * that is if all the elements are the same
     * 
     * arr2 = [1,1,1,1]
     */
    int largest = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        largest = max(largest, arr[i]);
    }

    // now the largest is known to us, we can find second largest
    int second_largest = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] != largest){
            second_largest = max(second_largest, arr[i]);
        }
    }

    // this handles the case where there is no second largest
    return second_largest == INT_MIN ? -1 : second_largest;
}


int second_largest_optimal(vector<int> arr){
    /**
     * In a stream of numbers, we can find the largest and the second largest
     * by updating them together
     * 
     * l1 (largest), l2(second largest)
     * 
     * while traversing array following cases might occur:
     * 
     * if(a[i] > l1){
     *      we update the second largest as the previous largest is now the second largest
     *      l2 = l1  
     *      then we have found a new largest element
     *      l1 = a[i]
     * } else if(a[i] == l1){
     *      ignore as l1 points to the largest value anyway
     *      also second largest does not change in this case 
     * } else if(a[i] < largest) {
     *      in this case, we cannot ignore the element as we have to checked with the second largest yet
     *      three cases are possible
     *      if(a[i] < l2){
     *          ignore the element, it is not larger than l1 or l2
     *      } 
     *      if(l2 == -1){
     *          l2 = a[i] as we have an element smaller than the largest for the first time
     *      } if(a[i] > l2){
     *          l2 = a[i]
     *      }
     * 
     * }
     * 
     */

    // takes only one pass 
    int l1 = -1, l2 = -1;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > l1){
            // update l1 and l2 both
            // otherwise l1 info is lost
            l2 = l1;
            // now update l1
            l1 = arr[i];
        }
        if(arr[i] < l1){
            // compare with l2
            if(l2 == -1 && l2 < arr[i]){
                // if either l2 is uninitialized or there is an element
                // arr[i] such that l2 < a[i] < l1
                // so we update l2 to a[i]
                l2 = arr[i];
            }
        }
    }
    return l2;
}

int main(){
    vector<int> arr;
    for(int i=0; i<10; i++){
        arr.push_back(i);
    }

    // cout << second_largest_naive(arr) << endl;

    // // worst case array, there is no second largest
    // vector<int> arr2 = {10, 10, 10};
    // cout << second_largest_naive(arr2) << endl;

      cout << second_largest_optimal(arr) << endl;

    // worst case array, there is no second largest
    vector<int> arr2 = {10, 10, 10};
    cout << second_largest_optimal(arr2) << endl;
}

