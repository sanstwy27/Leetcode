# ============================================================================
# Name        : Leetcode.637. Average of Levels in Binary Tree
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
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        res = []
        self.dfs(root, 0, res)
        for i in range(0, len(res)):
            res[i] = sum(res[i]) / len(res[i])
        return res

    def dfs(self, node: TreeNode, level: int, res: List[float]):
        if(node == None):
            return
        else:
            if(level == len(res)):
                res.append([])
                
            res[level].append(node.val)
            if(node.left):
                self.dfs(node.left, level + 1, res)
            if(node.right):
                self.dfs(node.right, level + 1, res)


root = TreeNode(3)
root.left = TreeNode(9)
root.right = TreeNode(20)
root.right.left = TreeNode(15)
root.right.right = TreeNode(7)
print(Solution().averageOfLevels(None))







