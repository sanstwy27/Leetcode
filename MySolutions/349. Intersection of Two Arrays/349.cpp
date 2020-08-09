//============================================================================
// Name        : Leetcode.349. Intersection of Two Arrays
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    	vector<int> ans;

    	unordered_set<int> numSet;
    	for(int i : nums1) numSet.insert(i);

    	unordered_set<int> hitSet;
    	for(int i : nums2) {
    		if(hitSet.count(i) == 0 && numSet.count(i) != 0) {
    			ans.push_back(i);
    			hitSet.insert(i);
    		}
    	}

    	return ans;
    }
};

int main() {
	// Test Case
	vector<int> nums1{2,6,2,9,1};
	vector<int> nums2{7,1};

	Solution t;
	vector<int> ans = t.intersection(nums1, nums2);
	for(int i : ans)
		cout << i << endl;

	return 0;
}



