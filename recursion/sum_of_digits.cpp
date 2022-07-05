#include <iostream>
using namespace std;

int sum_of_digits(int x, int sum){
	if(x == 0){
		return sum;
	}
	return sum_of_digits(x/10, sum+(x%10));
}

int main(){
	int x = 123456;
	cout << sum_of_digits(x, 0) << endl;
}