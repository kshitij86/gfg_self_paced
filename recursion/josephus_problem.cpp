#include <vector>
#include <iostream>
using namespace std;

/**
 * 
 * n people fron 0 to n-1 are standing in a circle
 * 
 * then the k-1th person is killed first
 * 
 * after that gun is handed to the person chronologically next
 * the guy at kth position from the gun holder is killed
 * 
 * [0,1,2,3,4,5,6] (2 is killed, gun goes to 3)
 * [0,1,3,4,5,6] (5 is killed, gun goes to 6)
 * [0,3,4,6] (1 is killed, gun goes to 3)
 * [0,3,4] (6 is killed)
 * [0,3] (4 is killed)
 * [3] (0 is killed)
 * 
 * the answer is always the last standing man
 * 
 * 
 */

// void recur(vector<int> &A, int k, int *ans, int killer, int itr){
// 	// the iteration number has to be A.size()-1
// 	// because each iteration one person is killed and
// 	// if there is only one person left, there must have been
//  	// n-1 iterations
// 	if(A.size() == 1 && itr == A.size()-1){
// 		*ans = A[0];
// 		return;
// 	}
// 	// need to decide whom to remove and whom to hand gun to for 
// 	// next round
// 	int killed;
// 	if(itr == 0){
// 		// only in this iteration is the 
// 		// killer value k-1
// 		killed = killer;
// 	} else {
// 		killed = ((killer + 2) % k);
// 	}
// 	// remove the person from consideration
// 	A.erase(A.begin() + killed);
// 	// hand gun to next person
// 	killer = (((killer + 3) % k));
// 	// do it again
// 	recur(A, k, ans, killer, itr+1);
// }

// int josephus(int n, int k){
// 	int ans = -1;
// 	vector<int> A;
// 	for(int i=0; i<n; i++){
// 		A.push_back(i);
// 	}
// 	int killer = k-1;
// 	int itr = 0;
// 	recur(A, k, &ans, killer, itr);
// 	return ans;
// }

int jos(int n, int k){
	if(n == 1){
		return 0;
	}
}

int main(){
	int n = 7, k = 3;
	cout << josephus(n, k) << endl;
}