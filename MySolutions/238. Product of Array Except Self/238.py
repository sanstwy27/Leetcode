# ============================================================================
# Name        : Leetcode.238. Product of Array Except Self
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://www.geeksforgeeks.org/a-product-array-puzzle/
# ============================================================================
from typing import collections, List
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [1] * n
        
        tmp = 1
        for i in range(1, n):
            res[i] = nums[i - 1] * tmp
            tmp = nums[i - 1] * tmp
        
        tmp = 1
        for i in range(n - 1, -1, -1):
            res[i] = res[i] * tmp
            tmp *= nums[i]
        
        return res






# nums = [1, 2, 3, 4]
nums = [1]
print(Solution().productExceptSelf(nums))
