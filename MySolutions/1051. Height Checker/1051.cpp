//============================================================================
// Name        : Leetcode.1051. Height Checker
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
    int heightChecker(vector<int>& heights) {
    	vector<int> sorted(heights);
    	sort(sorted.begin(), sorted.end());

    	int count = 0;
    	for(int i = 0; i < heights.size(); i++) {
    		if(heights[i] != sorted[i]) ++count;
    	}

    	return count;
    }
};

int main() {
	// Test Case
	vector<int> heights{1,1,4,2,1,3};

	Solution t;
	cout << t.heightChecker(heights) << endl;

	return 0;
}



