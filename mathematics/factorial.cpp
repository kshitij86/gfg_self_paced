#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

/**
  Recurrence:
    T(n) = T(n-1) + theta(1)
    The theta(1) work is done in checking the condition and doing the multiplication in line 26

    Time complexity - theta(n) [for both iterative and recursive]
    Space Complexity -
        theta(1) for iterative code
        theta(n) for recursive stack in recursive code
    Recursive code does unnecessary work and can be memoized
*/

int factorial_iterative(int n){
  int res = 1;
  for(int i=1; i<=n; i++){
    res *= i;
  }
  return res;
}

int factorial_recursive(int n){
  if(n == 1){
    return n;
  }
  return n * factorial_recursive(n-1);
}

int main(){
  int n = 3;
  cout << factorial_iterative(n) << endl;
  cout << factorial_recursive(n) << endl;

}
