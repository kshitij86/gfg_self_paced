#include <iostream>
using namespace std;

/**
 * 0123
 * abba
 * 
 * 01234
 * abbba
 * 
 */

bool is_palindrome(string x, int n, int i){
	// checks if given string is a palindrome
	if(i > (n/2-1)){
		// base case 1
		// i exceeds middle
		return true;
	}
	if(x[i] != x[n-i-1]){
		// base case 2
		// some chars from front and end do not match
		return false;
	}
	// everything fine for now, go further
	return is_palindrome(x, n, i+1);
}

int main(){
	string x = "aba";
	int n = x.length();
	cout << is_palindrome(x, n, 0) << endl;
}