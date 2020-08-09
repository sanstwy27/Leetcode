//============================================================================
// Name        : Leetcode.775. Global and Local Inversions
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
    bool isIdealPermutation(vector<int>& A) {
    	vector<int> minFromRightToLeft(A.size(), 0);
    	int tmpMin = INT_MAX;
    	for(int i = A.size() - 1; i >= 0; i--) {
    		tmpMin = min(A[i], tmpMin);
    		minFromRightToLeft[i] = tmpMin;
    	}

    	int localInv = 0, globalInv = 0;
    	for(int i = 0; i < A.size(); i++) {
    		// Count Local Inversions
    		if((i + 1) < A.size()) {
    			if(A[i] > A[i + 1]) {
    				++localInv;
    				++globalInv;
    			}
    		}

    		// Count Global Inversions
    		if((i + 2) < A.size()) {
    			if(A[i] > minFromRightToLeft[i + 2]) {
    				return false;
    			}
    		}
    	}

    	return true;
    }
};

int main() {
	// Test Case
	vector<int> A{1,2,0};

	Solution t;
	cout << t.isIdealPermutation(A) << endl;

	return 0;
}



