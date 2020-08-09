# ============================================================================
# Name        : Leetcode.1043. Partition Array for Maximum Sum
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1043-partition-array-for-maximum-sum/
# ============================================================================
from typing import collections, List
class Solution:
    def maxSumAfterPartitioning(self, A: List[int], K: int) -> int:
        n = len(A)
        dp = [0] * (n + 1)
        print(dp)
        
        for i in range(1, n + 1):
            m = -1
            for k in range(1, K + 1):
                if(i - k >= 0):
                    m = max(m, A[i - k])
                    dp[i] = max(dp[i], dp[i - k] + m * k)
            
        print(dp)
        return dp[n]



A = [1,15,7,9,2,5,10]
K = 3
print(Solution().maxSumAfterPartitioning(A, K))