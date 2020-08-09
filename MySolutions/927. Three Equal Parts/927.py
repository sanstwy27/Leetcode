# ============================================================================
# Name        : Leetcode.927. Three Equal Parts
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def threeEqualParts(self, A: List[int]) -> List[int]:
        iList = [[-1,-1]]
        sum = 0
        for i in range(len(A)):
            if(A[i] == 1):
                sum += 1
                iList.append([sum, i])
        
        if(sum % 3 != 0):
            return [-1, -1]
        elif(sum == 0):
            return [0, len(A) - 1]
        else:
            p1 = ((sum * 1) // 3)
            p2 = ((sum * 2) // 3)
            p3 = ((sum * 3) // 3)
            
            # Start Point
            s3 = len(A) - 1
            s2 = iList[p2][1] + (s3 - iList[p3][1])
            s1 = iList[p1][1] + (s3 - iList[p3][1])
            
            # Check isEqualParts
            i1, i2, i3 = s1, s2, s3
            cnt = A[i1] + A[i2] + A[i3]
            while(cnt != sum):
                if(cnt % 3 != 0):
                    return [-1, -1]
                else:
                    if(i1 - 1 >= 0):
                        i1 -= 1
                        cnt += A[i1]
                    if(i2 - 1 > s1):
                        i2 -= 1
                        cnt += A[i2]
                    if(i3 - 1 > s2):
                        i3 -= 1
                        cnt += A[i3]
            return [s1, s2 + 1]


# A = [1,1,0,1]
# A = [1,1,0,0,1]
# A = [1,0,1,1,0]
# A = [1,0,0,0,1,0,1,0,0]
# A = [0,0,0,0,0]
print(Solution().threeEqualParts(A))

