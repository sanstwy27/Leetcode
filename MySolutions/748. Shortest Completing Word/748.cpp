//============================================================================
// Name        : Leetcode.748. Shortest Completing Word
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   :
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
    	// Count licensePlate alphabets
		int totalAlphabets = 0;
    	unordered_map<char, int> licenseMap;
    	for(int i = 0; i < licensePlate.length(); i++) {
    		if(isalpha(licensePlate[i])) {
    			++licenseMap[toupper(licensePlate[i])];
    			++totalAlphabets;
    		}
    	}

		// Check vector of words
    	string ans;
    	for(int i = 0; i < words.size(); i++) {
    		int matchLen = totalAlphabets;
        	unordered_map<char, int> wordMap(licenseMap);
    		for(int j = 0; j < words[i].length(); j++) {
    			if(isalpha(words[i][j])) {
					char tmp = toupper(words[i][j]);

					if(wordMap.count(tmp) != 0) {
						if(--wordMap[tmp] >= 0) --matchLen;
					}

					if(matchLen == 0) {
						if(ans.empty()) ans = words[i];
						else {
							ans = (ans.length() <= words[i].length()) ? ans : words[i];
						}
					}

    			}
    		}
    	}

    	return ans;
    }
};

int main() {
	// Test Case
	string licensePlate = "1s3 456";
	vector<string> words{"looks", "pest", "stew", "show"};

	Solution t;
	cout << t.shortestCompletingWord(licensePlate, words) << endl;

	return 0;
}



