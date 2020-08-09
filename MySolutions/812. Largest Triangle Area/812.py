# ============================================================================
# Name        : Leetcode.812. Largest Triangle Area
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://www.mathopenref.com/coordtrianglearea.html
# [Area]:
#    area = |[Ax*(By - Cy) + Bx*(Cy - Ay) + Cx*(Ay - By)] / 2|
# ============================================================================
from typing import collections, List
import math
class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        largest = 0
        for i in range(0, len(points)):
            for j in range(i + 1, len(points)):
                for k in range(j + 1, len(points)):
                    tmp1 = points[i][0] * (points[j][1] - points[k][1])
                    tmp2 = points[j][0] * (points[k][1] - points[i][1])
                    tmp3 = points[k][0] * (points[i][1] - points[j][1])
                    area = math.fabs((tmp1 + tmp2 + tmp3) / 2)
                    largest = max(largest, area)
        return largest



points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
# points = []
print(Solution().largestTriangleArea(points))



