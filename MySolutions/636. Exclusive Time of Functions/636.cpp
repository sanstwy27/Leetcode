//============================================================================
// Name        : Leetcode.636. Exclusive Time of Functions
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
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
    vector<int> exclusiveTime(int n, vector<string>& logs) {
    	vector<int> ans(n, 0), tmpStack, splitRes;

    	int preStamp = 0;
    	for(int i = 0; i < logs.size(); i++) {
    		splitRes.clear();
    		bool isStart = splitStartStr(logs[i], ':', splitRes);

    		if(isStart) {
    			if(!tmpStack.empty()) {
    				ans[tmpStack.back()] += splitRes[1] - preStamp;
    			}
    			tmpStack.push_back(splitRes[0]);
    			preStamp = splitRes[1];
    		} else {
    			ans[tmpStack.back()] += splitRes[1] - preStamp + 1;
    			tmpStack.pop_back();
    			preStamp = splitRes[1] + 1;
    		}
    	}

    	return ans;
    }
private:
     bool splitStartStr(string str, char c, vector<int>& strCont) {
    	bool isStart = false;

    	string token = "";
    	std::stringstream ss(str);
        while (std::getline(ss, token, c)) {
        	if(token == "start") {
        		isStart = true;
        	} else if(token == "end") {
        		isStart = false;
        	} else {
        		strCont.push_back(std::stoi(token));
        	}
        }

        return isStart;
    }
};

int main() {
	// Test Case
	int n = 2;
	//vector<string> logs{"0:start:0","0:start:2","0:end:5","1:start:7","1:end:7","0:end:8"};
	//vector<string> logs{"0:start:0","1:start:2","1:end:5","0:end:6"};
	vector<string> logs{"0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"};

	Solution t;
	vector<int> m = t.exclusiveTime(n, logs);
	for(int i = 0; i < m.size(); i++) {
		cout << m[i] << endl;
	}

	return 0;
}



