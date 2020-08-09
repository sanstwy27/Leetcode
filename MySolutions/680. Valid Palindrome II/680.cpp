//============================================================================
// Name        : Leetcode.680. Valid Palindrome II
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   :
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
    	int l = 0, r = s.length() - 1;
    	while(l < r) {
    		if(s[l] == s[r]) {
    			++l; --r;
    		} else {
    			return validPalindrome(s, l + 1, r) || validPalindrome(s, l, r - 1);
    		}
    	}

    	return true;
    }
private:
    bool validPalindrome(string& s, int l, int r) {
    	while(l < r) {
    		if(s[l++] != s[r--]) return false;
    	}

    	return true;
    }
};

int main() {
	// Test Case

	Solution t;
	cout << t.validPalindrome("abca") << endl;

	return 0;
}



