//============================================================================
// Name        : Leetcode.1190. Reverse Substrings Between Each Pair of Parentheses
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
    string reverseParentheses(string s) {
    	string rp;
    	for(int i = 0; i < s.length(); i++) {
    		if(s[i] != ')') {
    			rp.push_back(s[i]);
    		} else {
    			reverseLastSubStr(rp);
    		}
    	}
    	return rp;
    }
private:
    void reverseLastSubStr(string& subStr) {
		string tmp;
    	for(int i = subStr.size() - 1; i >= 0 && subStr[i] != '('; i--) {
    		tmp.push_back(subStr[i]);
    		subStr.pop_back();
    	}
    	subStr.pop_back();

    	for(int i = 0; i < tmp.length(); i++) {
    		subStr.push_back(tmp[i]);
    	}
    }
};

int main() {
	// Test Case

	Solution t;
	cout << t.reverseParentheses("a(bcdefghijkl(mno)p)q") << endl;

	return 0;
}



