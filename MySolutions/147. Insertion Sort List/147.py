# ============================================================================
# Name        : Leetcode.147. Insertion Sort List
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
    def insertionSortList(self, head: ListNode) -> ListNode:
        newList = None
        while(head):
            staticmethod(show(newList))
            pre = newList
            cur = newList
            while(cur):
                if(head.val > cur.val):
                    pre = cur
                    cur = cur.next
                    continue
                else:
                    break
            tmp = head.next
            if(cur == newList):
                pre = head
                pre.next = cur
                newList = pre
            else:
                pre.next = head
                pre.next.next = cur
            head = tmp
        return newList

def show(node: ListNode):
    while(node):
        print(node.val, " ", end="")
        node = node.next
    print()


l1 = ListNode(4)
l2 = ListNode(2)
l3 = ListNode(1)
l4 = ListNode(3)
l1.next = l2
l2.next = l3
l3.next = l4
x = Solution().insertionSortList(l1)
show(x)


# l1 = ListNode(-1)
# l2 = ListNode(5)
# l3 = ListNode(3)
# l4 = ListNode(4)
# l5 = ListNode(0)
# l1.next = l2
# l2.next = l3
# l3.next = l4
# l4.next = l5
# x = Solution().insertionSortList(l1)
# show(x)

