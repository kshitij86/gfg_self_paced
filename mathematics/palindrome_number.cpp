#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

string is_palindrome(int n){
  // successfully returns the palindrome status of a number
  /**
    Here i is used to keep track of the index
    But i is not really needed, below code has same effect:
    while(copy_n){
      int rem = copy_n % 10;
      rev *= 10;
      rev += rem;
      copy_n /= 10;
    }
  */
  int rev = 0, copy_n = n, i = 0;
  string b;
  int count_digits = floor(log10(n)+1);
  while(copy_n){
    int rem = copy_n % 10;
    rev += rem * pow(10, count_digits - i - 1);
    i++;
    copy_n /= 10;
  }

  cout << rev << endl;
  b = rev == n ? "Yes" : "No";
  return b;
}

int main(){
  int n = 363;
  cout << is_palindrome(n) << endl;
}
