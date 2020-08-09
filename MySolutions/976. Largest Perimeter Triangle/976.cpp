//============================================================================
// Name        : Leetcode.976. Largest Perimeter Triangle
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   : https://zhuanlan.zhihu.com/p/54992171
//  [Note] a, b, c are consecutive number
//   pf: if there exists X is satisfying a => b => X => c,
//       since b + c > a, where b + X >= b + c > a
//       then a + b + X >= a + b + c
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
    	sort(A.begin(), A.end());
    	for(int i = A.size() - 1; i >= 2; i--) {
    		if(A[i] + A[i - 1] > A[i - 2] &&
    				A[i - 1] + A[i - 2] > A[i] &&
					A[i - 2] + A[i] > A[i - 1]) {
    			return A[i] + A[i - 1] + A[i - 2];
    		}
    	}
    	return 0;
    }
};

int main() {
	// Test Case
	vector<int> A{3,6,2,3};

	Solution t;
	cout << t.largestPerimeter(A) << endl;

	return 0;
}



