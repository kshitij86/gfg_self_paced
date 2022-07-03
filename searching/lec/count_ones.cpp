#include <vector>
#include <iostream>
using namespace std;

// count the number of ones in a sorted binary array
// binary arrays only consist of bits

int count_ones(vector<int> &A){
    // similar idea to count frequency of all elements
    // in a sorted array using binary search
    int last_pos = -1, first_pos = -1;
    int low = 0, high = A.size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        if((A[mid] == 1) && ((A[mid-1] != A[mid] && mid > 0) || (mid==0))){
            first_pos = mid;
            break;
        } else if(A[mid] < 1){
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    low = 0;
    high = A.size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        if((A[mid] == 1) && ((A[mid+1] != A[mid] && mid<A.size()-1) || (mid==A.size()-1))){
            last_pos = mid;
            break;
        } else if(A[mid] > 1){
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    if(first_pos + last_pos >=0){
        return (last_pos - first_pos + 1);
    }
    return 0;
}

int main(){
    // key is by default 1
    vector<int> A = {0,0,0,1,1,1};
    cout << count_ones(A) << endl;
}