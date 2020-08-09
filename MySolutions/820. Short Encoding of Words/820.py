# ============================================================================
# Name        : Leetcode.820. Short Encoding of Words
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://www.cnblogs.com/grandyang/p/10089792.html
# ============================================================================
from typing import collections, List
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        s = set(words)
        words = list(s)
        for word in words:
            for i in range(1, len(word)):
                s.discard(word[i:])

        sum = len(s)
        for word in s:
            sum += len(word)
            
        return sum



words = ["time", "me", "bell"]
print(Solution().minimumLengthEncoding(words))











