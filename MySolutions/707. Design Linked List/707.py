# ============================================================================
# Name        : Leetcode.707. Design Linked List
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class MyLinkedList:
    
    class LinkedNode:
        def __init__(self, n: int):
            self.val = n
            self.next = None
            self.pre = None
            
    _len = 0
    _head, _tail = None, None

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._len = 0
        self._head = None
        self._tail = None
        

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        if(self._head == None or index >= self._len):
            return -1
        else:
            cur = None
            if(index <= self._len - index):
                cur = self._head
                step = index
                while(step > 0):
                    cur = cur.next
                    step -= 1
            else:
                cur = self._tail
                step = self._len - index - 1
                while(step > 0):
                    cur = cur.pre
                    step -= 1

            if(cur):
                return cur.val
            else:
                return -1
        

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        ln = self.LinkedNode(val)
        if(not self._head and not self._tail):
            self._head = ln
            self._tail = ln
        else:
            ln.next = self._head
            self._head.pre = ln
            self._head = ln
        self._len += 1
        return
        

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        ln = self.LinkedNode(val)
        if(not self._head and not self._tail):
            self._head = ln
            self._tail = ln
        else:
            ln.pre = self._tail
            self._tail.next = ln
            self._tail = ln
        self._len += 1
        return

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if(index == 0):
            self.addAtHead(val)
            return
        elif(index == self._len):
            self.addAtTail(val)
            return
        else:
            if(index > self._len or self._head == None):
                return
            else:
                ln = self.LinkedNode(val)
                cur = None
                if(index <= self._len - index):
                    cur = self._head
                    step = index
                    while(step > 0):
                        cur = cur.next
                        step -= 1
                else:
                    cur = self._tail
                    step = self._len - index - 1
                    while(step > 0):
                        cur = cur.pre
                        step -= 1
                        
                if(cur):
                    if(cur.pre):
                        cur.pre.next = ln
                    ln.pre = cur.pre
                    ln.next = cur
                    cur.pre = ln
                    self._len += 1
            return

    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if(self._len == 0):
            return
        else:
            if(index >= self._len or self._head == None):
                return -1
            else:
                cur = None
                if(index <= self._len - index):
                    cur = self._head
                    step = index
                    while(step > 0):
                        cur = cur.next
                        step -= 1
                else:
                    cur = self._tail
                    step = self._len - index - 1
                    while(step > 0):
                        cur = cur.pre
                        step -= 1
                        
                if(cur):
                    if(cur.pre):
                        cur.pre.next = cur.next
                    if(cur.next):
                        cur.next.pre = cur.pre
                        
                    if(index == 0):
                        self._head = cur.next
                    if(index == self._len - 1):
                        self._tail = cur.pre
                    del cur
    
                    self._len -= 1
                    if(self._len == 0):
                        self._head= None
                        self._tail = None
                return
    
    def displayList(self):
        cur = self._head
        while(cur):
            print(" ", cur.val, end="")
            cur = cur.next
        print()


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)


# linkedList = MyLinkedList()
# p1 = linkedList.addAtHead(1)
# p2 = linkedList.addAtTail(3)
# p3 = linkedList.addAtIndex(1, 2)
# p4 = linkedList.get(1)
# p5 = linkedList.deleteAtIndex(1)
# p6 = linkedList.get(1)
# print(p1)
# print(p2)
# print(p3)
# print(p4)
# print(p5)
# print(p6)


# linkedList = MyLinkedList()
# p1 = linkedList.addAtHead(7)
# p2 = linkedList.addAtHead(2)
# p3 = linkedList.addAtHead(1)
# p4 = linkedList.addAtIndex(3, 0)
# p5 = linkedList.deleteAtIndex(2)
# p6 = linkedList.addAtHead(6)
# p7 = linkedList.addAtTail(4)
# p8 = linkedList.get(4)
# p9 = linkedList.addAtHead(4)
# p10 = linkedList.addAtIndex(5, 0)
# p11 = linkedList.addAtHead(6)
# print(p1)
# print(p2)
# print(p3)
# print(p4)
# print(p5)
# print(p6)
# print(p7)
# print(p8)
# print(p9)
# print(p10)
# print(p11)


# linkedList = MyLinkedList()
# p1 = linkedList.addAtHead(1)
# p2 = linkedList.addAtTail(3)
# p3 = linkedList.addAtIndex(1, 2)
# p4 = linkedList.get(1)
# p5 = linkedList.deleteAtIndex(0)
# p6 = linkedList.get(0)
# print(p1)
# print(p2)
# print(p3)
# print(p4)
# print(p5)
# print(p6)



# linkedList = MyLinkedList()
# p1 = linkedList.addAtHead(1)
# p2 = linkedList.addAtTail(3)
# p3 = linkedList.addAtIndex(1, 2)
# p4 = linkedList.get(1)
# p5 = linkedList.deleteAtIndex(1)
# p6 = linkedList.get(1)
# print(p1)
# print(p2)
# print(p3)
# print(p4)
# print(p5)
# print(p6)


linkedList = MyLinkedList()
p1 = linkedList.addAtIndex(0, 10)
p2 = linkedList.addAtIndex(0, 20)
p3 = linkedList.addAtIndex(1, 30)
p4 = linkedList.get(0)
print(p1)
print(p2)
print(p3)
print(p4)









