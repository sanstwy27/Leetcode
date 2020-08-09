# ============================================================================
# Name        : Leetcode.865. Smallest Subtree with all the Deepest Nodes
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
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        dict = {}
        deepest = self.setDepth(root, 0, dict)
        return self.deepestSmallestSubtree(root, dict, deepest)
        
    def deepestSmallestSubtree(self, node: TreeNode, dict: dict(), deepest: int) -> TreeNode:
        if(node):
            if(node.left and node.right):
                if(dict[node.left] == deepest and dict[node.right] == deepest):
                    return node
                if(dict[node.left] == deepest):
                    return self.deepestSmallestSubtree(node.left, dict, deepest)
                if(dict[node.right] == deepest):
                    return self.deepestSmallestSubtree(node.right, dict, deepest)
            if(node.left):
                return self.deepestSmallestSubtree(node.left, dict, deepest)
            if(node.right):
                return self.deepestSmallestSubtree(node.right, dict, deepest)
            
            return node
        return None
        
    def setDepth(self, node: TreeNode, depth: int, dict: dict()):
        if(node):
            left = self.setDepth(node.left, depth + 1, dict)
            right = self.setDepth(node.right, depth + 1, dict)
            dict[node] = max(left, right)
            return max(left, right)
        return depth


def show(node: TreeNode):
    if(node):
        show(node.left)
        print(node.val, " ", end="")
        show(node.right)

# root = TreeNode(3)
# root.left = TreeNode(5)
# root.right = TreeNode(1)
# root.left.left = TreeNode(6)
# root.left.right = TreeNode(2)
# root.left.right.left = TreeNode(7)
# root.left.right.right = TreeNode(4)
# root.right.left = TreeNode(0)
# root.right.right = TreeNode(8)
# res = Solution().subtreeWithAllDeepest(root)
# show(res)


root = TreeNode(1)
res = Solution().subtreeWithAllDeepest(root)
show(res)

