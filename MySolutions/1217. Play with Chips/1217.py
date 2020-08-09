# ============================================================================
# Name        : Leetcode.1217. Play with Chips
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://leetcode.com/problems/play-with-chips/discuss/
#               398329/Not-understanding-the-problem
#
#   for [1, 2, 3], would look like:
#   ----------------------------------------
#   | position 1 | position 2 | position 3 |
#   ----------------------------------------
#   |   chip 1   |   chip 2   |   chip 3   |
#   ----------------------------------------
#
#   for [2, 2, 2, 3, 3], would look like:
#   ---------------------------
#   | position 2 | position 3 |
#   ---------------------------
#   |   chip 1   |   chip 4   |
#   ---------------------------
#   |   chip 2   |   chip 5   |
#   ---------------------------
#   |   chip 3   |            |
#   ---------------------------
#
# ============================================================================
from typing import collections, List
class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        odd = 0
        even = 0
        for i in chips:
            if(i % 2 == 1):
                odd += 1
            else:
                even += 1
        
        return min(odd, even)



chips = [2,2,2,3,3]
print(Solution().minCostToMoveChips(chips))

