//============================================================================
// Name        : Leetcode.888. Fair Candy Swap
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   :
//============================================================================
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    	int sumA = 0;
    	set<int> setA;
    	for(int i = 0; i < A.size(); i++) {
    		sumA += A[i];
    		setA.insert(A[i]);
    	}
    	int sumB = 0;
    	set<int> setB;
    	for(int i = 0; i < B.size(); i++) {
    		sumB += B[i];
    		setB.insert(B[i]);
    	}

    	vector<int> ans;
    	int diff = sumB - sumA;
    	for(set<int>::iterator iter = setA.begin(); iter != setA.end(); iter++) {
    		int swapNum = (*iter) + (diff / 2);
    		if(setB.count(swapNum) != 0) {
    			ans.push_back(*iter);
    			ans.push_back(swapNum);
    			break;
    		}
    	}

    	return ans;
    }
};

int main() {
	// Test Case
	vector<int> A{1,2}, B{2,3};

	Solution t;
	vector<int> ans = t.fairCandySwap(A, B);
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}

	return 0;
}



