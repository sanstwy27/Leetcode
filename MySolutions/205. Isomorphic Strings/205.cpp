//============================================================================
// Name        : Leetcode.205. Isomorphic Strings
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
    bool isIsomorphic(string s, string t) {
    	if(s.length() != t.length())
    		return false;

    	int sMap[256] = {0}, tMap[256] = {0};
    	for(int i = 0; i < s.size(); i++) {
    		if(sMap[s[i]] != tMap[t[i]]) return false;
    		sMap[s[i]] = i + 1;
    		tMap[t[i]] = i + 1;
    	}

    	return true;
    }
};

int main() {
	// Test Case

	Solution t;
	cout << t.isIsomorphic("aba", "baa") << endl;

	return 0;
}



