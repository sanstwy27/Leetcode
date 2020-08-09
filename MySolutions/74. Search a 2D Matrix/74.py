# ============================================================================
# Name        : Leetcode.74. Search a 2D Matrix
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False
        
        m, n = len(matrix), len(matrix[0])
        left = 0
        right = m * n - 1
        while(left <= right):
            mid = left + int((right - left) / 2)
            if(matrix[int(mid / n)][mid % n] == target):
                return True
            elif(matrix[int(mid / n)][mid % n] < target):
                left = mid + 1
            elif(matrix[int(mid / n)][mid % n] > target):
                right = mid - 1    
        
        return False



# matrix = [
#   [1,   3,  5,  7],
#   [10, 11, 16, 20],
#   [23, 30, 34, 50]
# ]
matrix = []
target = 0
print(Solution().searchMatrix(matrix, target))











