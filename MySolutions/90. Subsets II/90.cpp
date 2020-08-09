//============================================================================
// Name        : Leetcode.90. Subsets II
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   : https://github.com/azl397985856/leetcode/blob/master/problems/90.subsets-ii.md
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	vector<vector<int>> ans;
    	vector<int> subSet;

    	// Get Subsets
    	std::sort(nums.begin(), nums.end());
    	getSubsets(nums, 0, subSet, ans);

    	return ans;
    }
private:
    void getSubsets(vector<int>& nums, int pos, vector<int>& subSet, vector<vector<int>>& ans) {
    	ans.push_back(subSet);
    	for(int i = pos; i < nums.size(); i++) {
			subSet.push_back(nums[i]);
			getSubsets(nums, i + 1, subSet, ans);
			subSet.pop_back();

			while((i + 1) < nums.size() && (nums[i + 1] == nums[i])) ++i;
    	}
    }
};

int main() {
	// Test Case
	//vector<int> nums{1,2,2};
	vector<int> nums{4,4,4,1,4};

	Solution t;
	vector<vector<int>> ans = t.subsetsWithDup(nums);

	for(int i = 0; i < ans.size(); i++) {
		for(int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j];
		}
		 cout << endl;
	}
	cout << ans.size() << endl;

	return 0;
}



