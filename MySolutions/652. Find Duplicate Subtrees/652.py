# ============================================================================
# Name        : Leetcode.652. Find Duplicate Subtrees
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://leetcode.com/problems/find-duplicate-subtrees/solution/
# ============================================================================
from typing import collections, List
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        serial = collections.Counter()
        res = []
        self.serializeTree(root, serial, res)
        return res

    def serializeTree(self, node: TreeNode, serial: collections.Counter(), res: List[TreeNode]) -> str:
        if(not node):
            return "#"
        else:
            key = str(node.val) + "," + \
                    self.serializeTree(node.left, serial, res) + "," + \
                    self.serializeTree(node.right, serial, res)
            serial[key] += 1
            if(serial[key] == 2):
                print(key)
                res.append(node)
            return key


root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.right.left = TreeNode(2)
root.right.right = TreeNode(4)
root.right.left.left = TreeNode(4)
Solution().findDuplicateSubtrees(root)







