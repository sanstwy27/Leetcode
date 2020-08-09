# ============================================================================
# Name        : Leetcode.232. Implement Queue using Stacks
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class MyQueue:
    _d = collections.deque()

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._d = collections.deque()

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self._d.append(x)
        

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        return self._d.popleft()

    def peek(self) -> int:
        """
        Get the front element.
        """
        x = self._d.popleft()
        self._d.appendleft(x)
        return x
        

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return len(self._d) == 0
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()


obj = MyQueue()
print(obj.empty())
obj.push(1)
print(obj.peek())
obj.push(2)
obj.push(3)
print(obj.pop())
print(obj.pop())
print(obj.empty())


o = MyQueue()
print(o.empty())

