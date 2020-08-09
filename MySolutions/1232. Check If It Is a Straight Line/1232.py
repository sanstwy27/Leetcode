# ============================================================================
# Name        : Leetcode.1232. Check If It Is a Straight Line
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        coordinates.sort()
        
        x1, y1 = coordinates[0]
        x2, y2 = coordinates[1]
        numerator = y2 - y1
        denominator = x2 - x1
        if(denominator == 0):
            denominator = 1
        slope = numerator / denominator
        offset = y1 - slope * x1
        
        for i in range(2, len(coordinates)):
            if(coordinates[i][1] != slope * coordinates[i][0] + offset):
                return False
        return True




# coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
coordinates = [[-3,-2],[-1,-2],[2,-2],[-2,-2],[0,-2]]
print(Solution().checkStraightLine(coordinates))





