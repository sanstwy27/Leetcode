# ============================================================================
# Name        : Leetcode.1039. Minimum Score Triangulation of Polygon
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://www.cnblogs.com/seyjs/p/10955757.html
# ============================================================================
from typing import collections, List
class Solution:
    def minScoreTriangulation(self, A: List[int]) -> int:
        n = len(A)
        dp = []
        for i in range(0, n):
            dp.append([float("inf")] * n)
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                for k in range(i + 1, j):
                    if(dp[i][k] == float("inf") or dp[k][j] == float("inf")):
                        num  = min(dp[i][k], dp[k][j])
                        if(num == float("inf")):
                            dp[i][j] = min(dp[i][j], A[i]*A[k]*A[j])
                        else:
                            dp[i][j] = min(dp[i][j], A[i]*A[k]*A[j] + num)
                    else:
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i]*A[k]*A[j])
        return dp[0][n - 1]


# A = [3,7,4,5]
A = [1,3,1,4,1,5]
print(Solution().minScoreTriangulation(A))



