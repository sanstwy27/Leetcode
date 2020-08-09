# ============================================================================
# Name        : Leetcode.1287. Element Appearing More Than 25% In Sorted Array
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        c = collections.Counter(arr)
        return c.most_common(1)[0][0]


arr = [1,2,2,6,6,6,6,7,10]
print(Solution().findSpecialInteger(arr))
