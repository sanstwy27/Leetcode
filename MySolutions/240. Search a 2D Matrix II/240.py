# ============================================================================
# Name        : Leetcode.240. Search a 2D Matrix II
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
import math
class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if(not matrix):
            return False
        else:
            if(not matrix[0]):
                return False
            else:
                return self.searchSubMatrix(matrix, target, 0, 0, len(matrix) - 1, len(matrix[0]) - 1)
        
    def searchSubMatrix(self, matrix, target, tlx, tly, brx, bry):
        if(target == matrix[tlx][tly]):
            return True
        elif(target < matrix[tlx][tly] or target > matrix[brx][bry]):
            return False
        else:
            if(tlx != brx or tly != bry):
                # Top-Left
                if(self.searchSubMatrix(matrix, target, tlx, tly, math.floor((tlx + brx) / 2), math.floor((tly + bry) / 2))):
                    return True
                # Top-Right
                if(self.searchSubMatrix(matrix, target, math.ceil((tlx + brx) / 2), tly, brx, math.floor((tly + bry) / 2))):
                    return True
                # Bottom-Left
                if(self.searchSubMatrix(matrix, target, tlx, math.ceil((tly + bry) / 2), math.floor((tlx + brx) / 2), bry)):
                    return True
                # Bottom-Right
                if(self.searchSubMatrix(matrix, target, math.ceil((tlx + brx) / 2), math.ceil((tly + bry) / 2), brx, bry)):
                    return True
            return False




# matrix = [
#   [1,   4,  7, 11, 15],
#   [2,   5,  8, 12, 19],
#   [3,   6,  9, 16, 22],
#   [10, 13, 14, 17, 24],
#   [18, 21, 23, 26, 30]
# ]
matrix = [[]]
target = 25
print(Solution().searchMatrix(matrix, target))



