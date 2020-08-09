//============================================================================
// Name        : Leetcode.1262. Greatest Sum Divisible by Three
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   : https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1262-greatest-sum-divisible-by-three/
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
    	vector<int> dp(3, 0);
    	for(int num : nums) {
    		vector<int> tmp(dp);
    		for(int i : tmp) {
    			dp[(i + num) % 3] = max(dp[(i + num) % 3], (i + num));
    		}
    	}

    	return dp[0];
    }
};

int main() {
	// Test Case
	vector<int> nums{1,1,5,4,7};

	Solution t;
	cout << t.maxSumDivThree(nums) << endl;

	return 0;
}



