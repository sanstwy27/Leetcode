# ============================================================================
# Name        : Leetcode.934. Shortest Bridge
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def shortestBridge(self, A: List[List[int]]) -> int:
        # Island 1
        island1 = set()
        for i in range(0, len(A)):
            for j in range(0, len(A)):
                if(A[i][j] == 1 and (len(island1) == 0)):
                    self.initIsland(A, i, j, island1)
        # Bridge + 1
        for i in range(1, len(A) + 1):
            tmp = self.expandIsland(A, island1)
            for (x, y) in tmp:
                if(A[x][y] == 1):
                    return i - 1
            island1 = island1.union(tmp)
        return 0
    
    def initIsland(self, A: List[List[int]], i: int, j: int, myset: set()):
        if(i >= 0 and i < len(A)) and (j >= 0 and j < len(A)):
            if((i, j) in myset):
                return
            else:
                if(A[i][j] == 1):
                    myset.add((i, j))
                    self.initIsland(A, i + 1, j, myset)
                    self.initIsland(A, i - 1, j, myset)
                    self.initIsland(A, i, j + 1, myset)
                    self.initIsland(A, i, j - 1, myset)
                    return
    
    def expandIsland(self, A: List[List[int]], myset: set()):
        tmp = set()
        for (i, j) in myset:
            if(i + 1 < len(A) and (i + 1, j) not in myset):
                tmp.add((i + 1, j))
            if(i - 1 >= 0 and (i - 1, j) not in myset):
                tmp.add((i - 1, j))
            if(j + 1 < len(A) and (i, j + 1) not in myset):
                tmp.add((i, j + 1))
            if(j - 1 >= 0 and (i, j - 1) not in myset):
                tmp.add((i, j - 1))
        return tmp



#A = [[0,1,0],[0,0,0],[0,0,1]]
A = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
print(Solution().shortestBridge(A))


