# ============================================================================
# Name        : Leetcode.673. Number of Longest Increasing Subsequence
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://www.cnblogs.com/grandyang/p/7603903.html
# ============================================================================
from typing import collections, List
class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        n = len(nums)
        lenList = [1] * n
        cntList = [1] * n
        for i in range(0, n):
            for j in range(0, i):
                if(nums[i] > nums[j]):
                    if(lenList[i] == lenList[j] + 1):
                        cntList[i] += cntList[j]
                    if(lenList[i] < lenList[j] + 1):
                        lenList[i] = lenList[j] + 1
                        cntList[i] = cntList[j]
        ans = 0
        maxLen = max(lenList)
        for i in range(0, n):
            if(lenList[i] == maxLen):
                ans += cntList[i]
        
        return ans



#nums = [2,2,2,2,2]
#nums = [1,3,5,4,7]
nums = []
print(Solution().findNumberOfLIS(nums))