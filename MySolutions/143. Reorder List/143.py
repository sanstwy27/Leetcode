# ============================================================================
# Name        : Leetcode.143. Reorder List
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
from math import ceil
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if(not head):
            return
        else:
            l = []
            cur = head.next
            while(cur):
                l.append(cur)
                cur = cur.next
    
            for i in range(0, ceil(len(l) / 2)):
                l[len(l) - 1 - i].next = l[i]
                if(i > 0):
                    l[i - 1].next = l[len(l) - 1 -i]
            if(len(l) > 0):
                l[ceil(len(l) / 2) - 1].next = None
                head.next = l[len(l) - 1]
            
            return head




# l1 = ListNode(1)
# l2 = ListNode(2)
# l3 = ListNode(3)
# l4 = ListNode(4)
# l5 = ListNode(5)
# l1.next = l2
# l2.next = l3
# l3.next = l4
# l4.next = l5


l1 = ListNode(1)
l2 = ListNode(2)
l3 = ListNode(3)
l4 = ListNode(4)
l1.next = l2
l2.next = l3
l3.next = l4


res = Solution().reorderList(l1)
while(res):
    print(res.val, " ", end="")
    res = res.next


