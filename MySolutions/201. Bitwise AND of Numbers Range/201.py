# ============================================================================
# Name        : Leetcode.201. Bitwise AND of Numbers Range
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://www.cnblogs.com/grandyang/p/4431646.html
# ============================================================================
from typing import collections, List
class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        if(m == 0):
            return 0
        elif(m == n):
            return m
        else:
            mask = 2147483647
            while((m & mask) != (n & mask)):
                mask = mask << 1
            return mask & m
        



print(Solution().rangeBitwiseAnd(6, 7))




