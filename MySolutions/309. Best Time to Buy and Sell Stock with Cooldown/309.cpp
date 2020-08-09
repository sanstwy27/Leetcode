//============================================================================
// Name        : Leetcode.309. Best Time to Buy and Sell Stock with Cooldown
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description :
// Reference   : https://zhuanlan.zhihu.com/p/80078865
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if(prices.size() < 2) return 0;

		// vector<int> buy(i): stock BUY to maximize profit day i.
		// vector<int> sell(i): Stock SELL to maximize profit on day i.
    	vector<int> buy(prices.size()), sell(prices.size());
    	buy[0] = -prices[0];
    	buy[1] = max(buy[0], -prices[1]);
    	sell[0] = 0;
    	sell[1] = max(prices[1] - prices[0], 0);

		// Dynamic Programming
    	for(int i = 2; i < prices.size(); i++) {
    		buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
    		sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
    	}

    	return sell.back();
    }
};

int main() {
	// Test Case
	//vector<int> prices{1,2,3,0,2};
	vector<int> prices{2, 1};

	Solution t;
	cout << t.maxProfit(prices) << endl;

	return 0;
}

