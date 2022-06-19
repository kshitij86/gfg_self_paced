#include <vector>
#include <iostream>
using namespace std;

void print_vector(vector<int> &A, int start, int end){
    for(int i=start; i<end; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(vector<int> &A, int start, int end){
    int i = start-1;
    int j = start;
    int pivot = A[end];
    while(j < end){
        if(A[j] < pivot){
            i += 1;
           swap(&A[i], &A[j]);
        }
        j++;
    }
    // at this step A[end] and A[i+1] should be swapped
    swap(&A[i+1], &A[end]);
    return i+1;
}

void quick_sort(vector<int> &A, int start, int end){
    // print_vector(A, 0, A.size());
    if(start < end){
        int x = partition(A, start, end);
        quick_sort(A, start, x-1);
        quick_sort(A, x+1, end);
    }
}

int main(){
    vector<int> A = {2,1};
    quick_sort(A, 0, A.size()-1);
    print_vector(A, 0, A.size());

}