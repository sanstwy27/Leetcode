# ============================================================================
# Name        : Leetcode.1122. Relative Sort Array
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        c = collections.Counter(arr1)
        res = []
        for i in arr2:
            for j in range(0, c[i]):
                res.append(i)
                c[i] -= 1
                if(c[i] <= 0):
                    c.pop(i, -1)
        tmp = []
        for k, v in c.items():
            for i in range(0, v):
                tmp.append(k)
        tmp.sort()
        res += tmp

        return res
    
    


# arr1 = [2,3,1,3,2,4,6,7,9,2,19]
# arr2 = [2,1,4,3,9,6]
arr1 = [28,6,22,8,44,17]
arr2 = [22,28,8,6]
print(Solution().relativeSortArray(arr1, arr2))

