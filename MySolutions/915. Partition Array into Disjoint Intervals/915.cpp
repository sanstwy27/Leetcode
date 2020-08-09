//============================================================================
// Name        : Leetcode.915. Partition Array into Disjoint Intervals
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
    int partitionDisjoint(vector<int>& A) {
    	int len = A.size();
    	vector<int> vMax(len, 0), vMin(len, 0);


    	int max = INT_MIN, min = INT_MAX;
    	for(int imax = 0, imin = len - 1; imax < len; imax++, imin--) {
    		max = std::max(max, A[imax]);
    		min = std::min(min, A[imin]);

    		vMax[imax] = max;
    		vMin[imin] = min;
    	}

    	int flag = -1;
    	for(int i = 0; i < len - 1; i++) {
    		if(vMax[i] <= vMin[i + 1]) {
    			flag = i + 1;
    			break;
    		}
    	}

    	return flag;
    }
};

int main() {
	// Test Case
	vector<int> A{1,1};

	Solution t;
	cout << t.partitionDisjoint(A) << endl;

	return 0;
}

