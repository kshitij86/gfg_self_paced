#include <bits/stdc++.h>
using namespace std;


/**
 * method that considers all pairs
 * didn't get, very tricky recursion
 */

int max_profit(vector<int> &A, int start, int end) {
	if (end <= start) {
		return 0;
	}
	int profit = 0;
	for (int i = start; i < end; i++) {
		for (int j = i + 1; j <= end; j++) {
			if (A[i] < A[j]) {
				int curr_profit = (A[j] - A[i]) + max_profit(A, start, i - 1) + max_profit(A, j + 1, end);
				profit = max(profit, curr_profit);
			}
		}
	}
	return profit;
}

int stock_buy_and_sell(vector<int> &A) {
	/**
	 * if the price of a stock goes down, we will let it go as down as
	 * possible.
	 * then when it starts increasing, we know it will not go down
	 * any further and so we can buy.
	 *
	 * same logic for when it goes up, let it go as high as possible.
	 * then we can sell it at the peak for maximum profit.
	 *
	 * so we can go from peak to peak and try to add all the profits
	 */

	// simply add the profits if it goes up
	// else do nothing
	// I was doing find a peak, then a valley

	// if prices are [1,2,3,4]
	/**
	 * instead of directly adding (4-1=3)m it adds, (2-1) + (3-2) + (4-3)
	 * by observing that the price is increasing each time
	 *
	 * this indirectly adds all the peaks and does not consider the valleys
	 * as buying in valley will give profit as (peak - valley) only
	 */
	int profit = 0;
	for (int i = 1; i < A.size(); i++) {
		if (A[i] > A[i - 1]) {
			profit += A[i] - A[i - 1];
		}
	}
	return profit;
}

int main() {
	vector<int> A = {1, 5, 3, 8, 12};
	cout << stock_buy_and_sell(A) << endl;
}