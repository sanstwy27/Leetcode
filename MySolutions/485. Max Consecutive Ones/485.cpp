//============================================================================
// Name        : Leetcode.485. Max Consecutive Ones
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   :
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    	int maxCount = 0, tmpCount = 0;

    	for(int i = 0; i < nums.size(); i++) {
    		if(nums[i] == 1) {
    			++tmpCount;
    			maxCount = max(maxCount, tmpCount);
    		} else {
    			tmpCount = 0;
    		}
    	}

    	return maxCount;
    }
};

int main() {
	// Test Case
	vector<int> nums{1};

	Solution t;
	cout << t.findMaxConsecutiveOnes(nums) << endl;

	return 0;
}



