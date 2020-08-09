# ============================================================================
# Name        : Leetcode.1175. Prime Arrangements
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
        
        primeCnt = 0
        nPrimeCnt = 0
        for i in range(1, n + 1):
            if(i in primes):
                primeCnt += 1
            else:
                nPrimeCnt += 1
        
        p1 = self.permutations(primeCnt)
        p2 = self.permutations(nPrimeCnt)
        res = (p1 * p2) % (10**9 + 7)
        return res
    
    def permutations(self, n: int) -> int:
        res = 1
        for i in range(1, n + 1):
            res = (res * i) % (10**9 + 7)
        return res


n = 5
print(Solution().numPrimeArrangements(n))





