//============================================================================
// Name        : Leetcode.452. Minimum Number of Arrows to Burst Balloons
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   : https://www.cnblogs.com/grandyang/p/6050562.html
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
    	if(points.empty()) return 0;

    	sort(points.begin(), points.end());
    	int totalArrow = 1;
    	int curEnd = points[0][1];
    	for(int i = 0; i < points.size(); i++) {
    		if(points[i][0] > curEnd) {
    			curEnd = points[i][1];
    			++totalArrow;
    		} else {
    			curEnd = min(curEnd, points[i][1]);
    		}
    	}

    	return totalArrow;
    }
};

int main() {
	// Test Case
	vector<vector<int>> points{{10,16}, {2,8}, {1,6}, {7,12}};
	//vector<vector<int>> points{{-2147483648,2147483647}};
	//vector<vector<int>> points{{10,16},{2,8},{1,6},{7,12},{14,20},{15,15}};

	Solution t;
	cout << t.findMinArrowShots(points) << endl;

	return 0;
}



