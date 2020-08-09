//============================================================================
// Name        : Leetcode.838. Push Dominoes
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
    string pushDominoes(string dominoes) {
    	int len = dominoes.length();
    	vector<int> rightCount(len, 0);
    	vector<int> leftCount(len, 0);

    	bool rightFlag = false, leftFlag = false;
    	int rightCnt = 0, leftCnt = 0;
    	for(int i = 0, j = len - 1; i < len; i++, j--) {
    		// Right Counts
    		if(dominoes[i] == 'R') {
    			rightFlag = true;
    		} else if(dominoes[i] == 'L') {
    			rightFlag = false;
    		}

    		if(dominoes[i] == 'R' || dominoes[i] == 'L') {
    			rightCnt = 0;
    		} else {
    			++rightCnt;
    		}
    		if(rightFlag) rightCount[i] = rightCnt;

    		// Left Counts
    		if(dominoes[j] == 'R') {
    			leftFlag = false;
    		} else if(dominoes[j] == 'L') {
    			leftFlag = true;
    		}

    		if(dominoes[j] == 'R' || dominoes[j] == 'L') {
    			leftCnt = 0;
    		} else {
    			++leftCnt;
    		}
    		if(leftFlag) leftCount[j] = leftCnt;
    	}

    	for(int i = 0; i < len; i++) {
    		if(rightCount[i] > 0 && leftCount[i] > 0) {
				if(rightCount[i] > leftCount[i]) dominoes[i] = 'L';
				if(rightCount[i] < leftCount[i]) dominoes[i] = 'R';
				continue;
    		}
    		if(rightCount[i] > 0) {
    			dominoes[i] = 'R';
    		}
    		if(leftCount[i] > 0) {
    			dominoes[i] = 'L';
    		}
    	}

    	return dominoes;
    }
};

int main() {
	// Test Case
	//string dominoes = ".L.R...LR..L..";
	string dominoes = "R.LL";

	Solution t;
	cout << t.pushDominoes(dominoes) << endl;

	return 0;
}



