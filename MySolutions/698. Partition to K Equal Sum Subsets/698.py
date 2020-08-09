# ============================================================================
# Name        : Leetcode.698. Partition to K Equal Sum Subsets
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://www.cnblogs.com/grandyang/p/7733098.html
# ============================================================================
from typing import collections, List
class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        if(len(nums) < k):
            return False
        else:
            sum = 0
            for num in nums:
                sum += num      
            if(sum % k != 0):
                return False
            else:
                target = int(sum / k)
                while (nums.count(target)): 
                    nums.remove(target)
                    k -= 1
                nums.sort(reverse = True)
                visited = [False] * len(nums)
                
                return self.dfs(nums, k, target, 0, 0, visited)
    
    
    def dfs(self, nums: List[int], k: int, target: int, curSum: int, pos: int, visited: List[int]):
        if(k == 1):
            return True
        else:
            if(curSum == target):
                return self.dfs(nums, k - 1, target, 0, 0, visited)
            elif(curSum < target):
                for i in range(pos, len(nums)):
                    if(visited[i]):
                        continue
                    else:
                        if(curSum + nums[i] <= target):
                            visited[i] = True
                            if(self.dfs(nums, k, target, curSum + nums[i], i + 1, visited)):
                                return True
                            visited[i] = False
                
        return False





nums = [4, 3, 2, 3, 5, 2, 1]
k = 4
# nums = [2,2,2,2,3,4,5]
# k = 4
print(Solution().canPartitionKSubsets(nums, k))


