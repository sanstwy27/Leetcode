//============================================================================
// Name        : Leetcode.242. Valid Anagram
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
    bool isAnagram(string s, string t) {
    	if(s.size() != t.size())
    		return false;

    	sort(s.begin(), s.end());
    	sort(t.begin(), t.end());
    	for(int i = 0; i < s.size(); i++) {
    		if(s[i] != t[i]) return false;
    	}

    	return true;
    }
};

int main() {
	// Test Case

	Solution t;
	cout << t.isAnagram("argqwrfb", "argqwrfb") << endl;


	return 0;
}



