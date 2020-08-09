//============================================================================
// Name        : Leetcode.319. Bulb Switcher
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   : https://www.cnblogs.com/grandyang/p/5100098.html
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
    	int ans = 1;
    	while(ans * ans <= n) ++ ans;
    	return ans - 1;
    }
};

int main() {
	// Test Case

	Solution t;
	cout << t.bulbSwitch(9999999) << endl;

	return 0;
}



