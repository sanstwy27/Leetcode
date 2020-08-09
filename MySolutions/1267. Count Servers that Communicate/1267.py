# ============================================================================
# Name        : Leetcode.1267. Count Servers that Communicate
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   :  https://leetcode.jp/leetcode-1267-count-servers-that-communicate
# ============================================================================
from typing import collections, List
class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        row = [0] * len(grid)
        col = [0] * len(grid[0])
        for i in range(0, len(grid)):
            for j in range(0, len(grid[i])):
                if(grid[i][j] == 1):
                    row[i] += 1
                    col[j] += 1
        res = 0
        for i in range(0, len(grid)):
            if(row[i] == 0):
                continue
            for j in range(0, len(grid[i])):
                if(col[i] == 0):
                    continue
                else:
                    if(grid[i][j] == 1 and (row[i] > 1 or col[j] > 1)):
                        res += 1
        return res



grid = [[1,0],[1,1]]
# grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
# grid = [[1,0,0],[0,0,0],[1,0,1]]
print(Solution().countServers(grid))

