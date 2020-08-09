# ============================================================================
# Name        : Leetcode.222. Count Complete Tree Nodes
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
    def countNodes(self, root: TreeNode) -> int:
        cnt = 0
        if(root):
            d = collections.deque()
            d.append(root)
            process = True
            while(len(d)):
                size = len(d)
                cnt += size
                for i in range(0, size):
                    t = d.popleft()
                    if(t.left):
                        if(t.right):
                            if(process):
                                d.append(t.left)
                                d.append(t.right)
                        else:
                            if(process):
                                d.append(t.left)
                            process = False
                    else:
                        process = False
        return cnt




root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
# root.left.left = TreeNode(4)
# root.left.right = TreeNode(5)
root.right.left = TreeNode(6)
print(Solution().countNodes(root))


