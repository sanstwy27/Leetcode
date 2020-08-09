# ============================================================================
# Name        : Leetcode.62. Unique Paths
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        m -= 1
        n -= 1
        if(m > n):
            m, n = n, m
        
        numerator = 1
        for i in range(m + n, n, -1):
            numerator *= i
        denominator = 1
        for i in range(1, m + 1):
            denominator *= i

        return numerator//denominator
        
        """
        Ref: https://www.cnblogs.com/zuoyuan/p/3785221.html
        if m == 1 and n == 1:
            list = [[1]]
        elif m == 1 and n > 1:
            list = [[1 for i in range(n)]]
        elif m > 1 and n == 1:
            list = [[1] for i in range(m)]
        else:
            list = [[0 for i in range(n)] for i in range(m)]
            for i in range(0, n):
                list[0][i] = 1
            for i in range(0, m):
                list[i][0] = 1
            for i in range(1, m):
                for j in range(1, n):
                    list[i][j] = list[i-1][j] + list[i][j-1]
        print(list)
        return list[m-1][n-1]
        """


m = 2
n = 1
print(Solution().uniquePaths(m, n))


