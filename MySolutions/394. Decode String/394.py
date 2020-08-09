# ============================================================================
# Name        : Leetcode.394. Decode String
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def decodeString(self, s: str) -> str:
        d = collections.deque()
        for i in range(0, len(s)):
            if(s[i] != "]"):
                d.append(s[i])
            else:
                subS = ""
                while(d[len(d) - 1] != "["):
                    subS = d.pop() + subS
                d.pop()

                times = 0
                digit = 1
                while(len(d) > 0 and d[len(d) - 1].isdigit()):
                    num = d.pop()
                    times += (int(num) * digit)
                    digit *= 10
                
                d.append(subS * times)
        
        res = ""
        while(len(d) > 0):
            res = res + d.popleft()
        return res



# s = "3[a]2[bc]"
# s = "3[a2[c]]"
# s = "2[abc]3[cd]ef"
s = ""
print(Solution().decodeString(s))



