#include <iostream>
using namespace std;

void print_1(int i, int N){
	if(i > N){
		return;
	}
	cout << i++ << endl; 
	print_1(i, N);
}

int main(){
	int N = 7, i = 1;
	print_1(i, N);
}