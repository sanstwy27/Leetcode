# ============================================================================
# Name        : Leetcode.397. Integer Replacement
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def integerReplacement(self, n: int) -> int:
        return self.minStep(n, 0)

    def minStep(self, cur: int, step: int):
        if(cur == 1):
            return step
        else:
            if(cur % 2 == 0):
                return self.minStep(cur / 2, step + 1)
            else:
                p1 = self.minStep(cur + 1, step + 1)
                m1 = self.minStep(cur - 1, step + 1)
                return min(p1, m1)



print(Solution().integerReplacement(8))