# ============================================================================
# Name        : Leetcode.338. Counting Bits
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def countBits(self, num: int) -> List[int]:
        res = [0] * (num + 1)
        for i in range(1, num + 1):
            if(i % 2 == 0):
                res[i] = res[int(i / 2)]
            else:
                res[i] = res[int(i / 2)] + 1
        return res



num = 5
print(Solution().countBits(num))
