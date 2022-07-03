#include <vector>
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

// only a given number has to be identified as prime
// not all numbers below it, so sieve is not needed and can be overhead

bool is_prime_naive(int n){
  // O(n) approach
  // only range - [2, n-1] is checked as n always divides n
  // at best only n-2 numbers are checked
  if(n == 1){
    return false;
  }
  for(int i=2; i<n; i++){
    if(n%i==0){
      // if any number smaller than n and other than 1 divides it
      // return false as it has other factor
      return false;
    }
  }
  return true;
}

bool is_prime_optimal1(int n){
  // O(sqrt(n)) approach
  // in worst case we only need to check until the sqrt of the number
  // if n = 66, floor(sqrt(n)) = 8
  // factors of 66 = 11 and 6, and ony factor is guaranteed to be < sqrt(n)
  // here it is 6
  // so we check only until sqrt(n)
  // if x*x <= n
  // then x = sqrt(n)
  if(n==1){
    return false;
  }

  // check this case before checking for n%2 and n%3 because
  // 2 and 3 will satisfy and give wrong answer
  if(n==2 || n==3){
    return true;
  }
  // added to avoid checking multiples of 2 and 3
  // this step can save a lot of iterations as
  // the number that is divisible by 2 or 3
  // then numbers like 6, 12, 18, 21, etc. also can be skipped in loop
  // and only true primes like 11, 19, 17 etc. will be cheked in loop
  if((n%2 ==0) || (n%3==0)){
    return false;
  }
  // we can begin at 5 because 2 and 3 are already covered
  // so the next prime number is 5
  for(int i=5; i<sqrt(n); i+=6){
    if((n%i==0) ||(n%(i+2)==0)){
      return false;
    }
  }
  return true;
}

void format_op(int x){
  x ? cout << "Yes" : cout << "No";
  cout << endl;
}

int main(){
  int n = 67;
  format_op(is_prime_optimal1(n));
  format_op(is_prime_naive(n));
}
