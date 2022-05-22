#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

/**
  Program to print all divisors of a number in increasing order
*/

void print_vec(vector<int> v){
  for(auto i: v){
    cout << i << " ";
  }
  cout << endl;
}

vector<int> print_divisors_naive(int n){
  // brute force solution
  vector divisors = {1};
  for(int i=2; i<=n;i++){
    if(n%i==0){
      divisors.push_back(i);
    }
  }
  return divisors;
}

vector<int> print_divisors_optimal(int n){
  // divisors of a number always appear in pairs
  // one before sqrt(n) and one after
  // if (x, y) is the number pair, then y = n/x
  // so we need to only go until the sqrt(n)
  // this approach works but does not give divisors in sorted order
  vector<int> divisors;
  for(int i=1; i*i<=n; i++){
    if(n%i==0){
      divisors.push_back(i);
      divisors.push_back(n/i);
    }
  }
  return divisors;
}

vector<int> print_divisors_optimal_sorted(int n){
  vector<int> divisors;
  // go from 1 to sqrt(n)
  // this will help get all the smaller divisors first
  for(int i=1;i*i<=n;i++){
    if(n%i==0){
      divisors.push_back(i);
    }
  }

  //
  for(int i=1;i*i<=n;i++){
    if(n%i==0){
      divisors.push_back(i);
    }
  }
}

int main(){
  int n = 1000000;
  // naive approach
  vector<int> r1 = print_divisors_naive(n);
  print_vec(r1);

  cout << endl;

  // optimal sqrt(n) approach
  vector<int> r2 = print_divisors_optimal(n);
  print_vec(r2);
}
