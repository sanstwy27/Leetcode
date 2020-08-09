//============================================================================
// Name        : Leetcode.791. Custom Sort String
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   :
//============================================================================
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string customSortString(string S, string T) {
    	// Init
    	vector<char> seq;
    	for(int i = 0; i < S.length(); i++) {
    		seq.push_back(S[i]);
    	}

    	map<char, int> tTotal;
    	for(int i = 0; i < T.length(); i++) {
    		++tTotal[T[i]];
    	}

    	// Custom String
    	string ans;
    	// 1. Sort CharS
    	for(int i = 0; i < seq.size(); i++) {
    		char key = seq[i];
    		int cnt = tTotal[key];
    		for(int j = 0; j < cnt; j++) {
    			ans.push_back(key);
    		}
    		tTotal[key] = 0;
    	}
        // 2. Other
    	for(map<char, int>::iterator iter = tTotal.begin(); iter != tTotal.end(); iter++) {
    		if(iter->second != 0) {
    			for(int i = 0; i < iter->second; i++) {
    				ans.push_back(iter->first);
    			}
    			iter->second = 0;
    		}
    	}

    	return ans;
    }
};

int main() {
	// Test Case

	Solution t;
	cout << t.customSortString("cba", "abcd") << endl;


	return 0;
}



