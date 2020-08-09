# ============================================================================
# Name        : Leetcode.345. Reverse Vowels of a String
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]
        strList = list(s)
        left, right = 0, len(s) - 1
        while(left < right):
            if(strList[left] not in vowels):
                left += 1
            if(strList[right] not in vowels):
                right -= 1
            if(strList[left] in vowels and strList[right] in vowels):
                strList[left], strList[right] = strList[right], strList[left]
                left += 1
                right -= 1
        return "".join(strList)


s = "leetcode"
# s = ""
print(Solution().reverseVowels(s))


