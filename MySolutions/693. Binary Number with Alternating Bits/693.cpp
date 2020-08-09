//============================================================================
// Name        : Leetcode.693. Binary Number with Alternating Bits
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
    bool hasAlternatingBits(int n) {
    	int prev = -1;

    	for(int i = n; i > 0; i /= 2) {
    		if((i % 2) == prev) return false;
    		else prev = i % 2;
    	}

    	return true;
    }
};

int main() {
	// Test Case

	Solution t;
	cout << t.hasAlternatingBits(10) << endl;

	return 0;
}



