//============================================================================
// Name        : Leetcode.482. License Key Formatting
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : 
// Reference   : https://zxi.mytechroad.com/blog/string/leetcode-482-license-key-formatting/
//============================================================================
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
    	string upper_S;
    	for (char c : S)
    		if (c != '-') upper_S.push_back(toupper(c));

    	int first = 0;
    	if(upper_S.length() > 0) {
    		first = (upper_S.length() % K == 0) ? K : (upper_S.length() % K);
    	}

    	string ans = upper_S.substr(0, first);
    	for (int i = 0; i < upper_S.length() - first; i++) {
    		if (i % K == 0) ans += '-';
    		ans.push_back(upper_S[i + first]);
    	}

    	return ans;
    }
};

int main() {
	// Test Case
	string S1 = "2-5g-3-J";
	int K1 = 2;
	string S2 = "2-4A0r7-4k";
	int K2 = 4;
	string S3 = "---";
	int K3 = 3;

	Solution t;
	cout << t.licenseKeyFormatting(S1, K1) << endl;
	cout << t.licenseKeyFormatting(S2, K2) << endl;
	cout << t.licenseKeyFormatting(S3, K3) << endl;

	return 0;
}
