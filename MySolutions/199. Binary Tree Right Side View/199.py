# ============================================================================
# Name        : Leetcode.199. Binary Tree Right Side View
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
    def rightSideView(self, root: TreeNode) -> List[int]:
        res = []
        q = collections.deque()
        q.append(root)
        size = 0
        while(len(q) > 0):
            r = None
            size = len(q)
            for i in range(0, size):
                r = q.popleft()
                if(r):
                    if(r.left):
                        q.append(r.left)
                    if(r.right):
                        q.append(r.right)
            if(r):
                res.append(r.val)
        return res



root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.right = TreeNode(5)
root.right.right = TreeNode(4)
print(Solution().rightSideView(root))


