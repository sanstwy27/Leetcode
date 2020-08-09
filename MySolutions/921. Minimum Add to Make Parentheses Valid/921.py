# ============================================================================
# Name        : Leetcode.921. Minimum Add to Make Parentheses Valid
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        d = collections.deque()
        for i in range(0, len(S)):
            if(len(d) > 0):
                if(S[i] == ")" and d[len(d) - 1] == "("):
                    d.pop()
                    continue
            d.append(S[i])
        return len(d)



S = "())"
print(Solution().minAddToMakeValid(S))







