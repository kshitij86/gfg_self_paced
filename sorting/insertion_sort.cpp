#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> &A, int start, int end){
    for(int i=start; i<end; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void insertion_sort(vector<int> &A){
    int n = A.size();
    for(int i=1; i<n; i++){
        int key = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

int main(){
    vector<int> A = {5,1,2,3,4,6};
    insertion_sort(A);
    print_vector(A, 0, A.size());
}