# ============================================================================
# Name        : Leetcode.822. Card Flipping Game
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://blog.csdn.net/fuxuemingzhu/article/details/82861796
# ============================================================================
from typing import collections, List
class Solution:
    def flipgame(self, fronts: List[int], backs: List[int]) -> int:
        s = set()
        for i in range(0, len(backs)):
            if(fronts[i] == backs[i]):
                s.add(fronts[i])
        
        res = float("inf")
        for i in fronts:
            if(i not in s):
                res = min(res, i)
        for i in backs:
            if(i not in s):
                res = min(res, i)

        if(res != float("inf")):
            return res
        else:
            return 0 




fronts = [1,2,4,4,7]
backs = [1,3,4,1,3]
# fronts = [1,1]
# backs = [1,2]
print(Solution().flipgame(fronts, backs))



