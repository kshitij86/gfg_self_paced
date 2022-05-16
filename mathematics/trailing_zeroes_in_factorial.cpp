#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

/**
  Function will return count of trailing zeroes in n!
*/

int trailing_count_naive(int n){
  int res = 1;
  for(int i=2; i<=n; i++){
    res *= i;
  }
  // cout << res << endl;
  int count_zeroes = 0;
  // check the number while it is divisible by 10;
  while((res%10) == 0){
    count_zeroes++;
    res /= 10;
  }
  return count_zeroes;
}

int trailing_count_efficient(int n){
  // one observation to make is that only '5' and '2' are going to contribute zeroes
  // if a number can be factorized as - (5^x) * (2^y) * k
  // where k is product of the rest of the factors, the number of zeroes
  // in n! will be min(x, y)

  /**
    Important point - There will always be lesser 5's than 2's,
        so only counting 5's is sufficient
    Time Compexity - theta(log(n)base5)
  */
  int res = 1;
  for(int i=2; i<=n; i++){
    res *= i;
  }
  // now res has the factorial of given number
  // now find the highest powers of 5 and 2 in n!
  int high_5 = 0, high_2 = 0;
  int temp = res;
  while((temp%5) == 0){
    high_5++;
    temp /= 5;
  }
  // redundant as number will always have lesser 5's and counting 5's
  // is sufficient
  // reset temp value to find power of 2
  // temp = res;
  // while((temp%2) == 0){
  //   high_2++;
  //   temp /= 2;
  // }
  // note: in each while loop we only need to loop until we exhaust all 2's or 5's
  // example -> 100 = (5^2) * (2^2)
  // when 100 is divided by 2 twice, all 2's are gone can high_2 = 2
  return high_5;
}



int main(){
  int n = 10;
  // cout << trailing_count_naive(n) << endl;
  cout << trailing_count_efficient(n) << endl;
}
