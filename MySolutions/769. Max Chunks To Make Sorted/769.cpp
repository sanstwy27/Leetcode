//============================================================================
// Name        : Leetcode.769. Max Chunks To Make Sorted
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
    int maxChunksToSorted(vector<int>& arr) {
    	vector<int> minMark(arr.size()), maxMark(arr.size());

    	int curMax = INT_MIN, curMin = INT_MAX;
    	for(int i = 0, j = arr.size() - 1; i < arr.size(); i++, j--) {
    		curMax = max(curMax, arr[i]);
    		maxMark[i] = curMax;

    		curMin = min(curMin, arr[j]);
    		minMark[j] = curMin;
    	}

    	int maxChunks = 1;
    	for(int i = 0; i < arr.size(); i++) {
    		if(i + 1 < arr.size()) {
    			if(maxMark[i] < minMark[i + 1]) ++maxChunks;
    		}
    	}

    	return maxChunks;
    }
};

int main() {
	// Test Case
	vector<int> arr = {4,3,2,1,0};

	Solution t;
	cout << t.maxChunksToSorted(arr) << endl;

	return 0;
}



