# ============================================================================
# Name        : Leetcode.231. Power of Two
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        while(n > 1):
            n /= 2
        return n == 1


print(Solution().isPowerOfTwo(1))





