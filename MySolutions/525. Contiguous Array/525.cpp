//============================================================================
// Name        : Leetcode.525. Contiguous Array
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   :
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
  	    if (nums.empty()) return 0;

  	    unordered_map<int, int> pos;
  	    int sum = 0, ans = 0;
  	    for (int i = 0; i < nums.size(); ++i) {
  	    	sum += nums[i] ? 1 : -1;
  	    	if (sum == 0) {
  	    		ans = i + 1;
  	    	} else {
  	    		if (pos.count(sum)) {
  	    			// Index Distance
  	    	        ans = max(ans, i - pos[sum]);
  	    		} else {
  	    			// Update Last Index with The Sum
  	    			pos[sum] = i;

  	    		}
  	    	}
  	    }
  	    return ans;

    }
};

int main() {
	// Test Case
	vector<int> nums{0,0,0,1,0,0,1,0,0,0,0,0,1,1,1,0,0,0,1,1,0,0,1,1,0,0,0,1,1,1,1,0,0,0,1,0,0,0,1,1,0,0,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,1,1,1,1,1,0,1,0,0,1,0,0,1,0,1,0,1,1,1,0,0,1,1,1,1,0,1,0,0,0,1,1,0,0,1,0,0,1,0,0,0,0,0,1,0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,1,0,1,0,1,0,0,0,1,1,1,1,0,1,0,1,1,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,1,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,1,0,1,0,1,0,1,1,0,0,1,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,0,1,0,1,0,1,1,0,0,0,0,1,1,0,1,0,1,1,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,0,1,1,0,1,0,0,0,0,1,0,0,1,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,1,1,0,0,0,1,1,1,1,0,1,1,0,0,1,0,1,1,1,1,0,0,1,0,0,1,0,0,0,1,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1,1,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,1,1,0,1,1,1,1,1,1,0,0,1,0,0,1,0,1,1,1,0,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,1,0,1,0,0,0,1,0,0,1,0,1,0,1,0,0,1,1,1,1,1,0,0,0,0,0,0,1,0,1,1,0,0,0,1,1,0,1,1,0,1,1,1,0,0,0,1,1,0,1,1,1,1,0,0,1,1,0,1,1,0,0,0,0,1,0,0,0,0,1,1,0,1,0,0,1,0,1,1,0,0,1,0,0,1,0,1,0,0,1,0,0,0,1,1,0,0,0,1,0,0,0,1,1,1,0,0,0,1,0,0,1,1,1,1,0,0,1,0,0,0,1,0,0,1,0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0,0,0,0,1,1,0,1,1,0,0,0,1,0,1,0,1,0,0,1,0,1,0,0,1,1,0,1,1,1,0,1,0,1,0,0,0,1,0,1,1,1,0,1,1,0,1,1,0,1,0,0,1,0,1,0,1,1,1,1,0,0,0,0,1,1,0,0,1,0,1,1,1,1,1,0,0,0,1,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,0,1,0,0,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,0,1,0,0,1,1,0,0,1,1,1,0,1,0,1,1,0,1,1,1,1,0,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,1,1,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,0,1,0,0,0,1,1,1,0,0,1,1,1,0,0,1,0,0,0,1,1,0,0,1,1,0,1,1,0,0,0,0,0,0,1,0,0,1,0,1,0,1,1,0,1,0,0,0,0,0,1,0,0,1,0,1,0,1,0,0,0,0,0,0,1,0,1,1,0,1,0,1,1,0,0,0,0,1,1,0,1,1,0,1,1,1,1,0,1,1,1,1,0,1,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,1,0,1,1,0,1,1,1,1,0,0,1,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,1,1,1,0,1,0,0,0,0,0,1,1,0,1,1,1,1,0,1,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,1,0,0,0,1,1,0,0,0,0,1,1,1,1,1,0,1,1,1};

	Solution t;
	int maxLen =  t.findMaxLength(nums);
	cout << maxLen << endl;

	return 0;
}



