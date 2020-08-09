# ============================================================================
# Name        : Leetcode.24. Swap Nodes in Pairs
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
    def swapPairs(self, head: ListNode) -> ListNode:
        h, flag = None, None
        cur = head
        while(cur):
            tmp1 = cur.next
            if(tmp1):
                tmp2 = tmp1.next
                if(tmp2):
                    tmp1.next = cur
                    cur.next = tmp2
                else:
                    tmp1.next = cur
                    cur.next = None
                if(flag):
                    flag.next = tmp1
                
                if(not h):
                    h = tmp1
            else:
                if(not h):
                    h = head
            
            flag = cur
            cur = cur.next
            
        return h


# l1 = ListNode(1)
# l2 = ListNode(2)
# l3 = ListNode(3)
# l4 = ListNode(4)
# l1.next = l2
# l2.next = l3
# l3.next = l4

l1 = ListNode(1)

h = Solution().swapPairs(l1)
while(h):
    print(h.val, " ", end="")
    h = h.next









