//============================================================================
// Name        : Leetcode.20. Valid Parentheses
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
    bool isValid(string s) {
    	vector<char> tmp;

    	for(int i = 0; i < s.size(); i++) {
    		if(s[i] == '{' || s[i] == '(' || s[i] == '[')
    			tmp.push_back(s[i]);

    		switch(s[i]) {
    		case '}':
    			if(tmp.empty()) return false;
    			if(tmp.back() != '{') return false;
    			tmp.pop_back();
    			break;
    		case ')':
    			if(tmp.empty()) return false;
    			if(tmp.back() != '(') return false;
    			tmp.pop_back();
				break;
    		case ']':
    			if(tmp.empty()) return false;
    			if(tmp.back() != '[') return false;
    			tmp.pop_back();
				break;
    		}
    	}

    	return tmp.size() == 0;
    }
};

int main() {
	// Test Case
	string str = "{[]}";

	Solution t;
	cout << t.isValid(str) << endl;

	return 0;
}



