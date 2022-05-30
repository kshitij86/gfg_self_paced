#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

void print_array(vector<int> arr){
    for(auto i: arr){
        cout << i << " ";
    }
    cout << endl;
}

vector<int> remove_duplicates_naive(vector<int> arr){
    // uses O(K) extra sopace, where k is the number of unique elements
    // keep track of all elements that hacve been seen
    // if seen, don't add to res array
    set<int> seen_map;
    vector<int> res;
    for(auto i: arr){
        if(seen_map.find(i) == seen_map.end()){
            // never seen before
            seen_map.insert(i);
            res.push_back(i);
        }
    } 
    return res;
}

vector<int> remove_duplicates_optimal1(vector<int> &arr){
    // not copmpletely correct, needs to handle some cases better
    // this works in O(N) time and uses O(1) extra space
    // maintian a variable that stores the element seen till now
    // and a variable that stores how many elements of the array to consider

    // temp stores that last seen element
    //  uses it tot ignore all other elements
    int temp = arr[0], k = 1;
    int max_ele = *max_element(arr.begin(), arr.end());
    for(int i=1; i<arr.size(); i++){
        if(temp == max_ele){
            break;
        }
        if(temp != arr[i]){
            // set the new element
            /**
             * [1,2,2,3]
             * 
             * temp = 2, k = 2
             * [1,2,2,3]
             *      
             *        k
             * [1,2,3,3]
             * temp = 3, k = 3
             * 
             */ 

            /**
             * [1,2,3,3,3,3,4]
             * temp = 3, k = 3
             *  
             * [1,2,3,4,3,3,4]
             * temp = 4, k = 4
             * 
             * 
             * */
            arr[k] = arr[i];
            temp = arr[i];
            k++;
        }
    }
    return arr;
}

vector<int> remove_duplicates_optimal2(vector<int> &arr){
    // takes only O(1) extra space
    int res = 1;
    for(int i=1; i<arr.size(); i++){
        if(arr[res-1] != arr[i]){
            // check with previous element is they are not same, we have seen a new element
            arr[res] = arr[i];
            res++;
        }
        /**
         * [1,2,2,3]
         * res = 1
         * 
         * [1,2,2,3]
         * res = 2
         * 
         * [1,2,3,3]
         * res = 3
         * 
         * 
         * [10, 10, 10]
         * res = 1
         * 
         * 
         */
    }
    // only consider elements upto res
    return arr;
}

int main(){
    vector<int> arr = {1,2,2,3,3,3,4};
    vector<int> naive_arr = remove_duplicates_naive(arr);
    print_array(naive_arr);


    vector<int> optimal_arr = remove_duplicates_optimal2(arr);
    print_array(optimal_arr);
}