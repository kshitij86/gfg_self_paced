#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int gcd_naive(int a, int b){
  // min_limit is taken and not maximum as
  // gcd(a,b) <= min(a,b)
  // example -> a = 10, b = 50
  // any number >10 will not divide 10 and will not be a divisor (e.g. 11)
  //Time Complexity - O(min(a,b))
  int min_limit = min(a,b);
  int gcd_ans = 0;
  for(int i=2; i<=min_limit; i++){
    if((a%i==0) && (b%i==0)){
      gcd_ans =max(i,gcd_ans);
    }
  }
  return gcd_ans;
}

int gcd_optimal(int a, int b){
  // euclid algorithm
  //  it is based on the hypothesis that
  // gcd(a,b) = gcd(a,a-b)
  // If a = b(q) + r
  // then gcd(a,b) = gcd(b,r)
  // Example - gcd(6,4)
  // 6 = 4(1) + 2
  // so as the first part (4*1) is a factor of 6 (technically) we can focus
  // only on the remainder
  // 4 = 2(2) + 0
  // so the last non zero reaminder comes out to be gcd (2 here)
  if(b==0){
    return a;
  }
  // we return gcd(b, a%b) as a>b initially and then we write
  // a = b(q) + r, so now b is techincally >= r
  // so r = a%b is atmost b and b will be larger too
  return gcd_optimal(b, a%b);
}

int main(){
  int a = 4, b = 5;
  cout << gcd_optimal(a,b) << endl;
}
