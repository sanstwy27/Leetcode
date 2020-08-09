//============================================================================
// Name        : Leetcode.464. Can I Win
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : 
// Reference   : https://www.cnblogs.com/grandyang/p/6103525.html
//               https://www.jianshu.com/p/b7db270b7577
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
    	if(desiredTotal <= maxChoosableInteger) return true;
    	if(desiredTotal > (maxChoosableInteger + 1) * maxChoosableInteger / 2) return false;

    	unordered_map<int, bool> state(maxChoosableInteger);
    	return canWin(maxChoosableInteger, 0, state, desiredTotal);
    }

private:
    bool canWin(int maxChoosableInteger, int stateUsedKey, unordered_map<int, bool>& state, int desiredTotal) {
    	if(state.count(stateUsedKey)) return state[stateUsedKey];
    	for(int i = 1; i <= maxChoosableInteger; i++) {
    	    if((stateUsedKey & (1 << i)) == 0) { // 2^i is not Used.
				if(desiredTotal <= i || !canWin(maxChoosableInteger, stateUsedKey | (1 << i), state, desiredTotal - i)) {
					state[stateUsedKey] = true;
					return true;
				}
    	    }
    	}
    	state[stateUsedKey] = false;
    	return false;
    }
};


int main() {
	// Test Case
	int maxChoosableInteger = 6;
	int desiredTotal = 11;

	Solution t;
	cout << t.canIWin(maxChoosableInteger, desiredTotal) << endl;

	return 0;
}

