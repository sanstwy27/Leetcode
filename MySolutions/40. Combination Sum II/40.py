# ============================================================================
# Name        : Leetcode.40. Combination Sum II
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List, Dict
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        ans, cur = list(), []
        self.dfs(candidates, target, 0, cur, ans)
        return ans

    def dfs(self, candidates, target, start, cur, ans):
        """
            candidates: List[int],
                target: int,
                 start: int,
                   cur: List[int],
                   ans: List[List[int]]
        """
        if(start == len(candidates)):
            return
        else:
            for i in range(start, len(candidates)):
                cur.append(candidates[i])
                if(sum(cur) == target):
                    if(cur not in ans):
                        ans.append(cur.copy())
                if(sum(cur) < target):
                    self.dfs(candidates, target, i + 1, cur, ans)
                cur.pop()
                    
            return



candidates = [10,1,2,7,6,1,5]
target = 8
#candidates = [2,5,2,1,2]
#target = 5
print(Solution().combinationSum2(candidates, target))