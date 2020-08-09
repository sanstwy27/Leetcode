//============================================================================
// Name        : Leetcode.867. Transpose Matrix
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
    vector<vector<int>> transpose(vector<vector<int>>& A) {
    	vector<vector<int>> ans;
    	for(int i = 0; i < A[0].size(); i++) {
			vector<int> row;
    		for(int j = 0; j < A.size(); j++) {
    			row.push_back(A[j][i]);
    		}
    		ans.push_back(row);
    	}
    	return ans;
    }
};

int main() {
	// Test Case
	vector<vector<int>> A{{1,2,3},{4,5,6}};

	Solution t;
	vector<vector<int>> ans = t.transpose(A);
	for(int i = 0; i < ans.size(); i++) {
		for(int j = 0; j < ans[0].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}



