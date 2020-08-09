//============================================================================
// Name        : Leetcode.384. Shuffle an Array
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
    Solution(vector<int>& nums) {
    	nums_ = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
    	return nums_;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
    	vector<int> suffle(nums_);
    	for(int i = 0; i < suffle.size(); i++) {
    		int swapIndex = (i + rand()) % suffle.size();
    		cout << swapIndex << endl;
    		swap(suffle[i], suffle[swapIndex]);
    	}
    	return suffle;
    }
private:
    vector<int> nums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main() {
	// Test Case
	vector<int> nums{1,2,3};

	Solution t = Solution(nums);
	t.shuffle();



	return 0;
}



