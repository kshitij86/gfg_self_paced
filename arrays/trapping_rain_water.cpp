#include <bits/stdc++.h>
using namespace std;

int trap_water(vector<int> &A) {
  // for every index the left max and right max can be found
  // then the amount of water that can be stored at a certain index
  // is equal to the min(lMax, rMax) - A[i]
  // O(N^2) approach, not efficient
  int res = 0;
  for (int i = 1; i < A.size() - 1; i++) {
    int lMax = INT_MIN, rMax = INT_MIN;
    // left maximum bar height
    for (int j = 0; j < i; j++) {
      lMax = max(lMax, A[j]);
    }
    // right maximum bar heigth
    for (int j = i; j < A.size(); j++) {
      rMax = max(rMax, A[j]);
    }
    /**
     * |
     * |  |
     * |__|
     *
     * we can only store min(3,2) = 2 amount of water not 3
     */
    res += min(rMax, lMax) - A[i];
  }
  return res;
}

int trap_water_optimal(vector<int> &A) {
  // to avoid computing left and right each time
  //  it is better to pre-compute and store it (memoize)
  int n = A.size();
  int lMax[n], rMax[n], res = 0;
  // set first element as going from l to r
  lMax[0] = A[0];
  // set last element has going from r to l
  rMax[A.size() - 1] = A[A.size() - 1];
  /**
   *     [3, 0, 1, 2, 5]
   * l = [3, 3, 3, 3, 5]
   * r = [5, 5, 5, 5, 5]
   *
   */
  // set the left max for each element
  for (int i = 1; i < A.size(); i++) {
    lMax[i] = max(A[i], lMax[i - 1]);
  }
  // set the right max for each element
  for (int i = A.size() - 2; i >= 0; i-- ) {
    rMax[i] = max(A[i], rMax[i + 1]);
  }

  // compute the amount of water at each pillar
  for (int i = 1; i < A.size() - 1; i++) {
    // now there is no need to compute the maximum
    // it is already stored in lMax and rMax
    res += min(lMax[i], rMax[i]) -  A[i];
  }
  return res;
}

int main() {
  // the numbers represent the heights of the bars
  vector<int> A = {3, 0, 1, 2, 5};
  cout << trap_water_optimal(A) << endl;
}
