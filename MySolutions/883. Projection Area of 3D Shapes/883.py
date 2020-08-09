# ============================================================================
# Name        : Leetcode.883. Projection Area of 3D Shapes
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def projectionArea(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        else:
            r = len(grid)
            c = len(grid[0])
            shadow = 0
            
            for i in range(0, r):
                shadow += max(grid[i])
                
            for i in range(0, c):
                colMax = 0
                for j in range(0, r):
                    colMax = max(colMax, grid[j][i])
                    if(grid[j][i] > 0):
                        shadow += 1
                shadow += colMax
    
            return shadow


grid = [[2,2,2],[2,1,2],[2,2,2]]
print(Solution().projectionArea(grid))


