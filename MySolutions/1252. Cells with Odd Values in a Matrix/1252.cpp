//============================================================================
// Name        : Leetcode.1252. Cells with Odd Values in a Matrix
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
    int oddCells(int n, int m, vector<vector<int>>& indices) {
    	vector<vector<int>> countMap(n, vector<int>(m, 0));
    	for(int i = 0; i < indices.size(); i++) {
        	int x = indices[i][0];
        	int y = indices[i][1];
        	increMatrix(x, y, countMap);
    	}

    	int ans = 0;
    	for(int i = 0; i < countMap.size(); i++) {
    		for(int j = 0; j < countMap[0].size(); j++) {
    			if(countMap[i][j] % 2 == 1) ++ans;
    		}
    	}

    	return ans;
    }
private:
    void increMatrix(int x, int y, vector<vector<int>>& countMap) {
    	countMap[x][y] += 2;

    	for(int i = (x - 1); i >= 0; i--) {
    		++countMap[i][y];
    	}
    	for(int i = (x + 1); i < countMap.size(); i++) {
    		++countMap[i][y];
    	}
    	for(int i = (y - 1); i >= 0; i--) {
    		++countMap[x][i];
    	}
    	for(int i = (y + 1); i < countMap[0].size(); i++) {
    		++countMap[x][i];
    	}
    }
};

int main() {
	// Test Case
	int n = 48, m = 37;
	vector<vector<int>> indices{{40,5}};

	Solution t;
	cout << t.oddCells(n, m, indices) << endl;

	return 0;
}



