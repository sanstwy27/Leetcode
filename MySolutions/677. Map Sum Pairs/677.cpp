//============================================================================
// Name        : Leetcode.677. Map Sum Pairs
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   :
//============================================================================
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {

    }

    void insert(string key, int val) {
		int oldVal = 0;
		if(keySet.count(key) != 0) {
			oldVal = mapSum[key];
		}

    	string k;
    	for(int i = 0; i < key.length(); i++) {
    		k.push_back(key[i]);
    		mapSum[k] = mapSum[k] + (val - oldVal);
    	}

    	if(keySet.count(key) == 0) {
    		keySet.insert(key);
    	}
    }

    int sum(string prefix) {
    	if(mapSum.count(prefix) != 0) return mapSum[prefix];
    	else return 0;
    }
private:
    set<string> keySet;
    map<string, int> mapSum;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

int main() {
	// Test Case

	MapSum* obj = new MapSum();
	obj->insert("apple", 3);
	//cout << obj->sum("ap") << endl;
	obj->insert("app", 2);
	cout << obj->sum("ap") << endl;


	return 0;
}



