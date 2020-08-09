# ============================================================================
# Name        : Leetcode.1185. Day of the Week
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://zxi.mytechroad.com/blog/math/leetcode-1185-day-of-the-week/
# ============================================================================
from typing import collections, List
class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        daytab = []
        daytab.append([0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31])
        daytab.append([0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31])
        
        daystotal = 0
        for y in range(1970, year):
            daystotal += (365 + self.leapYear(y))
        leap = 1 if self.leapYear(year) else 0
        for m in range(0, month):
            daystotal += daytab[leap][m]
        daystotal += day

        week = ["Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday"]
        return week[(daystotal) % 7]


    def leapYear(self, year: int):
        return (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)




# day = 31
# month = 8
# year = 2019
# day = 18
# month = 7
# year = 1999
day = 15
month = 8
year = 1993
print(Solution().dayOfTheWeek(day, month, year))






