# ============================================================================
# Name        : Leetcode.880. Decoded String at Index
# Author      : LeetCode(@awice)
# Version     : sanstwy27 Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def decodeAtIndex(self, S: str, K: int) -> str:
        size = 0
        # Find size = length of decoded string
        for c in S:
            if c.isdigit():
                size *= int(c)
            else:
                size += 1

        for c in reversed(S):
            K %= size
            if K == 0 and c.isalpha():
                return c

            if c.isdigit():
                size /= int(c)
            else:
                size -= 1



#print(2*3*4*5*6*7*8*9*9*9*9*9*9*9*9*9*9*9*9*9*9*9)
# S = "leet2code3"
# K = 10
# S = "a2345678999999999999999"
# K = 1
# S = "ha22"
# K = 5
S = "abc"
K = 1
print(Solution().decodeAtIndex(S, K))












