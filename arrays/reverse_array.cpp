#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
using namespace std;

void print_array(vector<int> arr){
    if(arr.size() == 0){
        cout << "<empty>" << endl;
        return;
    }
    for(auto i: arr){
        cout << i << " ";
    }
    cout << endl;
}

void reverse_array_optimal(vector<int> &arr){
    // if the length is odd, we can swap the elements like
    // swap(arr[i], arr[arr.size() - i - 1])
    // the middle element can be left as it is
    /*
        Depending on the value of the length of the array, 
        we can set the mid value

        if odd, then go until floor(arr.size()/2)
        else go until ((arr.size()/2)-1)
    */
    int mid; 
    if(arr.size()%2 != 0){
        // odd length
        mid = arr.size()/2;
    } else {
        // 0 1 2 3
        mid = (arr.size()/2)-1;
    }
     for(int i=0; i<mid; i++){
        int temp = arr[i];
        arr[i] = arr[arr.size() - i - 1];
        arr[arr.size() - i - 1] = temp;
    }
}

int main(){
    // this solution modifies the vector in place
    vector<int> empty = {};
    vector<int> even_len = {1,2,3,4,5,6};
    vector<int> odd_len = {1,2,3,4,5,6,7};

    // call the function
    reverse_array_optimal(empty);
    reverse_array_optimal(even_len);
    reverse_array_optimal(odd_len);

    // print the array
    print_array(empty);
    print_array(odd_len);
    print_array(even_len);


}