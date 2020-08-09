//============================================================================
// Name        : Leetcode.682. Baseball Game
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
    int calPoints(vector<string>& ops) {
    	vector<int> points, tmpoint;

    	for(int i = 0; i < ops.size(); i++) {
    		// Digits
    		if(is_digits(ops[i])) {
    			points.push_back(stoi(ops[i]));
    			continue;
    		}
    		// "+"
    		if(ops[i] == "+") {
    			int tmpSum = 0;
    			for(int i = 0; i < 2; i++) {
					if(!points.empty()) {
						tmpoint.push_back(points.back());
						points.pop_back();
					}
    			}
    			int tmpSize = tmpoint.size();
    			for(int i = 0; i < tmpSize; i++) {
    				points.push_back(tmpoint.back());
    				tmpSum += points.back();
    				tmpoint.pop_back();
    			}
    			points.push_back(tmpSum);
    			continue;
    		}
    		// "C"
    		if(ops[i] == "C") {
    			points.pop_back();
    			continue;
    		}
    		// "D"
    		if(ops[i] == "D") {
    			int tmpVal = points.back() * 2;
    			points.push_back(tmpVal);
    			continue;
    		}
    	}

    	int total = 0;
    	for(int i = 0; i < points.size(); i++) {
    		total += points[i];
    	}

    	return total;
    }
private:
    bool is_digits(const std::string &str)
    {
        return str.find_first_not_of("-0123456789") == std::string::npos;
    }
};

int main() {
	// Test Case
	vector<string> ops{"5","2","C","D","+"};

	Solution t;
	cout << t.calPoints(ops) << endl;

	return 0;
}


