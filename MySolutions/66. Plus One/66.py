# ============================================================================
# Name        : Leetcode.66. Plus One
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if(len(digits) == 0):
            return [0]

        carry = 1
        for i in range(len(digits) - 1, -1, -1):
            digits[i] = digits[i] + carry
            carry = digits[i] // 10
            digits[i] = digits[i] % 10
        if(carry > 0):
            digits.insert(0, carry)
        return digits











digits = [4,3,2,1]
# digits = [1,9,9,9,9]
# digits = [0]
print(Solution().plusOne(digits))






