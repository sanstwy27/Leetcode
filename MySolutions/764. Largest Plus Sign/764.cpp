//============================================================================
// Name        : Leetcode.764. Largest Plus Sign
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   : https://www.cnblogs.com/grandyang/p/8679286.html
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
    	if(N == 0)
    		return 0;

    	vector<vector<int>> map(N, vector<int>(N, 1));
    	for(int i = 0; i < mines.size(); i++) {
       		map[mines[i][0]][mines[i][1]] = 0;
    	}

		// Count 1's
    	vector<vector<int>> ansMap(N, vector<int>(N, INT_MAX));
    	for(int i = 0; i < N; i++) {
    		// => right scan (left counts)
    		int count = 0;
    		for(int j = 0; j < N; j++) {
    			count = (map[i][j] == 1) ? count + 1 : 0;
    			ansMap[i][j] = min(ansMap[i][j], count);
    		}
    		// <= left scan (right counts)
    		count = 0;
			for(int j = N-1; j >= 0; j--) {
				count = (map[i][j] == 1) ? count + 1 : 0;
				ansMap[i][j] = min(ansMap[i][j], count);
			}
    	}

    	for(int j = 0; j < N; j++) {
    		// ^ up scan (down counts)
    		int count = 0;
    		for(int i = 0; i < N; i++) {
    			count = (map[i][j] == 1) ? count + 1 : 0;
    			ansMap[i][j] = min(ansMap[i][j], count);
    		}
    		// £¾ down scan (up counts)
    		count = 0;
			for(int i = N-1; i >= 0; i--) {
				count = (map[i][j] == 1) ? count + 1 : 0;
				ansMap[i][j] = min(ansMap[i][j], count);
			}
    	}

    	// Find ans;
    	int ans = 0;
    	for(int i = 0; i < N; i++) {
        	for(int j = 0; j < N; j++) {
        		if(ans == 0) {
        			ans = ansMap[i][j];
        		}
       			ans = max(ans, ansMap[i][j]);
        	}
    	}

    	return ans;
    }
};

int main() {
	// Test Case
//	int N = 5;
//	vector<vector<int>> mines = {{4, 2}};
	int N = 2;
	vector<vector<int>> mines = {};

	Solution t;
	cout << t.orderOfLargestPlusSign(N, mines) << endl;

	return 0;
}



