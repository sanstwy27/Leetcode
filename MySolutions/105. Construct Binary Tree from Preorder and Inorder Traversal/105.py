# ============================================================================
# Name        : Leetcode.105. Construct Binary Tree from Preorder and Inorder Traversal
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
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if(len(preorder) == 0):
            return None
        elif(len(preorder) == 1):
            return TreeNode(preorder[0])
        else:
            root = self.buildSubTree(preorder, 0, len(preorder) - 1, inorder, 0, len(inorder) - 1)
            return root

    def buildSubTree(self, preorder: List[int], pL: int, pR: int, inorder: List[int], iL: int, iR: int) -> TreeNode:
        if(pL > pR):
            return None
        elif(pL == pR):
            return TreeNode(preorder[pL])
        else:
            mid = inorder.index(preorder[pL])
            root = TreeNode(preorder[pL])
            leftT = self.buildSubTree(preorder, pL + 1, pL + 1 + (mid - iL) - 1, inorder, iL, mid - 1)
            rightT = self.buildSubTree(preorder, pL + 1 + (mid - iL), pR, inorder, mid + 1, iR)
            root.left = leftT
            root.right = rightT
            return root




def showTree(node: TreeNode):
    if(node):
        showTree(node.left)
        print(node.val, " ", end="")
        showTree(node.right)
        

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
root = Solution().buildTree(preorder, inorder)
showTree(root)



