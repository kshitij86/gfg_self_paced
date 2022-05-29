#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int pow_naive(int n, int x){
    /**
     * Takes O(N) time, and O(N) extra recursion stack space
     */
    if(x == 0){
        return 1;
    }
    return pow_naive(n, x-1) * n;
}


int pow_optimal1(int n, int x){
    /**
     * It is based in the fact that:
     * 
     * if((x%2)==0){
     *   divide the power instead of subtracting it 
     * } else {
     *  pow(n, x-1) * n
     * }
     * 
     * This will save a lot of recursive calls as we are dividing the power and not subtracting
     * 
     * theta(logn) time and space(stack) for both
     */
    if(x == 0){
        return 1;
    }
    // only this recursive call is made and it is of the form T(n/2)
    int temp = pow_optimal1(n, x/2);
    temp = temp * temp;
    if((x%2) == 0){
        return temp;
    } 
    return temp * 2;
}

int pow_optimal2(int n, int x){
    int temp = n;
    for(int i=x; i>0; i++){
        
    }
}

int main(){
    int n = 2, x = 3;
    cout << pow_naive(n, x) << endl;
    cout << pow_optimal1(n, x) << endl;
}