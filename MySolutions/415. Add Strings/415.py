# ============================================================================
# Name        : Leetcode.415. Add Strings
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        
        l_num1 = list(num1)
        l_num2 = list(num2)
        l_num1.reverse()
        l_num2.reverse()
        
        res = ""
        carry = 0
        
        for i in range(0, max(len(l_num1), len(l_num2))):
            n1 = 0
            if(i < len(l_num1)):
                n1 = int(l_num1[i])
        
            n2 = 0
            if(i < len(l_num2)):
                n2 = int(l_num2[i])

            print(n1, ", ", n2)
            res = str((n1 + n2 + carry) % 10) + res                 
            carry = int((n1 + n2 + carry) / 10)
            
        if(carry > 0):
            res = str(carry) + res
        return res



# num1 = "4651231"
# num2 = "1345456456456"
num1 = "1"
num2 = "9"
print(Solution().addStrings(num1, num2))








