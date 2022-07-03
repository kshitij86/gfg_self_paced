#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
using namespace std;

void move_zeroes_to_end_naive1(vector<int> &arr){
    // O(N) extra space to store elements in external array
    vector<int> res;
    int zero_count = 0;
    for(auto i: arr){
        if(!i){
            zero_count++;
        }
    }
    for(auto i: arr){
        if(i){
            res.push_back(i);
        }
    }
    while(zero_count--){
        res.push_back(0);
    }
    arr = res;
}

// note array should be passed as reference to modify it
void move_zeroes_to_end_naive2(vector<int> &arr){
    // O(N^2) time complexity for two loops
    // the idea is the first find a zero element
    // after that find a non-zero value to the right of it
    // swap them both
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == 0){
            // now go and find the first corresponding non-zero element
            for(int j=i+1; j<arr.size(); j++){
                if(arr[j] != 0){
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
}

void move_zeroes_to_end_optimal(vector<int> &arr){
    /**
     * It takes only one pass of the array
     * Idea is based on the fact that if we have an array
     * a1, a2, a3, 0,0,0
     * then if the next element processed is a zero, there is no need to do anything
     * otherwise swap with the first zero and increment count
     * count = count of non zero elements from left of the array
     * 
     * count will point to the first zero, so move ahead in the array 
     * and i will keep moving on
     * 
     * if the array starts with non-zero el;ements, then we swap them by themselves
     * otherwise, we swap non zero with zero as all are identical
     *  
     * {10, 5, 0, 0, 8, 9, 0}
     * count  = 0
     * i = 0, swap(arr[0], arr[0]), count = 1
     * i = 1, swap(arr[1], arr[1]), count = 2
     * i = 2,
     * i = 3, 
     * i = 4, swap(arr[4], arr[2]), count = 3
     * i = 5, swap(arr[5], arr[3]), count = 4 {10,5,8,9,0,0,0}
     */

    int count = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] != 0){
            swap(arr[i], arr[count]);
            count++;
        }
    }

}

int main(){
    vector<int> arr = {10, 5, 0, 0, 8, 9, 0};
    move_zeroes_to_end_optimal(arr);
    for(auto i: arr){
        cout << i << " ";
    }
    cout << endl;
}