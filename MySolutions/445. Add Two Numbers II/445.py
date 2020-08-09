# ============================================================================
# Name        : Leetcode.445. Add Two Numbers II
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
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        d1 = collections.deque()
        d2 = collections.deque()
        tmp = l1
        while(tmp):
            d1.append(tmp)
            tmp = tmp.next
        tmp = l2
        while(tmp):
            d2.append(tmp)
            tmp = tmp.next

        res = []
        carry = 0
        while(len(d1) > 0 or len(d2) > 0):
            sum = 0
            if(d1):
                sum += (d1.pop()).val
            if(d2):
                sum += (d2.pop()).val
            sum += carry
            carry = int(sum / 10)
            res.append(ListNode(sum % 10))
        if(carry > 0):
            res.append(ListNode(carry))
        for i in range(len(res) - 1, -1, -1):
            if(i > 0):
                res[i].next = res[i - 1]

        return res[len(res) - 1]




n1 = ListNode(7)
n2 = ListNode(2)
n3 = ListNode(4)
n4 = ListNode(3)
n1.next = n2
n2.next = n3
n3.next = n4

m1 = ListNode(5)
m2 = ListNode(6)
m3 = ListNode(4)
m1.next = m2
m2.next = m3

res = Solution().addTwoNumbers(n1, m1)
while(res):
    print(res.val, " ", end="")
    res = res.next







