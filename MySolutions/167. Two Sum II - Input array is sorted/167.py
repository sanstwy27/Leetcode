# ============================================================================
# Name        : Leetcode.167. Two Sum II - Input array is sorted
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        c = collections.Counter(numbers)
        res = []
        for i in range(0, len(numbers)):
            if(numbers[i] == (target - numbers[i]) and c[target - numbers[i]] > 1):
                res.append(i + 1)
                res.append(i + 2)
                break
            if(c[target - numbers[i]] > 0):
                x = self.searchIndex(numbers, target - numbers[i], 0, len(numbers) - 1)
                if(x != -1):
                        res.append(i + 1)
                        res.append(x + 1)
                        break
        res.sort()
        return res
            
    
    def searchIndex(self, numbers: List[int], num: int, left: int, right: int) -> int:
        if(left <= right):
            mid = left + int((right - left) / 2)
            if(numbers[mid] == num):
                return mid
            elif(numbers[mid] > num):
                return self.searchIndex(numbers, num, left, mid - 1)
            else:
                return self.searchIndex(numbers, num, mid + 1, right)
        return -1



numbers = [2,7,11,15]
target = 9
# numbers = [1,2,3,4,4,9,56,90]
# target = 8
print(Solution().twoSum(numbers, target))
