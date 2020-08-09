# ============================================================================
# Name        : Leetcode.1128. Number of Equivalent Domino Pairs
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
import operator as op
from functools import reduce
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        if(len(dominoes) <= 1):
            return 0
        else:
            myCounter = collections.Counter()
            for a, b in dominoes:
                if a <= b:
                    myCounter[a * 10 + b] += 1
                else:
                    myCounter[b * 10 + a] += 1
            
            eqNum = 0
            for k, cnt in myCounter.items():
                if(cnt >= 2):
                    eqNum += int(self.ncr(cnt, 2))

            return eqNum

    def ncr(self, n, r):
        r = min(r, n-r)
        numer = reduce(op.mul, range(n, n-r, -1), 1)
        denom = reduce(op.mul, range(1, r+1), 1)
        return numer / denom



dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
#dominoes = [[1,2],[2,1],[3,4],[5,6]]
print(Solution().numEquivDominoPairs(dominoes))

