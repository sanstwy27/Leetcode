# ============================================================================
# Name        : Leetcode.1161. Maximum Level Sum of a Binary Tree
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        count = collections.Counter()
        self.calLevelSum(1, root, count)
        #print(sorted(count.items()))
        maxLevel = 0
        maxSum = 0
        for c, sum in count.items():
            if(sum > maxSum):
                maxLevel = c
                maxSum = sum
        return maxLevel
    
    def calLevelSum(self, level: int, node: TreeNode, count: collections.Counter):
        if(node == None):
            return
        
        count[level] += node.val
        self.calLevelSum(level + 1, node.left, count)
        self.calLevelSum(level + 1, node.right, count)

#[989,null,10250,98693,-89388,null,null,null,-32127]
root = TreeNode(989)
root.right = TreeNode(10250)
root.right.left = TreeNode(98693)
root.right.right = TreeNode(-89388)
root.right.left.left = TreeNode(-32127)

print(Solution().maxLevelSum(root))


