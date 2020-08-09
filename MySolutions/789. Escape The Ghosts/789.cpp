//============================================================================
// Name        : Leetcode.789. Escape The Ghosts
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
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
    	vector<int> me{0, 0};
    	int myTime = getTime(me, target);

    	for(int i = 0; i < ghosts.size(); i++) {
    		if(myTime >= getTime(ghosts[i], target)) return false;
    	}

    	return true;
    }
private:
    int getTime(vector<int>& from, vector<int>& to) {
    	if(from.empty() || to.empty()) return 0;

    	int dx = to[0] - from[0];
    	int dy = to[1] - from[1];
    	int time = 0;
    	for(time = 0; dx != 0 || dy != 0;) {
    		if(dx != 0) dx = dx > 0 ? dx - 1 : dx + 1;
    		else if(dy != 0) dy = dy > 0 ? dy - 1 : dy + 1;

    		time += 1;
    	}

    	return time;
    }
};

int main() {
	// Test Case
	vector<vector<int>> ghosts = {{1, 0}};
	vector<int> target{2, 0};

	Solution t;
	cout << t.escapeGhosts(ghosts, target) << endl;

	return 0;
}



