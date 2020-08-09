# ============================================================================
# Name        : Leetcode.771. Jewels and Stones
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        haveJ = 0
        Sc = collections.Counter(S)
        for c in J:
            if(Sc[c] > 0):
                haveJ += Sc[c]
        return haveJ
        
        

# J = "aA"
# S = "aAAbbbb"
J = ""
S = "ZZ"
print(Solution().numJewelsInStones(J, S))

