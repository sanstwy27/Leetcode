//============================================================================
// Name        : Leetcode. 1031. Maximum Sum of Two Non-Overlapping Subarrays
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : 
// Reference   : https://zxi.mytechroad.com/blog/leetcode/leetcode-weekly-contest-133/
//============================================================================
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        // Get Array Size
    	const int n = A.size();
    	// Sum of SubArray
    	vector<int> ss(n + 1, 0);
    	for (int i = 0; i < n; ++i)
    		ss[i + 1] = ss[i] + A[i];

    	// Find Solution
    	int ans = 0;
    	for (int i = 0; i <= n - L; ++i) {
    		// Get Sum of L-length SubArray
    		int ls = ss[i + L] - ss[i];
    		// Get Max Sum of M-length SubArray
    		// (on either side of the L-length subarray)
    		int ms = max(maxSum(ss, 0, i - M - 1, M),
    				maxSum(ss, i + L, n - M, M));

    		ans = max(ans, ls + ms);
    	}

    	return ans;
    }
private:
    int maxSum(const vector<int>& ss, int start, int end, int len) {
    	int max_sum = INT_MIN;
    	for (int i = start; i <= end; ++i)
    		max_sum = max(max_sum, ss[i + len] - ss[i]);

    	return max_sum;
    }
};

int main() {
	// Test Case
	vector<int> A {0,6,5,2,2,5,1,9,4};
    int L = 1, M = 2;

    Solution t;
    cout << t.maxSumTwoNoOverlap(A, L, M) << endl;

	return 0;
}
