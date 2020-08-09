//============================================================================
// Name        : Leetcode.841. Keys and Rooms
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
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
    	map<int, bool> roomsMap;
    	roomsMap[0] = true;
    	for(int i = 0; i < rooms.size(); i++) {
    		if(roomsMap.count(i) != 0) {
    			dfs(roomsMap, i, rooms);
    		}
    	}

    	return roomsMap.size() == rooms.size();
    }
private:
    void dfs(map<int, bool>& roomsMap, int roomNum, vector<vector<int>>& rooms) {
		if(roomsMap.size() >= 3000)
			return;

    	for(int i : rooms[roomNum]) {
			if(roomsMap.count(i) == 0) {
				roomsMap[i] = true;
				dfs(roomsMap, i, rooms);
			}
    	}
    }
};

int main() {
	// Test Case
	vector<vector<int>> rooms{{3},{3,2,1},{2},{1}};

	Solution t;
	cout << t.canVisitAllRooms(rooms) << endl;

	return 0;
}



