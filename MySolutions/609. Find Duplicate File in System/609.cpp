//============================================================================
// Name        : Leetcode.609. Find Duplicate File in System
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
    vector<vector<string>> findDuplicate(vector<string>& paths) {
    	map<string, vector<string>> fileMap;

		vector<string> tokens;
    	for(string s : paths) {
    		tokens.clear();
    		split(s, tokens);
    		if(!tokens.empty()) {
    			string path = tokens[0];
				for(int i = 1; i < tokens.size(); i++) {
					string::size_type p1 = tokens[i].find_first_not_of("(", 0);
					string::size_type p2 = tokens[i].find_first_of("(", p1);
					string::size_type p3 = tokens[i].find_first_of(")", p2);
					string filename = tokens[i].substr(p1, p2 - p1);
					string content = tokens[i].substr(p2 + 1, p3 - p2 - 1);

					fileMap[content].push_back(path + "/" + filename);
				}
    		}
    	}

    	vector<vector<string>> ans;
    	for(pair<string, vector<string>> p : fileMap) {
    		if(p.second.size() > 1)
    			ans.push_back(p.second);
    	}

    	return ans;
    }
private:
    void split(const string& s, vector<string>& tokens, const string& delimiters = " ") {
        string::size_type lastPos = s.find_first_not_of(delimiters, 0);
        string::size_type pos = s.find_first_of(delimiters, lastPos);
        while (string::npos != pos || string::npos != lastPos) {
            tokens.push_back(s.substr(lastPos, pos - lastPos));//use emplace_back after C++11
            lastPos = s.find_first_not_of(delimiters, pos);
            pos = s.find_first_of(delimiters, lastPos);
        }
    }
};

int main() {
	// Test Case
	vector<string> paths{"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};

	Solution t;
	vector<vector<string>> ans = t.findDuplicate(paths);
	for(vector<string> i : ans) {
		for(string j : i) {
			cout << j << endl;
		}
		cout << " ++++" << endl;
	}

	return 0;
}



