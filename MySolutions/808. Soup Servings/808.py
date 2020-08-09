# ============================================================================
# Name        : Leetcode.808. Soup Servings
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://leetcode.com/problems/soup-servings/discuss/ \
#               121711/C%2B%2BJavaPython-When-N-greater-4800-just-return-1
# ============================================================================
from typing import collections, List
import math
class Solution(object):
    memo = {}
    def soupServings(self, N):
        if N > 4800: return 1
        def f(a, b):
            if (a, b) in self.memo: return self.memo[a, b]
            if a <= 0 and b <= 0: return 0.5
            if a <= 0: return 1
            if b <= 0: return 0
            self.memo[(a, b)] = 0.25 * (f(a - 4, b) + f(a - 3, b - 1) + f(a - 2, b - 2) + f(a - 1, b - 3))
            return self.memo[(a, b)]
        N = math.ceil(N / 25.0)
        return f(N, N)



print(Solution().soupServings(800))


