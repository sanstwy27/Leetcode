//============================================================================
// Name        : Leetcode.516. Longest Palindromic Subsequence
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
    int longestPalindromeSubseq(string s) {
    	int n = s.length();
    	vector<vector<int>> dp(n, vector<int>(n));
    	for(int i = n - 1; i >= 0; i--) {
    		dp[i][i] = 1;
    		for(int j = i + 1; j < n; j++) {
    			if(s[i] == s[j]) {
    				dp[i][j] = dp[i + 1][j - 1] + 2;
    			} else {
    				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
    			}
    		}
    		display(dp);
    	}

    	return dp[0][n - 1];
    }
private:
    void display(vector<vector<int>>& dp) {
    	for(int i = 0; i < dp.size(); i++) {
    		for(int j = 0; j < dp[0].size(); j++) {
    			cout << dp[i][j] << " ";
    		}
    		cout << endl;
    	}
		cout << "--------------" << endl;
    }
};

int main() {
	// Test Case

	Solution t;
	cout << t.longestPalindromeSubseq("bbabab") << endl;


	return 0;
}



