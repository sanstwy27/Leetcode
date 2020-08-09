# ============================================================================
# Name        : Leetcode.836. Rectangle Overlap
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        if((rec2[0] < rec1[0] and rec1[0] < rec2[2]) or
                (rec1[0] <= rec2[0] and rec2[0] < rec1[2])):
            if((rec2[1] < rec1[1] and rec1[1] < rec2[3]) or
                    (rec1[1] <= rec2[1] and rec2[1] < rec1[3])):
                return True            
        return False


rec1 = [0,0,2,2]
rec2 = [1,1,3,3]
# rec1 = [0,0,1,1]
# rec2 = [1,0,2,1]
# rec1 = [7,8,13,15]
# rec2 = [10,8,12,20]
print(Solution().isRectangleOverlap(rec1, rec2))