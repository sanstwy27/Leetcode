# ============================================================================
# Name        : Leetcode.524. Longest Word in Dictionary through Deleting
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def findLongestWord(self, s: str, d: List[str]) -> str:        
        # Construct (length, str) of d
        sPair = list()
        for i in range(0, len(d)):
            sPair.append((len(d[i]), d[i]))
        sPair.sort(reverse = True)
        
        # Find ans
        ans = ""
        for (cnt, str) in sPair:
            if(cnt < len(ans)):
                break
            
            i = 0
            for c in s:
                if(c == str[i]):
                    i += 1
                if(i == cnt):
                    ans = str
                    break
        
        return ans


#s = "abpcplea"
#d = ["ale","apple","monkey","plea","bbea"]
#s = "abpcplea"
#d = ["a","b","c"]
#s = "abpcplea"
#d = ["z"]
#s = "bab"
#d = ["ba","ab","a","b"]
s = "aewfafwafjlwajflwajflwafj"
d = ["apple","ewaf","awefawfwaf","awef","awefe","ewafeffewafewf"]
print(Solution().findLongestWord(s, d))






