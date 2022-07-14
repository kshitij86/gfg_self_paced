#include <iostream>
using namespace std;

int natural_sum(int N, int sum){
	if(N == 0){
		return sum;
	}
	return natural_sum(N-1, sum+N);
}

int main(){
	int N = 3;
	cout << natural_sum(N, 0) << endl; 
}