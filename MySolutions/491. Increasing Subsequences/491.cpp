//============================================================================
// Name        : Leetcode.491. Increasing Subsequences
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description :
// Reference   :
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
    	vector<vector<int>> ans;
    	vector<int> cur;
    	dfs(nums, 0, cur, ans);
    	return ans;
    }
private:
    void dfs(vector<int>& nums, int start, vector<int> cur, vector<vector<int>>& ans) {
    	unordered_set<int> seen;

    	for(int i = start; i < nums.size(); i++) {
    		if(!cur.empty() && cur.back() > nums[i]) continue;
    		if(seen.insert(nums[i]).second) {
    			cur.push_back(nums[i]);
				if(cur.size() > 1)
					ans.push_back(cur);

	    		dfs(nums, i + 1, cur, ans);
	    		cur.pop_back();
    		}
    	}
    }
};

void showAnswer(vector<vector<int>> ans) {
	for(vector<vector<int>>::iterator it_out = ans.begin(); it_out != ans.end(); it_out++) {
		cout << "[";
		for(vector<int>::iterator it_in = it_out->begin(); it_in != it_out->end(); it_in++) {
			cout << *it_in << " ";
		}
		cout << "]" << endl;
	}
}

int main() {
	// Test Case
	//vector<int> input{4, 6, 7, 7};
	//vector<int> input{4, 3, 2, 1};
	vector<int> input{1,2,3,4,5,6,7,8,9,10,1,1,1,1,1};

	Solution t;
	showAnswer(t.findSubsequences(input));


	return 0;
}

