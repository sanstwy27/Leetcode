# ============================================================================
# Name        : Leetcode.528. Random Pick with Weight
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://www.cnblogs.com/grandyang/p/9784690.html
# ============================================================================
from typing import collections, List
import random
class Solution:

    _sum = []

    def __init__(self, w: List[int]):
        
        self._sum = [0] * (len(w) + 1)
        for i in range(1, len(self._sum)):
            self._sum[i] = self._sum[i - 1] + w[i - 1]
        print(self._sum)

    def pickIndex(self) -> int:
        
        total = self._sum[len(self._sum) - 1]
        pick = total * random.random()
        return self.searchCeilIndex(0, len(self._sum), pick) - 1
    
    def searchCeilIndex(self, left: int, right: int, target: int) -> int:
        if(left < right):
            mid = left + int((right - left) / 2)
            if(self._sum[mid] > target):
                return self.searchCeilIndex(left, mid, target)
            else:
                return self.searchCeilIndex(mid + 1, right, target)
        return right


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()


w = [1,3]
obj = Solution(w)
print(obj.pickIndex())
print(obj.pickIndex())
print(obj.pickIndex())
print(obj.pickIndex())








