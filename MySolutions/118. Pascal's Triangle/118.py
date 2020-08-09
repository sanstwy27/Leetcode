# ============================================================================
# Name        : Leetcode.118. Pascal's Triangle
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = []
        for i in range(0, numRows):
            res.append([])
            for j in range(0, i + 1):
                if(j == 0 or j == i):
                    res[i].append(1)
                else:
                    if(i > 0):
                        res[i].append(res[i - 1][j - 1] + res[i - 1][j])
        return res



numRows = 5
print(Solution().generate(3))







