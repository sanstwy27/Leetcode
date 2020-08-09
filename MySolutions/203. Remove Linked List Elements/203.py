# ============================================================================
# Name        : Leetcode.203. Remove Linked List Elements
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
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        pre = None
        cur = head
        while(cur):
            if(cur.val == val):
                if(not pre):
                    cur = cur.next
                    del head
                    head = cur
                    continue
                else:
                    cur = cur.next
                    del pre.next
                    pre.next = cur
                    continue
            if(cur):
                pre = cur
                cur = cur.next

        return head



l1 = ListNode(1)
l2 = ListNode(2)
l3 = ListNode(6)
l4 = ListNode(3)
l5 = ListNode(4)
l6 = ListNode(5)
l7 = ListNode(6)
l1.next = l2
l2.next = l3
l3.next = l4
l4.next = l5
l5.next = l6
l6.next = l7
root = Solution().removeElements(l1, 6)
while(root):
    print(root.val, " ", end="")
    root = root.next


