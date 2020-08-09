# ============================================================================
# Name        : Leetcode.95. Unique Binary Search Trees II
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://www.cnblogs.com/grandyang/p/4301096.html
# ============================================================================
from typing import collections, List
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        if(n == 0):
            return []
        else:
            return self.construct(1, n)
    
    def construct(self, start: int, end: int) -> List[TreeNode]:
        if(start > end):
            return [None]
        else:
            res = []
            for i in range(start, end + 1):
                left = self.construct(start, i - 1)
                right = self.construct(i + 1, end)
                for l in left:
                    for r in right:
                        node = TreeNode(i)
                        node.left = l
                        node.right = r
                        res.append(node)
            
            return res 


import queue
def showTree(q: queue):
    while(not q.empty()):
        x = q.get() 
        if(x):
            print(" ", x.val, end="")
            q.put(x.left)
            q.put(x.right)
        else:
            print(" null", end="")

n = 3
res = Solution().generateTrees(n)
for t in res:
    q = queue.Queue()
    q.put(t)
    showTree(q)
    print()
