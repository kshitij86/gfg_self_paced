#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int gcd(int a, int b){
  // Euclidean GCD
  if(b == 0){
    return a;
  }
  return gcd(b, a%b);
}

int lcm_naive(int a, int b){
  // Takes O(N) time to compute or O(a*b - max(a,b) + 1) as the range of i
  // is defined using these numbers
  // to find lcm, it can be maximum a*b if a and b are co-prime
  for(int i=max(a,b); i<=a*b; i++){
    if((i%a==0) && (i%b==0)){
      // since we are staring from small numbers and going to larger ones
      // the smallest number here is the lcm
      return i;
    }
  }
  return -1;
}

int lcm_optimal(int a, int b){
  // optimal, O(log(min(a,b))) solution which is finding gcd
  int prod = a * b;
  /**
   Based on the idea that lcm * hcf = a * b
   So, lcm = (a*b)/hcf
  */
  int x = gcd(a, b);

  return prod/x;
}

int main(){
  int a = 6, b = 4;
  cout << lcm_naive(a, b) << endl;
  cout << lcm_optimal(a, b) << endl;
}
