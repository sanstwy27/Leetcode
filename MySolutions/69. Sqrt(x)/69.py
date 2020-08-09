# ============================================================================
# Name        : Leetcode.69. Sqrt(x)
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://www.cnblogs.com/grandyang/p/4346413.html
# ============================================================================
from typing import collections, List
class Solution:
    def mySqrt(self, x: int) -> int:
        if(x <= 1):
            return x
        else:
            ans = 0
            left, right = 0, int(x / 2) + 1
            while(left < right):
                mid = int((left + right) / 2)
                if(mid * mid <= x):
                    ans = mid
                    left = mid + 1
                else:
                    right = mid
            return ans


print(Solution().mySqrt(2147395599))

