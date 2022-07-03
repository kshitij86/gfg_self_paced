#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

/*
  Program to print all prime factors of a number, repeated also allowed
*/

void print_vec(vector<int> v){
  for(auto i: v){
    cout << i << " ";
  }
  cout << endl;
}

vector<int> process_sieve(vector<int> &sieve, int n){
  for(int i=2; i*i<n;i++){
    if(sieve[i]==1){
      // mark all multiples of this number as not prime
      // starts at 2 because i*1 will set a prime number to be not prime
      for(int j=2; j*i<n; j++){
        sieve[i*j] = 0;
      }
    }
  }

  return sieve;
}

vector<int> prime_factors_naive(int n){
  if(n<=1)
    return {n};
  // approach is to find all prime numbers upto that number
  // for each prime number, divide n by that prime  number
  // until possible and keep adding to the
  vector<int> sieve(n+1, 1);
  vector<int> result;
  // 1 and zero are not prime
  sieve[0] = sieve[1] = 0;
  // 0 -> not prime
  // 1 -> prime
  sieve = process_sieve(sieve, n+1);
  // print_vec(siesve);

  // keep dividing the number by i
  // until it is divisible
  // then all prime factors are gone and the same result is passed further
  // like if 24/(2^3) so we have divided by 2 3 time to get 3
  // now only this 3 will be checked for divisibility
  for(int i=2;i<sieve.size();i++){
    if(sieve[i]==1 && n%i==0){
      while(n%i==0){
        n/=i;
        result.push_back(i);
      }
    }
  }
  return result;
}

vector<int> prime_factors_optimal(int n){
  return {};
}


int main(){
  int n = 84;
  vector<int> res = prime_factors_naive(n);
  print_vec(res);
}
