//============================================================================
// Name        : Leetcode.125. Valid Palindrome
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
    bool isPalindrome(string s) {
    	string alphaStr;
    	for(char c : s) {
    		if(isalpha(c) || isdigit(c)) {
    			alphaStr.push_back(tolower(c));
    		}
    	}

    	if(alphaStr.empty()) {
    		return true;
    	} else {
    		int n = alphaStr.size();
    		for(int i = 0, j = n - 1; i <= n/2; i++, j--) {
    			if(alphaStr[i] != alphaStr[j]) return false;
    		}
    	}

    	return true;
    }
};

int main() {
	// Test Case

	Solution t;
	//cout << t.isPalindrome("A man, a plan, a canal: Panama") << endl;
	cout << t.isPalindrome("race a car") << endl;

	return 0;
}



