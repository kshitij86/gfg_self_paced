#include <iostream>
using namespace std;

/**
 * 
 * TOH(N, a, b, c) = TOH(n-1, a, b, c) + (move one disk from a to c) + TOH(n-1, a, b, c)
 * 
 * a - [3,2,1] (top)
 * b - []
 * c - []
 * 
 * move top disk from a to c
 * 
 * a - [3,2] (top)
 * b - []
 * c - [1]
 * 
 * move disk 2 from a to c
 * 
 * a - [3] (top)
 * b - [2]
 * c - [1]
 * 
 *
 * move disk 1 from c to b
 * 
 * a - [3] (top)
 * b - [2,1]
 * c - []
 * 
 * move disk 3 from a to c
 * 
 * a - [] (top)
 * b - [2,1]
 * c - [3]
 * 
 * here, one of the disks is successfully placed
 * now move disk 1 to a
 * 
 * a - [1] (top)
 * b - [2]
 * c - [3]
 * 
 * move disk 2 to c
 *
 * a - [1] (top)
 * b - []
 * c - [3,2]
 * 
 * move disk 1 to c
 * 
 * a - [] (top)
 * b - []
 * c - [3,2,1]
 * 
 * total of seven steps are needed which is (2^n)-1 
 * 
 * 
 * TOH(N) = 2*TOH(N-1) + (constant work to move the disk)
 * 
 * first step is to place N-1 disks on the auxiliary tower
 * and the move one disk (largest not placed at C) to C
 * 
 * the the task is to move N-1 disks to C, so we recursively call the function 
 * for these, which is the last recursive step
 * 
 * 
 */


int toh(int n){
	// this function will compute the answer
	if(n == 1){
		return 1;
	}
	return ((2 * toh(n-1)) + 1);
}


int main(){
	int n = 4;
	cout << toh(n) << endl;
}