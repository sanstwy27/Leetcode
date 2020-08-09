# ============================================================================
# Name        : Leetcode.116. Populating Next Right Pointers in Each Node
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        d = collections.deque()
        d.append(root)
        while(len(d) > 0):
            size = len(d)
            pre, cur = None, None
            for i in range(0, size):
                pre = cur
                cur = d.popleft()
                if(pre):
                    pre.next = cur
                if(cur):
                    if(cur.left):
                        d.append(cur.left)
                    if(cur.right):
                        d.append(cur.right)
        return root

def show(root: Node):
    d = collections.deque()
    d.append(root)
    while(len(d) > 0):
        size = len(d)
        for i in range(0, size):
            cur = d.popleft()
            if(cur.next):
                print(cur.val, " ", end="")
            else:
                print(cur.val, "# ", end="")
            
            if(cur.left):
                d.append(cur.left)
            if(cur.right):
                d.append(cur.right)
    return



root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)
res = Solution().connect(root)
show(res)






