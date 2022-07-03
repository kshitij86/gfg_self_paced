#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void printVec(vector<int> &A, int i, int j){
    for(int k=i; k<=j; k++){
        cout << A[k] << " ";
    }
    cout << endl;
}

void merge(vector<int> &arr, int left, int mid, int right){

    int n1 = mid - left  + 1;
    int n2 = right - mid;
    
    vector<int> arr1, arr2;

    for(int i=left; i<=mid; i++){
        arr1.push_back(arr[i]);
    }

    for(int i=mid+1; i<=right; i++){
        arr2.push_back(arr[i]);
    }

    // p1 -> pointer for arr1
    // p2 -> pointer for arr2
    // p3 -> starts from left as elements before irt may already be placed
    int p1 = 0, p2 = 0, p3 = left;
    while(p1 < n1 && p2 < n2){
        if(arr1[p1] <= arr2[p2]){
            arr[p3] = arr1[p1];
            p1++;
        } else {
            arr[p3] = arr2[p2];
            p2++;
        }
        p3++;
    }

    // copy the remaining elements
    while(p1 < n1){
        arr[p3] = arr1[p1];
        p1++;
        p3++;
    }
        while(p2 < n2){
        arr[p3] = arr2[p2];
        p2++;
        p3++;
    }
}

void merge_sort(vector<int> &arr, int left, int right){
    if(left < right){
        // printVec(arr, left, right);
        int mid = (left + right) / 2;
        // recursively call till there is only 
        // one element in the array
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        // then start merging for each pairs of arrays
        merge(arr, left, mid, right);
    }
}   

int main(){
    vector<int> arr = {5,4,3,6,2,1};
    int n = arr.size();
    merge_sort(arr, 0, n-1);

    printVec(arr, 0, n-1);
}