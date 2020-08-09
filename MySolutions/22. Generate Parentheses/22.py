# ============================================================================
# Name        : Leetcode.22. Generate Parentheses
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        self.genParenthesis(n, n, "", res)
        return res

    def genParenthesis(self, left: int, right: int, cur: str, res: List[str]):
        if(left == 0 and right == 0):
            res.append(cur)
        else:
            if(left - 1 >= 0):
                self.genParenthesis(left - 1, right, cur + "(", res)
            if(right - 1 >= left):
                self.genParenthesis(left, right - 1, cur + ")", res)



n = 5
print(Solution().generateParenthesis(n))

