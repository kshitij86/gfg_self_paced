#include <bits/stdc++.h>
using namespace std;

/*
 * best video:
 * https://www.youtube.com/watch?v=M8BYckxI8_U&ab_channel=ArtofProblemSolving
 *
 * consider traversing the grid as a sequence of steps
 * either up or down and we can permute them
 *
 * but some of them will definitely be repeated
 *
 * so we can remove that by division
 *
 * in an m*n grid, we can d something like
 *
 * (m+n)!/(m! * n!)
 *
 * consider the steps - DDRRDRD
 *
 * imagine this will get us to last
 * then (m+n)! will count the down nes many times
 * and right also many times.
 *
 * to avoid this, we remove them
 *
 */

int count_paths(int i, int j, int r, int c){
	if(i > r || j > c){
		return 0;
	}
	if(i == r && j == c){
		return 1;	
	}
	return count_paths(i+1, j, r, c) + (i, j+1, r, c);
	
}

int main(){
	int r = 2, c = 2;
	cout << count_paths(0, 0, r, c) << endl;	
}
