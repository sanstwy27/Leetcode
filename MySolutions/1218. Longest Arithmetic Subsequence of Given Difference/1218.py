# ============================================================================
# Name        : Leetcode.1218. Longest Arithmetic Subsequence of Given Difference
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://www.cnblogs.com/seyjs/p/11646631.html
# ============================================================================
from typing import collections, List
class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        dic = {}
        res = 1
        for i in arr:
            if(i - difference) in dic:
                dic[i] = dic[i - difference] + 1
            else:
                dic[i] = 1
            res = max(res, dic[i])
        
        print(dic)        
        return res



#arr = [1,2,3,4]
#difference = 1
#arr = [1,3,5,7]
#difference = 1
#arr = [1,5,7,8,5,3,4,2,1]
#difference = -2
#arr = [4,12,10,0,-2,7,-8,9,-9,-12,-12,8,8]
#difference = 0
arr = [-22,24,-16,23,22,28,-8,18,5,28,5,15,22,-16,20,-22,-8,4,-25,-21,14,7,2,-22,-8,17,27,-5]
difference = 26
print(Solution().longestSubsequence(arr, difference))

