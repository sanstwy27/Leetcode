# ============================================================================
# Name        : Leetcode.1013. Partition Array Into Three Parts With Equal Sum
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        sum = 0
        for i in A:
            sum += i
            
        if(sum % 3 != 0 or len(A) < 3):
            return False
        else:
            subSum = sum / 3
            
            a, b, c = 0, 0, 0
            for i in A:
                if(a != subSum):
                    a += i
                elif(b != subSum):
                    b += i
                elif(c != subSum):
                    c += i

            return (a == b) and (b == c)


A = [1,1,1]
print(Solution().canThreePartsEqualSum(A))







