# ============================================================================
# Name        : Leetcode.19. Remove Nth Node From End of List
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        l = []
        cur = head
        while(cur):
            l.append(cur)
            cur = cur.next
        
        if(n == len(l)):
            return head.next
        else:
            l[len(l) - n - 1].next = l[len(l) - n].next
            return head



l1 = ListNode(1)
l2 = ListNode(2)
l3 = ListNode(3)
l4 = ListNode(4)
l5 = ListNode(5)
l1.next = l2
l2.next = l3
l3.next = l4
l4.next = l5
res = Solution().removeNthFromEnd(None, 2)
while(res):
    print(res.val, " ", end="")
    res = res.next







