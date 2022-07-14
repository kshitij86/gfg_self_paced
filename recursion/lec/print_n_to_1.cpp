#include <iostream>
using namespace std;

void print_N(int N){
	if(N == 0){
		return;
	}
	cout << N-- << endl;
	print_N(N);
}

int main(){
	int N = 7;
	print_N(N);
}