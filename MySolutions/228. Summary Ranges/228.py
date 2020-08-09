# ============================================================================
# Name        : Leetcode.228. Summary Ranges
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        res = []
        d = collections.deque()
        for i in nums:
            if(len(d) == 0):
                d.append(i)
            else:
                if(i - d[len(d) - 1] > 1):
                    if(len(d) == 1):
                        res.append(str(d.popleft()))
                    else:
                        res.append(str(min(d)) + "->" + str(max(d)))
                    d.clear()
                d.append(i)
                
        if(len(d) > 0):
            if(len(d) == 1):
                res.append(str(d.popleft()))
            else:
                res.append(str(min(d)) + "->" + str(max(d)))
        
        return res







# nums = [0,2,3,4,6,8,9]
nums = [0,1,2,4,5,7]
print(Solution().summaryRanges(nums))


