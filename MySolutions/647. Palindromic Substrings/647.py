# ============================================================================
# Name        : Leetcode.647. Palindromic Substrings
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        total = 0
        sSets, hit = set(), set()
        for l in range(1, n + 1):
            for pos in range(0, n - l + 1):
                substr = s[pos : pos + l]
                if(substr in hit):
                    total += 1
                else:
                    if(substr in sSets):
                        continue
                    else:
                        if(self.isPald(substr, 0, len(substr) - 1)):
                            total += 1
                            hit.add(substr)
                        sSets.add(substr)
        return total

    def isPald(self, s: str, start: int, end: int) -> bool:
        if(end >= len(s)):
            return False
        while(start < end):
            if(s[start] == s[end]):
                start += 1
                end -= 1
            else:
                return False
        return True


print(Solution().countSubstrings("aaa"))











