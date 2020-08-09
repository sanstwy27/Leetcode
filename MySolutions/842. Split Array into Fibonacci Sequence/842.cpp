//============================================================================
// Name        : Leetcode.842. Split Array into Fibonacci Sequence
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   : Huahua
// Description : Any %
// Reference   : https://zxi.mytechroad.com/blog/?s=842
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
	const int maxDigit = 10; //2147483647
public:
    vector<int> splitIntoFibonacci(string S) {
    	vector<int> ans;
    	dfs(ans, 0, S);
    	return ans;
    }
private:
    bool dfs(vector<int>& ans, int start, string& S) {
    	if(start == S.length())
    		return ans.size() > 2;

    	long num = 0;
    	size_t len = S[start] == '0' ? 1 : maxDigit;
    	for(int i = start; i < min(start + len, S.length()) ; i++) {
    		num = num * 10 + (S[i] - '0');
    		if(num > INT_MAX) break;
    		if(ans.size() >= 2) {
    			long sum = static_cast<long>(ans[ans.size() - 1]) + ans[ans.size() - 2];
    			if(sum > num) continue;
    			if(sum < num) break;
    		}

    		ans.push_back(num);
    		if(dfs(ans, i + 1, S)) return true;
    		ans.pop_back();
    	}
    	return false;
    }
};

int main() {
	// Test Case

	Solution t;
	vector<int> ans = t.splitIntoFibonacci("123456579");
	cout << ans.size() << endl;
	for(int i : ans) {
		cout << i << endl;
	}

	return 0;
}



