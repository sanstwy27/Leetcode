//============================================================================
// Name        : Leetcode.14. Longest Common Prefix
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
    string longestCommonPrefix(vector<string>& strs) {
    	if(strs.empty())
    		return "";

    	string ans = strs[0];
    	for(string s : strs) {
    		string prefix;
    		for(int i = 0; i < min(s.length(), ans.length()); i++) {
    			if(s[i] == ans[i]) {
    				prefix += ans[i];
    				continue;
    			}
    			break;
    		}
			ans = prefix;
    	}
    	return ans;
    }
};

int main() {
	// Test Case
	vector<string> strs{"flower","flow","flight"};

	Solution t;
    cout << t.longestCommonPrefix(strs) << endl;

	return 0;
}



