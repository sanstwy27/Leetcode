//============================================================================
// Name        : Leetcode.165. Compare Version Numbers
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description :
// Reference   :
//============================================================================
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
    	vector<int> ver1 = splitStr(version1, '.');
    	vector<int> ver2 = splitStr(version2, '.');

    	if(ver1.size() < ver2.size()) for(;ver1.size() < ver2.size();) ver1.push_back(0);
    	if(ver1.size() > ver2.size()) for(;ver1.size() > ver2.size();) ver2.push_back(0);

    	for(int i = 0; i < ver1.size(); i++) {
    		if(ver1[i] > ver2[i]) return 1;
    		if(ver1[i] < ver2[i]) return -1;
    	}

    	return 0;
    }
private:
    vector<int> splitStr(string& str, char c) {
    	string token = "";
    	vector<int> strCont;

    	std::stringstream ss(str);
        while (std::getline(ss, token, c)) {
        	strCont.push_back(std::stoi(token));
        }

        return strCont;
    }
};

int main() {
	// Test Case
	string ver1 = "1.1";
	string ver2 = "1";

	Solution t;
	cout << t.compareVersion(ver1, ver2) << endl;

	return 0;
}


