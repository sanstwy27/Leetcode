//============================================================================
// Name        : Leetcode.229. Majority Element II
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
    vector<int> majorityElement(vector<int>& nums) {
    	int a = 0, b = 0, aCnt = 0, bCnt = 0;

    	for(int i = 0; i < nums.size(); i++) {
    		if(nums[i] == a) ++aCnt;
    		else if(nums[i] == b) ++bCnt;
    		else if(aCnt == 0) { a = nums[i]; aCnt = 1; }
    		else if(bCnt == 0) { b = nums[i]; bCnt = 1; }
    		else { --aCnt; --bCnt; }
    	}

    	aCnt = 0, bCnt = 0;
    	for(int i = 0; i < nums.size(); i++) {
    		if(nums[i] == a) ++aCnt;
    		else if(nums[i] == b) ++bCnt;
    	}

    	vector<int> ans;
    	if(aCnt > (nums.size()/3)) ans.push_back(a);
    	if(bCnt > (nums.size()/3)) ans.push_back(b);
    	return ans;
    }
};

void showAns(vector<int>& ans) {
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}

int main() {
	// Test Case
	vector<int> nums{1,1,1,3,3,2,2,2};

	Solution t;
	vector<int> ans = t.majorityElement(nums);
	showAns(ans);

	return 0;
}



