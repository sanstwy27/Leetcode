# ============================================================================
# Name        : Leetcode.1072. Flip Columns For Maximum Number of Equal Rows
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        maxEqRow = 0
        n = len(matrix)
        s = set([tuple([1] * n), tuple([0] * n)])
        for r in matrix:
            if(tuple(r) not in s):
                r1 = r
                r2 = [i ^ 1 for i in r1]
                s.add(tuple(r1))
                s.add(tuple(r2))
    
                cnt = 0
                for testR in matrix:
                    if(testR == r1 or testR == r2):
                        cnt += 1
                        
                maxEqRow = max(maxEqRow, cnt)
            
        return maxEqRow




#print([0, 0, 1] == [0, 0, 1])
matrix = [[0,0,0],[0,0,1],[1,1,0]]
#matrix = [[0,1],[1,0]]
#matrix = [[0,1],[1,1]]
#matrix = []
print(Solution().maxEqualRowsAfterFlips(matrix))




