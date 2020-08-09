//============================================================================
// Name        : Leetcode.326. Power of Three
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   : https://www.cnblogs.com/grandyang/p/5138212.html
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
    	return (n > 0 && int(log10(n) / log10(3)) - log10(n) / log10(3) == 0);
    }
};

int main() {
	// Test Case

	Solution t;
	cout << t.isPowerOfThree(45) << endl;

	return 0;
}



