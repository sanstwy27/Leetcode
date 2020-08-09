//============================================================================
// Name        : Leetcode.724. Find Pivot Index
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description :
// Reference   :
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
    	int len = nums.size();
    	if(len < 2) return -1;

    	int lVal = 0, rVal = 0, i, j;
    	vector<int> lSum(nums), rSum(nums);
    	for(i = 0, j = len - 1; i < len; i++, j--) {
    		lSum[i] += lVal;
    		rSum[j] += rVal;
    		lVal = lSum[i];
    		rVal = rSum[j];
    	}

    	for(int i = 0; i < len; i++) {
    		if(lSum[i] == rSum[i]) return i;
    	}

    	return -1;
    }
};

int main() {
	// Test Case
	vector<int> nums{1, 7, 3, 6, 5, 6};

	Solution t;
	cout << t.pivotIndex(nums) << endl;

	return 0;
}


