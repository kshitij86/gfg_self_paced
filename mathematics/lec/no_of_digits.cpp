#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int count_digits_naive(int a){
  int digits = 0;
  while(a){
    digits++;
    a /= 10;
  }
  return digits;
}

int main(){
  int a = 123;
  // O(k), where k is the number of digits
  cout << count_digits_naive(a) << endl;

  // O(1) time operation
  cout << floor(log10(a) + 1) << endl;
}
