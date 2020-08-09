# ============================================================================
# Name        : Leetcode.405. Convert a Number to Hexadecimal
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   :
# ============================================================================
class Solution:
    def toHex(self, num: int) -> str:
        if(num == 0):
            return '0'
        if(num < 0):
            num += 4294967296
        
        hex_values = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 'a', 'b', 'c', 'd', 'e', 'f']
        reversed_number = ""
        while num > 0:
            remainder = num % 16
            num -= remainder
            num //= 16
            reversed_number = str(hex_values[remainder]) + reversed_number
        return reversed_number
        

print(Solution().toHex(256));
