//============================================================================
// Name        : Leetcode.1049. Last Stone Weight II
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   : https://www.zhangjc.site/archives-327/
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
    	int total = 0;
    	for(int s : stones)
    		total += s;
    	int backpack = total / 2;
    	vector<int> dp(backpack + 1, 0);

    	for(int s: stones) {
    		for(int i = backpack; i >= s; i--) {
    			dp[i] = max(dp[i], dp[i - s] + s);
    		}
    	}

    	return total - 2 * dp[backpack];
    }
};

int main() {
	// Test Case
	//vector<int> stones{2,7,4,1,8,1};
	//vector<int> stones{1,3,4,3,5,4};
	vector<int> stones{10,33,31,59,53,43,23,16,42,55,40,42,28,41,64,51,32,24,17,35,35,21,12,44};

	Solution t;
	cout << t.lastStoneWeightII(stones) << endl;

	return 0;
}



