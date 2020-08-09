//============================================================================
// Name        : Leetcode.845. Longest Mountain in Array
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   : https://www.cnblogs.com/grandyang/p/10459400.html
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& A) {
    	if(A.empty()) return 0;

    	int longestLen = 0;
    	int upLen = 0, downLen = 0;
    	for(int i = 1; i < A.size(); i++) {
    		if((downLen && A[i-1] < A[i]) || A[i-1] == A[i]) {
    			upLen = 0;
    			downLen = 0;
    		}

    		if(A[i-1] < A[i]) ++upLen;
    		if(A[i-1] > A[i]) ++downLen;

    		if(upLen && downLen) longestLen = max(longestLen, upLen + downLen + 1);
    	}

    	return longestLen;
    }
};

int main() {
	// Test Case
	vector<int> A{2,3,3,2,0,2};

	Solution t;
	cout << t.longestMountain(A) << endl;

	return 0;
}



