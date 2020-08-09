# ============================================================================
# Name        : Leetcode.729. My Calendar I
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class MyCalendar:
    _book = list()

    def __init__(self):
        self._book = []

    def book(self, start: int, end: int) -> bool:
        for a, b in self._book:
            if(a <= start and start <= b):
                return False
            if(start < a and a <= end - 1):
                return False
        self._book.append((start, end - 1))
        return True


# Your MyCalendar object will be instantiated and called as such:
obj = MyCalendar()
param_1 = obj.book(97,100)
param_2 = obj.book(33,51)
param_3 = obj.book(89,100)
param_4 = obj.book(83,100)
param_5 = obj.book(75,92)
param_6 = obj.book(76,95)
param_7 = obj.book(19,30)
param_8 = obj.book(53,63)
param_9 = obj.book(8,23)
param_10 = obj.book(18,37)
param_11 = obj.book(87,100)
param_12 = obj.book(83,100)
param_13 = obj.book(54,67)
param_14 = obj.book(35,48)
param_15 = obj.book(58,75)
param_16 = obj.book(70,89)
param_17 = obj.book(13,32)
param_18 = obj.book(44,63)
param_19 = obj.book(51,62)
param_20 = obj.book(2,15)

print(param_20)


