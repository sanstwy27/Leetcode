//============================================================================
// Name        : Leetcode.1053. Previous Permutation With One Swap
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
    vector<int> prevPermOpt1(vector<int>& A) {
    	vector<int> tmpMax(A.size(), 0);

    	int backMax = 0;
    	for(int i = A.size() - 1; i >= 0; i--) {
    		tmpMax[i] = i;
    		backMax = 0;
    		for(int j = i + 1; j < A.size(); j++){
    			if(A[i] > A[j]) {
    				if(A[j] > backMax) {
    					tmpMax[i] = j;
    					backMax = A[j];
    				}
    			}
    		}

    		if(tmpMax[i] != i) break;
    	}

    	for(int i = A.size() - 1; i >= 0; i--) {
    		if(i != tmpMax[i]) {
    			int tmp = A[i];
    			A[i] = A[tmpMax[i]];
    			A[tmpMax[i]] = tmp;
    			break;
    		}
    	}

    	return A;
    }
};

int main() {
	// Test Case
	//vector<int> A={1,9,4,6,7};
	//vector<int> A={3,1,1,3};
	//vector<int> A={1,1,5};
	vector<int> A={3,2,1};

	Solution t;
	vector<int> ans = t.prevPermOpt1(A);
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}



