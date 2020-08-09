//============================================================================
// Name        : Leetcode.500. Keyboard Row
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
    vector<string> findWords(vector<string>& words) {
    	// Init
    	vector<char> keyboardTop{'Q','W','E','R','T','Y','U','I','O','P'};
    	vector<char> keyboardMiddle{'A','S','D','F','G','H','J','K','L'};
    	vector<char> keyboardBottom{'Z','X','C','V','B','N','M'};
    	unordered_map<char, int> keyboardMap;
    	initKeyboardMap(keyboardTop, 1, keyboardMap);
    	initKeyboardMap(keyboardMiddle, 0, keyboardMap);
    	initKeyboardMap(keyboardBottom, -1, keyboardMap);

    	vector<string> ans;
    	for(int i = 0; i < words.size(); i++) {
    		for(int j = 0; j < words[i].length(); j++) {
    			if((j + 1) < words[i].length()) {
    				if(keyboardMap[words[i][j]] != keyboardMap[words[i][j + 1]]) break;
    			} else {
    				ans.push_back(words[i]);
    			}
    		}
    	}

    	return ans;
    }
private:
    void initKeyboardMap(vector<char>& keyboard, int val, unordered_map<char, int>& keyboardMap) {
    	for(int i = 0; i < keyboard.size(); i++) {
    		keyboardMap[toupper(keyboard[i])] = val;
    		keyboardMap[tolower(keyboard[i])] = val;
    	}
    }
};

int main() {
	// Test Case
	vector<string> words{"Hello", "Alaska", "Dad", "Peace"};

	Solution t;
	vector<string> ans = t.findWords(words);
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}

	return 0;
}



