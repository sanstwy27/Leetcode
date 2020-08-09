//============================================================================
// Name        : Leetcode.912. Sort an Array
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
    vector<int> sortArray(vector<int>& nums) {
    	vector<int> count(100001, 0);

    	int numsLen = nums.size();
    	for(int i = 0; i < numsLen; i++) {
    		++count[nums[i] + 50000];
    	}

    	int countLen = count.size(), flag = 0;
    	for(int i = 0; i < countLen; i++) {
			for(int j = 0; j < count[i]; j++) {
				nums[flag++] = i - 50000;
			}
    	}

    	return(nums);
    }
};

void showAns(vector<int>& nums) {
	for(int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
}

int main() {
	// Test Case
	//vector<int> nums{5,1,1,2,0,0};
	vector<int> nums{-20000};

	Solution t;
	t.sortArray(nums);
	showAns(nums);

	return 0;
}

