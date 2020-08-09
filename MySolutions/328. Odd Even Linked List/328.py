# ============================================================================
# Name        : Leetcode.328. Odd Even Linked List
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
    def oddEvenList(self, head: ListNode) -> ListNode:
        oddDummy = ListNode(0)
        evenDummy = ListNode(0)

        odd = oddDummy
        even = evenDummy
        cur = head
        isOdd = True
        while(cur):
            if(isOdd):
                odd.next = cur
                odd = odd.next
            else:
                even.next = cur
                even = even.next
            isOdd = not isOdd
            cur = cur.next

        if(odd == oddDummy):
            return head
        else:
            if(even == evenDummy):
                return oddDummy.next
            else:
                odd.next = evenDummy.next
                even.next = None
                return oddDummy.next



# l1 = ListNode(1)
# l2 = ListNode(2)
# l3 = ListNode(3)
# l4 = ListNode(4)
# l5 = ListNode(5)
# l1.next = l2
# l2.next = l3
# l3.next = l4
# l4.next = l5
# res = Solution().oddEvenList(l1)


l1 = ListNode(2)
l2 = ListNode(1)
l3 = ListNode(3)
l4 = ListNode(5)
l5 = ListNode(6)
l6 = ListNode(4)
l7 = ListNode(7)
l1.next = l2
l2.next = l3
l3.next = l4
l4.next = l5
l5.next = l6
l6.next = l7
res = Solution().oddEvenList(l1)


while(res):
    print(res.val, " ", end="")
    res = res.next

