# ============================================================================
# Name        : Leetcode.1033. Moving Stones Until Consecutive
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        num = [a, b, c]
        num.sort()

        list1 = list(range(num[0], num[1]))
        list1.remove(num[0])
        list2 = list(range(num[1], num[2]))
        list2.remove(num[1])
        len1 = len(list1)
        len2 = len(list2)
        
        maxMove = len1 + len2
        minMove = 0
        if(len1 == 0 and len2 == 0):
            minMove = 0
        elif(len1 <= 1 or len2 <= 1):
            minMove = 1
        elif(len1 >= 1 and len2 >= 1):
            minMove = 2    
            
        return [minMove, maxMove]




#a, b, c = 1, 2, 5
#a, b, c = 4, 3, 2
#a, b, c = 3, 4, 1
#a, b, c = 1, 7, 2
a, b, c = 7, 4, 1
#a, b, c = 3, 5, 1
print(Solution().numMovesStones(a, b, c))