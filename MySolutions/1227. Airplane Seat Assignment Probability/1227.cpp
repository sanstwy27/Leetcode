//============================================================================
// Name        : Leetcode.1227. Airplane Seat Assignment Probability
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   : https://github.com/wisdompeak/LeetCode/tree/master/Math/1227.Airplane-Seat-Assignment-Probability
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
    	// Consider that
    	// Seats number with K:
    	//     1 [2, 3, 4, ..., K-1] K
    	//     1 [neither his own nor the one of the nth passenger] K
    	// => K-th remain seats = (n - (k - 2)), if K=N then remain 2 seats
    	if(n == 1) return 1;
    	else return 0.5;
    }
};

int main() {
	// Test Case

	Solution t;
	cout << t.nthPersonGetsNthSeat(3) << endl;

	return 0;
}



