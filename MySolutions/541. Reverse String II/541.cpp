//============================================================================
// Name        : Leetcode.541. Reverse String II
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description :
// Reference   :
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for(int str_index = 0; str_index < s.length(); str_index += k) {
        	if((str_index / k) % 2 == 0) {
        		if(str_index + k <= s.length())
        		    reverse(&s[str_index], &s[str_index + k]);
        		else
        			reverse(&s[str_index], &s[s.length()]);
        	}
        }

        return s;
    }
};

int main() {
	// Test Case
    string str = "geeksforgeeks";
    int k = 6;

    Solution t;
    cout << t.reverseStr(str, k) << endl;

	return 0;
}

