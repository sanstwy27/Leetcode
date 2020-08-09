# ============================================================================
# Name        : Leetcode.1260. Shift 2D Grid
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        d = collections.deque()
        for i in range(0, len(grid)):
            for j in range(0, len(grid[0])):
                d.append(grid[i][j])
        d.rotate(k)
        for i in range(0, len(grid)):
            for j in range(0, len(grid[0])):
                grid[i][j] = d.popleft()
                
        return grid



grid = [[1,2,3],[4,5,6],[7,8,9]]
k = 1
print(Solution().shiftGrid(grid, k))