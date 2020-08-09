# ============================================================================
# Name        : Leetcode.530. Minimum Absolute Difference in BST
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
    def getMinimumDifference(self, root: TreeNode) -> int:
        if(root):
            res = float("inf")
            
            left = root.left
            while(left):
                if(left.right):
                    left = left.right
                else:
                    res = min(res, self.getMinimumDifference(root.left))
                    res = min(res, abs(root.val - left.val))
                    break

            right = root.right
            while(right):
                if(right.left):
                    right = right.left
                else:
                    res = min(res, self.getMinimumDifference(root.right))
                    res = min(res, abs(root.val - right.val))
                    break

            return res
        else:
            return float("inf")



# root = TreeNode(1)
# root.right = TreeNode(4)
# root.right.left = TreeNode(2)
# print(Solution().getMinimumDifference(root))


# root = TreeNode(236)
# root.left = TreeNode(104)
# root.right = TreeNode(701)
# root.left.right = TreeNode(227)
# root.right.right = TreeNode(911)
# print(Solution().getMinimumDifference(root))


root = TreeNode(543)
root.left = TreeNode(384)
root.right = TreeNode(652)
root.left.right = TreeNode(445)
root.right.right = TreeNode(699)
print(Solution().getMinimumDifference(root))




