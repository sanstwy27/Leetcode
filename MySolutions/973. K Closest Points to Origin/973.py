# ============================================================================
# Name        : Leetcode.973. K Closest Points to Origin
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://leetcode.com/problems/k-closest-points-to-origin/solution/
# ============================================================================
from typing import collections, List
class Solution(object):
    def kClosest(self, points, K):
        points.sort(key = lambda P: P[0]**2 + P[1]**2)
        return points[:K]





points = [[3,3],[2,9],[5,-1],[-2,4],[0,9],[0,5],[0,-3],[-3,0],[-5,0]]
K = 2
print(Solution().kClosest(points, K))
