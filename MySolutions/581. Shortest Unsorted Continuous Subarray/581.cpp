//============================================================================
// Name        : Leetcode.581. Shortest Unsorted Continuous Subarray
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
    int findUnsortedSubarray(vector<int>& nums) {
    	if(nums.empty()) return 0;

    	// Init
    	int n = nums.size();
    	vector<int> maxMark(n);
    	vector<int> minMark(n);
    	int maxVal = INT_MIN, minVal = INT_MAX;
    	for(int i = 0, j = n -1; i < n; i++, j--) {
    		maxVal = max(maxVal, nums[i]);
    		maxMark[i] = maxVal;

    		minVal = min(minVal, nums[j]);
    		minMark[j] = minVal;
    	}

    	// Find First Unsorted Index
    	int left = 0;
    	for(int i = 0; i < n; i++) {
    		if(maxMark[i] != minMark[i]) {
    			left = i;
    			break;
    		}
    	}

    	// Find Last Unsorted Index
    	int right = 0;
    	for(int i = n - 1; i >= 0; i--) {
    		if(maxMark[i] != minMark[i]) {
    			right = i;
    			break;
    		}
    	}

    	cout << left << ", " << right << endl;

    	return (left || right) ? (right - left + 1) : 0;
    }
};

int main() {
	// Test Case
	vector<int> nums{2, 1};

	Solution t;
	cout << t.findUnsortedSubarray(nums) << endl;

	return 0;
}



