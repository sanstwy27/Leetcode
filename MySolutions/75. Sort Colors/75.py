# ============================================================================
# Name        : Leetcode.75. Sort Colors
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
# ============================================================================
from typing import collections, List
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        lo = 0
        mid = 0
        hi = len(nums) - 1
        
        while(mid <= hi):
            if(nums[mid] == 0):
                self.swapPosition(nums, lo, mid)
                lo += 1
                mid += 1
            elif(nums[mid] == 1):
                mid += 1
            elif(nums[mid] == 2):
                self.swapPosition(nums, mid, hi)
                hi -= 1
        
    def swapPosition(self, nums: List[int], pos1: int, pos2: int):
        nums[pos1], nums[pos2] = nums[pos2], nums[pos1]


nums = [0,2,1]
Solution().sortColors(nums)
print(nums)