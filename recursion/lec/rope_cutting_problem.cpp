#include <iostream>
using namespace std;

/**
 * given a piece of rope, we need to make either a or b or c cuts in it and get
 * the maximum number of pieces possible
 * 
 * n = 5, a = 2, b = 5, c = 1
 * 
 * five pieces of length 1 will be enough
 * that is the maximum also
 * 
 * for recursive code, it is only possible if at the end there are no pieces left
 * that is the effective length at the end is zero
 * 
 * if no cuts could be made or the effective length is not zero at the end
 * we can say no way of doing so
 * 
 */

void recur(int n, int a, int b, int c, int *max_cuts, int ways){
	// if at any time the rope length is zero means that
	// this is a valid cut using a and b and c
	// and so the cuts made here will matter
	// an could possibly be the maximum
	if(n == 0){
		// cout << ways << endl;
		*max_cuts = max(ways, *max_cuts); 
		return;
	}
	// if we get a non-negative length after subtraction
	// make that call otherwise no need as it is invalid
	if((n - a) >= 0){
		recur(n-a, a, b, c, max_cuts, ways+1);
	}
	if((n - b) >= 0){
		recur(n-b, a, b, c, max_cuts, ways+1);
	}
	if((n - c) >= 0){
		recur(n-c, a, b, c, max_cuts, ways+1);
	}
}

int max_rope(int n, int a, int b, int c){
	int max_cuts = 0;
	// max_cuts passed as reference to modify
	// directly, others no need 
	recur(n, a, b, c, &max_cuts, 0);
	// if some ways exist then return the max
	// otherwise just -1
	return max_cuts ? max_cuts : -1;
}

int main(){
	int n = 9, a = 2, b = 2, c = 2;
	cout << max_rope(n, a, b, c) << endl;
}