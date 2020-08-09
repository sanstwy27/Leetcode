//============================================================================
// Name        : Leetcode.268. Missing Number
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
    int missingNumber(vector<int>& nums) {
    	sort(nums.begin(), nums.end());

    	for(int i = 0; i < nums.size(); i++) {
    		if(nums[i] != i) return i;
    	}

    	return nums.size();
    }
};

int main() {
	// Test Case
	vector<int> nums{9,6,4,2,3,5,7,0,1};

	Solution t;
	cout << t.missingNumber(nums) << endl;

	return 0;
}



