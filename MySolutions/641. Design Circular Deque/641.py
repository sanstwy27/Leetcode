# ============================================================================
# Name        : Leetcode.641. Design Circular Deque
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class MyCircularDeque:
    _front, _last = 0, 0
    _size, _maxSize = 0, 0
    _cdq = []
    
    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the size of the deque to be k.
        """
        self._front, self._last = 0, 0
        self._size, self._maxSize = 0, k
        self._cdq = [-1] * k

    def insertFront(self, value: int) -> bool:
        """
        Adds an item at the front of Deque. Return true if the operation is successful.
        """
        if(not self.isFull()):
            if(self._front == 0):
                self._front = self._maxSize - 1
            else:
                self._front -= 1
            self._cdq[self._front] = value
            self._size += 1
            return True
        else:
            return False
        

    def insertLast(self, value: int) -> bool:
        """
        Adds an item at the rear of Deque. Return true if the operation is successful.
        """
        if(not self.isFull()):
            self._cdq[self._last] = value
            self._last = (self._last + 1) % self._maxSize
            self._size += 1
            return True
        else:
            return False
        

    def deleteFront(self) -> bool:
        """
        Deletes an item from the front of Deque. Return true if the operation is successful.
        """
        if(not self.isEmpty()):
            self._front = (self._front + 1) % self._maxSize
            self._size -= 1
            return True
        else:
            return False

    def deleteLast(self) -> bool:
        """
        Deletes an item from the rear of Deque. Return true if the operation is successful.
        """
        if(not self.isEmpty()):
            if(self._last == 0):
                self._last = self._maxSize - 1
            else:
                self._last -= 1
            self._size -= 1
            return True
        else:
            return False

    def getFront(self) -> int:
        """
        Get the front item from the deque.
        """
        x = -1
        if(not self.isEmpty()):
            x = self._cdq[self._front]
        return x

    def getRear(self) -> int:
        """
        Get the last item from the deque.
        """
        x = -1
        if(not self.isEmpty()):
            if(self._last == 0):
                x = self._cdq[self._maxSize - 1]
            else:
                x = self._cdq[self._last - 1]
        return x

    def isEmpty(self) -> bool:
        """
        Checks whether the circular deque is empty or not.
        """
        if(self._size == 0):
            return True
        else:
            return False

    def isFull(self) -> bool:
        """
        Checks whether the circular deque is full or not.
        """
        if(self._size == self._maxSize):
            return True
        else:
            return False


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()


