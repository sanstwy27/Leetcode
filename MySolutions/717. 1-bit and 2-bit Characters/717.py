# ============================================================================
# Name        : Leetcode.717. 1-bit and 2-bit Characters
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        i = 0
        one = False
        while(i < len(bits)):
            if(bits[i] == 1):
                i += 2
                one = False
            else:
                i += 1
                one = True

        return one



# bits = [1, 0, 0]
# bits = [1, 1, 1, 0]
bits = [0, 1]
print(Solution().isOneBitCharacter(bits))


