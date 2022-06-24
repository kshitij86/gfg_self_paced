#include <vector>
#include <iostream>
using namespace std;

// flipping consecutive zeroes or ones is allowed
// find the minimum number of flips needed to make all elements same
// you can either flip zeroes or ones, but not both

// O(N^2) approach
int min_flips(vector<int> &A){
    // idea is to count the number of consecutive ones and zeroes
    // which has smaller number of consecutive ones will need smaller number of  flips
    // example - [0,0,0,1,1,1,1,0,0,0]
    // zero has two groups and ones have only one
    // so one flip from [3 - 6] is enough
    int n = A.size();
    int one_grps = 0, zero_grps = 0;
    // count one groups 
    for(int i=0; i<n; ){
        if(A[i] == 1){
            while(A[i] == 1 && i < n){
                i++;
            }
            one_grps++;
        } else {
            // this element is a zero
            i++;
        }
    }
    for(int i=0; i<n; ){
        if(A[i] == 0){
            while(A[i] == 0 && i < n){
                i++;
            }
            zero_grps++;
        } else {
            // this element is a zero
            i++;
        }
    }
    return min(one_grps, zero_grps);
}

// one fact to note about these is in binary strings, the number of groups of zero and one
// differ by atmost one
// 100011101 -> if starting and ending digit is same, they differ by one
// 10001000100 -> if different, they (groups) are same in number
// it works on the fact that let some bit be added to empty string
// "111" -> now if zeroes are added, then the groups are same in number
// "11100" -> now in this if more ones are added then the number will differ by one
// "111001111" -> so it makes sense to count those bits in the second group (00 here)
int min_flips_single_pass(vector<int> &A){
    
}

int main(){
    vector<int> A = {0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0};
    cout << min_flips(A) << endl;
}