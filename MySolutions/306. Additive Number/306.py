# ============================================================================
# Name        : Leetcode.306. Additive Number
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        cont = list()
        return self.dfs(num, 0, cont)

    def dfs(self, num: str, start: int, list: List[int]) -> bool:
        if(start == len(num)):
            return len(list) > 2

        n = len(list)
        digit = 1 if num[start] == '0' else len(num)
        curNum = 0
        for i in range(start, min(start + digit, len(num))):
            curNum = curNum * 10 + int(num[i])
            if(n >= 2):
                target = list[n - 1] + list[n - 2]
                if(curNum > target): return False
                elif(curNum < target): continue
            
            list.append(curNum)
            if(self.dfs(num, i + 1, list)):
                return True
            list.pop()

        return False



print(Solution().isAdditiveNumber("011235813"))