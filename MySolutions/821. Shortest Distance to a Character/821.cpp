//============================================================================
// Name        : Leetcode.821. Shortest Distance to a Character
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
    vector<int> shortestToChar(string S, char C) {
    	vector<int> ans(S.length(), 0);

    	// Scan Left to Right
    	vector<int> right_dist = countDist(S, C);

        // Scan Right to Left
    	string R = S;
    	std::reverse(R.begin(), R.end());
    	vector<int> left_dist = countDist(R, C);
    	std::reverse(left_dist.begin(), left_dist.end());

    	// Choose Min of Dist i
    	for(int i = 0; i < ans.size(); i++) {
    		ans[i] = min(right_dist[i], left_dist[i]);
    	}

    	return ans;
    }
private:
    vector<int> countDist(string sample, char findIt)
    {
        vector<int> tmp;
        for(int i = 0, j = INT_MAX - sample.size(); i < sample.size(); i++) {
            if(sample[i] == findIt) {
                j = 0;
            } else {
            	j++;
            }
        	tmp.push_back(j);
        }

        return tmp;
    }
};

void showAnswer(vector<int>& ans) {
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}

int main() {
	// Test Case
	string S1 = "loveleetcode";
	char C1 = 'e';
	string S2 = "eete";
	char C2 = 'e';

	Solution t;
	vector<int> ans = t.shortestToChar(S1, C1);
	showAnswer(ans);
	ans = t.shortestToChar(S2, C2);
	showAnswer(ans);

	return 0;
}
