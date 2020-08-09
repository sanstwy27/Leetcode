# ============================================================================
# Name        : Leetcode.846. Hand of Straights
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://buptwc.com/2018/06/04/Leetcode-846-Hand-of-Straights/
# ============================================================================
from typing import collections, List
class Solution:
    def isNStraightHand(self, hand: List[int], W: int) -> bool:
        if(len(hand) % W != 0):
            return False
        
        d = collections.Counter(hand)
        for key in sorted(d.keys()):
            if d[key] > 0:
                # 'slicing' and backwards
                for step in reversed(range(W)):
                    d[key + step] -= d[key]
                    if d[key + step] < 0:
                        return False
        return True


hand = [1,2,3,6,2,3,4,7,8]
W = int(3)
print(Solution().isNStraightHand(hand, W))
