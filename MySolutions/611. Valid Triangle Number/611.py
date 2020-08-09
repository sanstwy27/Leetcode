# ============================================================================
# Name        : Leetcode.611. Valid Triangle Number
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://www.cnblogs.com/grandyang/p/7053730.html
# ============================================================================
from typing import collections, List
class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums.sort()
        
        ans = 0
        for i in range(len(nums) - 1, 1, -1):
            left, right = 0, i - 1
            while(left < right):
                if(nums[left] + nums[right] > nums[i]):
                    ans += (right - left)
                    right -= 1
                else:
                    left +=1
                    
        return ans



nums = [2,2,3,4]
print(Solution().triangleNumber(nums))