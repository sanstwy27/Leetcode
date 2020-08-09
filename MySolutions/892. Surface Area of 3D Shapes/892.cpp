//============================================================================
// Name        : Leetcode.892. Surface Area of 3D Shapes
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
    int surfaceArea(vector<vector<int>>& grid) {
    	int ans = 0;
    	int n = grid.size();
    	for(int i = 0; i < n; i++) {
        	for(int j = 0; j < n; j++) {
        		if(grid[i][j] > 0) ans += 4 * grid[i][j] + 2;
        		if(i > 0 && grid[i - 1][j] > 0) ans -= min(grid[i - 1][j], grid[i][j]) * 2;
        		if(j > 0 && grid[i][j - 1] > 0) ans -= min(grid[i][j - 1], grid[i][j]) * 2;
        	}
    	}

    	return ans;
    }
};

int main() {
	// Test Case
	vector<vector<int>> grid{{1,1,1},{1,0,1},{1,1,1}};

	Solution t;
	cout << t.surfaceArea(grid) << endl;

	return 0;
}



