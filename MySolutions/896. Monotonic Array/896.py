# ============================================================================
# Name        : Leetcode.896. Monotonic Array
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        if(len(A) == 0):
            return False
        else:
            asc = A[0] <= A[len(A) - 1]
            tmp = A[0]
            for i in A:
                if(asc):
                    if(tmp > i):
                        return False
                    else:
                        tmp = i
                else:
                    if(tmp < i):
                        return False
                    else:
                        tmp = i
                        
            return True
            



A = [1,2,2,3]
#A = [1,3,2,4]
#A = []
print(len(A))
print(Solution().isMonotonic(A))



