# ============================================================================
# Name        : Leetcode.1080. Insufficient Nodes in Root to Leaf Paths
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
    def sufficientSubset(self, root: TreeNode, limit: int) -> TreeNode:
        if(root):
            x = self.prune(root, limit, 0)
            if(x < limit):
#                 del root
                root = None
        return root

    def prune(self, node: TreeNode, limit: int, cur: int) -> int:
        if(node):
            leftSum = float("inf")
            if(node.left):
                leftSum = self.prune(node.left, limit, cur + node.val)
            rightSum = float("inf")
            if(node.right):
                rightSum = self.prune(node.right, limit, cur + node.val)
            
#             print("== ", node.val, ", ", leftSum, ", ", rightSum)
            if(node.left and node.right):
                if(leftSum < limit):
#                     del node.left
                    node.left = None
                if(rightSum < limit):
#                     del node.right
                    node.right = None
                return max(leftSum, rightSum)
            elif(node.left):
                if(leftSum < limit):
#                     del node.left
                    node.left = None
                return leftSum
            elif(node.right):
                if(rightSum < limit):
#                     del node.right
                    node.right = None
                return rightSum
            else:
                return cur + node.val
        else:
            return cur



def show(node: TreeNode):
    if(node):
        show(node.left)
        print(node.val, " ", end="")
        show(node.right)
    else:
        print(" null ", end="")



# root = TreeNode(1)
# root.left = TreeNode(2)
# root.right = TreeNode(-3)
# root.left.left = TreeNode(-5)
# root.right.left = TreeNode(4)
# limit = -1
# res = Solution().sufficientSubset(root, limit)
# show(res)


# root = TreeNode(1)
# root.left = TreeNode(2)
# root.right = TreeNode(3)
# root.left.left = TreeNode(4)
# root.left.right = TreeNode(-99)
# root.right.left = TreeNode(-99)
# root.right.right = TreeNode(7)
# root.left.left.left = TreeNode(8)
# root.left.left.right = TreeNode(9)
# root.left.right.left = TreeNode(-99)
# root.left.right.right = TreeNode(-99)
# root.right.left.left = TreeNode(12)
# root.right.left.right = TreeNode(13)
# root.right.right.left = TreeNode(-99)
# root.right.right.right = TreeNode(14)
# limit = 1
# res = Solution().sufficientSubset(root, limit)
# show(res)


root = TreeNode(10)
root.left = TreeNode(5)
root.right = TreeNode(10)
limit = 21
res = Solution().sufficientSubset(root, limit)
show(res)

