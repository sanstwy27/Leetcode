//============================================================================
// Name        : Leetcode.877. Stone Game
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   : https://www.cnblogs.com/grandyang/p/10828725.html
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
    	int n = piles.size();
    	sort(piles.begin(), piles.end());

    	vector<vector<int>> dp(n, vector<int>(n));
    	for(int i = n - 1; i >= 0; i--) {
    		dp[i][i] = piles[i];
    		for(int j = i + 1; j < n; j++) {
				dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
    		}
    		//display(dp);
    	}

    	return dp[0][n - 1] > 0;
    }
private:
    void display(vector<vector<int>>& dp) {
    	for(int i = 0; i < dp.size(); i++) {
        	for(int j = 0; j < dp[0].size(); j++) {
        		cout << dp[i][j] << " ";
        	}
        	cout << endl;
    	}
    	cout << "-----" << endl;
    }
};

int main() {
	// Test Case
	vector<int> piles{5,3,4,5};

	Solution t;
	cout << t.stoneGame(piles) << endl;

	return 0;
}



