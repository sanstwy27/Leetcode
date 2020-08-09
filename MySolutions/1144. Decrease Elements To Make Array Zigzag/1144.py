# ============================================================================
# Name        : Leetcode.1144. Decrease Elements To Make Array Zigzag
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def movesToMakeZigzag(self, nums: List[int]) -> int:
        case1, case2 = 0, 0
        for i in range(0, len(nums)):
            move = 0
            if(i + 1 < len(nums)):
                if(i == 0):
                    if(nums[i] >= nums[i + 1]):
                        move += (nums[i] - nums[i + 1] + 1)
                else:
                    if(nums[i] >= nums[i - 1] and nums[i] >= nums[i + 1]):
                        move += (nums[i] - min(nums[i - 1], nums[i + 1]) + 1)
                    elif(nums[i] >= nums[i - 1]):
                        move += (nums[i] - nums[i - 1] + 1)
                    elif(nums[i] >= nums[i + 1]):
                        move += (nums[i] - nums[i + 1] + 1)
            else:
                if(nums[i] >= nums[i - 1]):
                    move += (nums[i] - nums[i - 1] + 1)
            
            if(i % 2 == 0):
                case1 += move
            else:
                case2 += move
            move = 0
            
        return min(case1, case2)



# nums = [9,6,1,6,2]
nums = [1,2,3]
print(Solution().movesToMakeZigzag(nums))

