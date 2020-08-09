# ============================================================================
# Name        : Leetcode.1286. Iterator for Combination
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class CombinationIterator:
    _str = ""
    _n = 0
    _clen = 0
    _c = None
    
    def __init__(self, characters: str, combinationLength: int):
        self._str = characters
        self._n = len(characters)
        self._clen = combinationLength

    def next(self) -> str:
        if(self._n < self._clen):
            return ""
        else:
            if(not self._c):
                self._c  = collections.Counter()
                for i in range(1, self._clen + 1):
                    self._c[i] = i - 1
            else:
                x = self._n - 1
                for i in range(self._clen, 0, -1):
                    if(self._c[i] != x):
                        self._c[i] += 1
                        tmp = self._c[i] + 1
                        for j in range(i + 1, self._clen + 1):
                            self._c[j] = tmp
                            tmp += 1
                        break
                    else:
                        x -= 1
            
            str = ""
            for i in range(1, self._clen + 1):
                str += self._str[self._c[i]]
    
            return str

    def hasNext(self) -> bool:
        if(self._n < self._clen):
            return False
        elif(not self._c):
            return True
        else:                
            x = self._n - 1
            for i in range(self._clen, 0, -1):
                if(self._c[i] != x):
                    return True
                else:
                    x -= 1
            return False


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()



obj = CombinationIterator("abc", 4)
while(obj.hasNext()):
    print(obj.next())









