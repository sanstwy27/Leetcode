# ============================================================================
# Name        : Leetcode.910. Smallest Range II
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://leetcode.com/problems/smallest-range-ii/discuss/173377/C++JavaPython-Add-0-or-2-*-K
# ============================================================================
from typing import collections, List
class Solution:
    def smallestRangeII(self, A: List[int], K: int) -> int:
        A.sort()
        res = A[-1] - A[0]
        for i in range(len(A) - 1):
            big = max(A[-1], A[i] + 2 * K)
            small = min(A[i + 1], A[0] + 2 * K)
            res = min(res, big - small)
        return res
        


A = [1,3,6]
K = 3
print(Solution().smallestRangeII(A, K))