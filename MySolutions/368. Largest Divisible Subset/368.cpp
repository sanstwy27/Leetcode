//============================================================================
// Name        : Leetcode.368. Largest Divisible Subset
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   : https://blog.csdn.net/fuxuemingzhu/article/details/83027364
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    	if(nums.size() <= 1)
    		return nums;

    	// DP
    	sort(nums.begin(), nums.end());
    	vector<int> dp(nums.size(), 0), preIndex(nums.size(), -1);
    	for(int i = 0; i < nums.size(); i++) {
        	for(int j = i - 1; j >= 0; j--) {
        		if(nums[i] % nums[j] == 0) {
        			if(dp[j] + 1 > dp[i]) {
						dp[i] = dp[j] + 1;
						preIndex[i] = j;
        			}
        			//break;
        		}
        	}
    	}

    	// Ans
    	int maxLen = 0, maxI = -1;
    	for(int i = 0; i < dp.size(); i++) {
    		if(dp[i] > maxLen) {
    			maxLen = dp[i];
    			maxI = i;
    		}
    	}

    	vector<int> ans;
    	while(maxI != -1) {
    		ans.push_back(nums[maxI]);
    		maxI = preIndex[maxI];
    	}
    	if(!ans.empty())
    		sort(ans.begin(), ans.end());
    	else
    		ans.push_back(nums[0]);

    	return ans;
    }
};

int main() {
	// Test Case
	//vector<int> nums{3,4,16,8};
	//vector<int> nums{2,4,16,8};
	//vector<int> nums{1,2,4,8,9,18,36,72};
	//vector<int> nums{546,669};
	vector<int> nums{4,8,10,240};

	Solution t;
	vector<int> ans = t.largestDivisibleSubset(nums);
	for(int i : ans)
		cout << i << endl;

	return 0;
}



