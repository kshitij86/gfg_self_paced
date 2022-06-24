#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * n-bonnaci number are where the ith number is given by 
 * the sum of n elements before it. By this logic, fibonacci numbers
 * are 2-bonacci numbers.
 * 
 * e.g. 
 * n = 3, m = 10
 * 
 * first n numbers in the series = [0, 0, 1]
 * 
 * first 10 3-bonacci numbers  = [0,0,1,1,2,4,7,13,24,44]
 * 
 * wap to compute the first m, n-bonacci  numbers
 * 
 */

void print_vec(vector<int> &A){
      for(auto i: A) {
        cout << i <<  " ";
    }
    cout << endl;
}

vector<int> n_bonacci(int n, int m){
    // uses O(m) extra space for n-bonacci numbers
    // based on sliding window technique
    int sum_n = 1;
    vector<int> res(m, 0);
    res[n-1] = 1;
    // go only less than m-n if starting at zero
    // finally we have m-n - 0 + 1 -> m-n+1 windows to consider
    for(int i=0; i<m-n; i++){
        res[i+n] = sum_n;
        sum_n -= res[i];
        sum_n += res[i+n];
    }
    return res;
}


int main(){
    int n = 3, m = 10;
    vector<int> res = n_bonacci(n, m);
    print_vec(res);
}
