//============================================================================
// Name        : Leetcode.853. Car Fleet
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
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    	float minStamp = INT_MAX;
    	map<int, float> ptMap;
    	vector<float> time(position.size(), 0.0);
    	for(int i = 0; i < position.size(); i++) {
    		time[i] = ((double)target - position[i]) / speed[i];
    		minStamp = min(minStamp, time[i]);
    		ptMap[position[i]] = time[i];
    	}

    	float timeStamp = 0;
    	int carFleet = 0;
    	for(map<int, float>::reverse_iterator iter = ptMap.rbegin(); iter != ptMap.rend(); iter++) {
    		//cout << iter->first << ", " << iter->second << ", " << psMap[iter->first] << " " << endl;
    		if(iter->second > timeStamp) {
    			++carFleet;
    			timeStamp = iter->second;
    		} else if(iter->second == timeStamp) {
    			if(timeStamp > minStamp)
    				++carFleet;
    		}
    	}

    	return carFleet;
    }
};

int main() {
	// Test Case
	//int target = 12;
	//vector<int> position{10,8,0,5,3}, speed{2,4,1,1,3};
	//int target = 10;
	//vector<int> position{8,3,7,4,6,5}, speed{4,4,4,4,4,4};
	//int target = 12;
	//vector<int> position{10,8,0,5,3}, speed{2,4,1,1,3};
	//int target = 10;
	//vector<int> position{2,4}, speed{3,2};
	//int target = 17;
	//vector<int> position{8,12,16,11,7}, speed{6,9,10,9,7};
	int target = 10;
	vector<int> position{4,6}, speed{3,2};

	Solution t;
	cout << t.carFleet(target, position, speed) << endl;

	return 0;
}



