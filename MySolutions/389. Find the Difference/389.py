# ============================================================================
# Name        : Leetcode.389. Find the Difference
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        sc = collections.Counter(s)
        tc = collections.Counter(t)
        tc.subtract(sc)
        tc._keep_positive()

        res = ""
        for key, c in tc.items():
            for i in range(0, c):
                res += key
        return res



s = "abcd"
t = "abcde"
print(Solution().findTheDifference(s, t))


