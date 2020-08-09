//============================================================================
// Name        : Leetcode.16. 3Sum Closest
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   : https://www.cnblogs.com/grandyang/p/4510984.html
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	sort(nums.begin(), nums.end());

    	int diff = INT_MAX, ans = 0;
    	for(int i = 0; i < nums.size(); i++) {
    		int left = i + 1, right = nums.size() - 1;
    		while(left < right) {
        		int newDiff = nums[i] + nums[left] + nums[right] - target;
        		if(diff > abs(newDiff)) {
        			diff = abs(newDiff);
        			ans = newDiff + target;
        		}

        		if(newDiff < 0) ++left;
        		else --right;
    		}
    	}

    	return ans;
    }
};

int main() {
	// Test Case
	 vector<int> nums = {-1, 2, 1, -4};
	 int target = 1;

	Solution t;
	cout << t.threeSumClosest(nums, target) << endl;

	return 0;
}



