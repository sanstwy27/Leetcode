//============================================================================
// Name        : Leetcode.1266. Minimum Time Visiting All Points
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
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    	int totalTime = 0;
    	if(points.size() <= 1) return totalTime;

    	int dx = 0, dy = 0;
    	for(int i = 0; (i + 1) < points.size(); i++) {
    		dx = points[i + 1][0] - points[i][0];
    		dy = points[i + 1][1] - points[i][1];
    		totalTime += moveTime(dx, dy);
    	}

    	return totalTime;
    }
private:
    int moveTime(int dx, int dy) {
    	int time = 0, mx = 0, my = 0;

    	for(int mx = 0, my = 0; dx !=0 || dy != 0; ) {
    		if(dx > 0) {
    			mx = 1;
    		} else if(dx == 0) {
    			mx = 0;
    		} else{
    			mx = -1;
    		}

    		if(dy > 0) {
    			my = 1;
    		} else if(dy == 0) {
    			my = 0;
    		} else{
    			my = -1;
    		}

    		dx -= mx;
    		dy -= my;
    		++time;
    	}

    	return time;
    }
};

int main() {
	// Test Case
	//vector<vector<int>> points {{1,1},{3,4},{-1,0}};
	vector<vector<int>> points {{1,1},{3,4}};

	Solution t;
	cout << t.minTimeToVisitAllPoints(points) << endl;

	return 0;
}

