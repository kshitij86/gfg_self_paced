#include <iostream>
using namespace std;

// find the square root of a given number

int sqrt_1(int x){
    // this takes O(sqrt(x)) of time
    // but this is not optimal 
    int i=1; 
    while(i*i <= x){
        i++;
    }
    return i-1;
}

int sqrt_2(int x){
    // O(logn) complexity
    // idea is to set mid according to its square
    // find sqrt using binary search
    // the numbers from 1 to x are in sorted order
    // treat this range as a sorted array
    int low = 1, high = x;
    while(low <= high){
        int mid = (low+high)/2;
        if((mid*mid <= x )&& ((mid+1)*(mid+1) > x)){
            // in this case, it is guaranteed
            // sqrt(x) lies in [mid, mid+1)
            return mid;
        } else if(mid*mid > x){
            // the number is too large
            high = mid-1;
        } else {
            // the number at mid is too small
            low = mid+1;
        }
    }
    return -1;
}

int main(){
    // expected output = 6
    int x = 900;
    cout << sqrt_2(x) << endl;
}