# ============================================================================
# Name        : Leetcode.872. Leaf-Similar Trees
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
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        leaf1 = []
        leaf2 = []
        self.buildLeafSeq(root1, leaf1)
        self.buildLeafSeq(root2, leaf2)
        print(leaf1)
        print(leaf2)
        return leaf1 == leaf2

    def buildLeafSeq(self, root: TreeNode, leaf: List[int]):
        q = collections.deque()
        q.append(root)
        while(len(q) != 0):
            cur = q.popleft()
            if(cur):
                if(cur.left == None and cur.right == None):
                    leaf.append(cur.val)
                else:
                    if(cur.right != None):
                        q.appendleft(cur.right)
                    if(cur.left != None):
                        q.appendleft(cur.left)
                        


root1 = TreeNode(3)
root1.left = TreeNode(5)
root1.right = TreeNode(1)

root2 = TreeNode(3)
root2.left = TreeNode(5)
root2.right = TreeNode(1)
root2.left.left = TreeNode(5)

print(Solution().leafSimilar(None, None))















