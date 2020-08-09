//============================================================================
// Name        : Leetcode.840. Magic Squares In Grid
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
    int numMagicSquaresInside(vector<vector<int>>& grid) {
    	int lenL = grid.size(), lenW = grid[0].size();
    	if(lenL < 3 || lenW < 3)
    		return 0;

    	int total = 0;
    	for(int i = 0; i <= lenL - 3; i++) {
    		for(int j = 0; j <= lenW - 3; j++) {
    			if(isMagicSquare(grid, i, j)) ++total;
    		}
    	}
    	return total;
    }
private:
    bool isMagicSquare(vector<vector<int>>& grid, int gi, int gj) {
    	// Check Nums Scope
    	vector<int> num(10, 0);
    	for(int i = 0; i < 3; i++) {
    		for(int j = 0; j < 3; j++) {
    			int val = grid[gi + i][gj + j];
    			if(val > 0 && val < 10)	++num[val];
    			else return false;
    		}
    	}
    	for(int i = 1; i < num.size(); i++)
    		if(num[i] == 0) return false;

    	// Check SUMs
    	// 1. Rows, Cols Sum
    	vector<int> sum;
    	for(int i = 0; i < 3; i++) {
    		int rowSum = 0, colSum = 0;
    		for(int j = 0; j < 3; j++) {
    			int rowVal = grid[gi + i][gj + j];
    			int colVal = grid[gi + j][gj + i];

    			rowSum += rowVal;
    			colSum += colVal;
    		}
    		if(sum.empty()) sum.push_back(rowSum);
    		if(rowSum != sum.back()) return false;
    		if(colSum != sum.back()) return false;
    	}
    	// 2. Diagonals Sum
    	if((grid[gi + 0][gj + 0] + grid[gi + 2][gj + 2])
    			!= (grid[gi + 0][gj + 2] + grid[gi + 2][gj + 0]))
    		return false;

    	return true;
    }
};

int main() {
	// Test Case
	//vector<vector<int>> grid{{4,3,8},{9,5,1},{2,7,6}};
	vector<vector<int>> grid{{4,3,8,4},{9,5,1,9},{2,7,6,2}};

	Solution t;
	cout << t.numMagicSquaresInside(grid) << endl;

	return 0;
}

