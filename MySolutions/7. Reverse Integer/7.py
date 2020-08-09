# ============================================================================
# Name        : Leetcode.7. Reverse Integer
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    
    l_int_max = ["2", "1", "4", "7", "4", "8", "3", "6", "4", "7"]
    l_int_min = ["2", "1", "4", "7", "4", "8", "3", "6", "4", "8"]
    
    def reverse(self, x: int) -> int:
        s = list(str(x))
        if("-" in s):
            s.remove("-")
        s.reverse()

        # 2^32 - 1 =  2147483647
        # -2^32    = -2147483648
        if(len(s) == 10):
            if(x < 0):
                for i in range(0, len(s)):
                    if(int(s[i]) == int(self.l_int_min[i])):
                        continue
                    elif(int(s[i]) < int(self.l_int_min[i])):
                        break
                    else:
                        return 0
            else:
                for i in range(0, len(s)):
                    if(int(s[i]) == int(self.l_int_max[i])):
                        continue
                    elif(int(s[i]) < int(self.l_int_max[i])):
                        break
                    else:
                        return 0

        res = int(''.join(str(i) for i in s))
        if(x < 0):
            res = -res
        return res
        



x = 8463847412
print(Solution().reverse(x))






