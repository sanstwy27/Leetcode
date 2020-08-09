//============================================================================
// Name        : Leetcode.344. Reverse String
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
    void reverseString(vector<char>& s) {
    	for(int i = 0, j = s.size() - 1; i < j; i++, j--) {
    		char c = s[i];
    		s[i] = s[j];
    		s[j] = c;
    	}
    }
};

int main() {
	// Test Case
	vector<char> s{'h','e','l','l','o'};

	Solution t;
	t.reverseString(s);
	for(char c : s) cout << c << " " << endl;

	return 0;
}



