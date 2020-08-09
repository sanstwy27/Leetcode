# ============================================================================
# Name        : Leetcode.112. Path Sum
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
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        return self.dfs(root, sum, 0)
        
    def dfs(self, node: TreeNode, target: int, curSum: int) -> bool:
        if(node):
            curSum += node.val
            if(curSum == target):
                if(node.left == None and node.right == None):
                    return True
            if(self.dfs(node.left, target, curSum)):
                return True
            if(self.dfs(node.right, target, curSum)):
                return True

        return False



# root = TreeNode(5)
# root.left = TreeNode(4)
# root.right = TreeNode(8)
# root.left.left = TreeNode(11)
# root.left.left.left = TreeNode(7)
# root.left.left.right = TreeNode(2)
# root.right.left = TreeNode(13)
# root.right.right = TreeNode(4)
# root.right.right.right = TreeNode(1)
# print(Solution().hasPathSum(root, 18))

root = TreeNode(1)
root.left = TreeNode(2)
print(Solution().hasPathSum(root, 1))

