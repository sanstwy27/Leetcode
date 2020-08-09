# ============================================================================
# Name        : Leetcode.697. Degree of an Array
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://leetcode.com/problems/degree-of-an-array/discuss/
#               108682/The-example-for-this-question-is-poor
#    Input: [1, 7, 7, 5, 7, 1]
#    Output: 4
#    Explanation: The degree of this array is 3 because 7 appears the most of any number. 
#                 The shortest subarray that you can make that has a degree of 3 is [7,7,5,7]. 
#                 The length of that subarray is 4, so we return 4.
# ============================================================================
from typing import collections, List
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        if(len(nums) == 0):
            return 0
        else:
            c = collections.Counter(nums)
            degree = c.most_common(1)[0][1]
    
            res = len(nums)
            for k, v in c.most_common():
                if(v == degree):
                    first = nums.index(k)
                    end = len(nums)
                    for i in range(len(nums) - 1, -1, -1):
                        if(nums[i] == k):
                            end = i
                            break
                else:
                    break
                
                res = min(res, end - first + 1)
                if(res == degree):
                    break
                
            return res




nums = [1,2,2,3,1,4,2]
# nums = [1,2,2,3,1]
# nums = [1, 2]
print(Solution().findShortestSubArray(nums))

