# ============================================================================
# Name        : Leetcode.655. Print Binary Tree
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
import math
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def printTree(self, root: TreeNode) -> List[List[str]]:
        level = self.maxTree(root)
        n = int(math.pow(2, level) - 1)
        arr = []
        for i in range(0, level):
            arr.append([""] * n)
        
        self.locArr(root, arr, 0, 0, n - 1)
        
        return arr

    def locArr(self, node: TreeNode, arr: List[List[str]], level: int, left: int, right: int):
        if(node == None):
            return
        else:
            loc = left + int((right - left) / 2)
            arr[level][loc] = str(node.val)
            self.locArr(node.left, arr, level + 1, left, loc - 1)
            self.locArr(node.right, arr, level + 1, loc + 1, right)

    def maxTree(self, node: TreeNode):
        if(node == None):
            return 0
        else:
            return 1 + max(self.maxTree(node.left), self.maxTree(node.right))



root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.right = TreeNode(4)
print(Solution().printTree(root))