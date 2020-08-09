//============================================================================
// Name        : Leetcode.823. Binary Trees With Factors
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

class Solution {
	const long moduleNum = 1000000007;
public:
    int numFactoredBinaryTrees(vector<int>& A) {
    	sort(A.begin(), A.end());
    	int maxNum = A[A.size() - 1];
    	set<int> baseSet;
    	for(int i : A) {
    		if(i <= (maxNum / 2)) baseSet.insert(i);
    	}

    	long num = 0;
    	map<int, long> dp;
    	for(int i : A) {
    		dp[i] = 1;
    		for(int j : baseSet) {
    			if(j < i) {
    				if(i % j == 0 && dp.count(i / j) != 0) {
    					dp[i] += (dp[j] * dp[i / j]) % moduleNum;
    				}
    			}
    		}
    		num += dp[i];
    	}

    	return num % moduleNum;
    }
};

int main() {
	// Test Case
	vector<int> A{45,42,2,18,23,1170,12,41,40,9,47,24,33,28,10,32,29,17,46,11,759,37,6,26,21,49,31,14,19,8,13,7,27,22,3,36,34,38,39,30,43,15,4,16,35,25,20,44,5,48};

	Solution t;
	cout << t.numFactoredBinaryTrees(A) << endl;

	return 0;
}



