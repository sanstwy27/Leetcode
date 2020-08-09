//============================================================================
// Name        : Leetcode.1015. Smallest Integer Divisible by K
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   : https://www.cnblogs.com/zywscq/p/10699120.html
// 1. Reduce caculation
//    => f(n)=111111...;　　
//    => g(n)=f(n)%K
//    => f(n)=f(n-1)*10+1
//    => f(n)%K=(f(n-1)*10+1)%K
//    => g(n)=g(n-1)*10+1
// 2. Until K rounds (by Pigeon-hole Principle)
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int K) {
    	int ans = -1, tmp = 1;
    	for(int i = 0; i < K; i++) {
    		if(tmp % K == 0) {
    			ans = i + 1;
    			break;
    		}
    		else tmp = (tmp % K) * 10 + 1;
    	}

    	return ans;
    }
};

int main() {
	// Test Case

	Solution t;
	cout << t.smallestRepunitDivByK(2) << endl;

	return 0;
}



