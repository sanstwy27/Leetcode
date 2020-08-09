//============================================================================
// Name        : Leetcode.209. Minimum Size Subarray Sum
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   :
//============================================================================
#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	std::deque<int> ans;

    	bool found = false;
    	int sum = 0, minLen = INT_MAX;
    	for(int i = 0; i < nums.size(); i++) {
    		ans.push_back(nums[i]);
    		sum += nums[i];
    		while(sum >= s) {
    			found = true;
    			int n = ans.size();
    			if(n > 0) {
    				minLen = min(minLen, n);
    			}

    			int tmp = ans[0];
    			sum -= tmp;
    			ans.pop_front();
    		}
    	}

    	return found ? minLen : 0;
    }
};

int main() {
	// Test Case
	 int s = 7;
	 vector<int> nums{2,3,7,1,2,4,3};

	 Solution t;
	 cout << t.minSubArrayLen(s, nums) << endl;

	return 0;
}



