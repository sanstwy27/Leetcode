# ============================================================================
# Name        : Leetcode.433. Minimum Genetic Mutation
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
from typing import collections, List
class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        if(end not in bank):
            return -1
        else:
            s = set(bank)
            bank = list(s)
            
            book = {}
            hit = {}
            book[start], book[end] = [], []
            hit[start], hit[end] = False, False
            for g in bank:
                book[g] = []
                hit[g] = False
                
            for g in bank:
                for d in book.copy():
                    if(self.hamiltonDistance(g, d) == 1):
                        book[d].append(g)
            return self.dfs(book, hit, start, 0, end)
            
    def dfs(self, book: dict, hit: dict, cur: str, step: int, end: str) -> int:
        if(cur == end):
            return step
        else:
            if(len(book[cur]) != 0):
                if(hit[cur] == False):
                    hit[cur] = True
                    
                    for d in book[cur]:
                        res = self.dfs(book, hit, d, step + 1, end)
                        if(res > 0):
                            return res
            return -1
        
    def hamiltonDistance(self, s1: str, s2: str) -> int:
        if(len(s1) != len(s2)):
            return -1
        else:
            distance = 0
            for i in range(0, min(len(s1), len(s2))):
                if(s1[i] != s2[i]):
                    distance += 1
            return distance


# start = "AAAAACCC"
# end = "AACCCCCC"
# bank = ["AAAACCCC", "AAACCCCC", "AACCCCCC"]
# start = "AACCGGTT"
# end = "AAACGGTA"
# bank = ["AACCGGTA", "AACCGCTA", "AAACGGTA"]
# start = "AACCTTGG"
# end = "AATTCCGG"
# bank = ["AATTCCGG","AACCTGGG","AACCCCGG","AACCTACC"]
start = "AACCGGTT"
end = "AAACGGTA"
bank = ["AACCGATT","AACCGATA","AAACGATA","AAACGGTA"]
print(Solution().minMutation(start, end, bank))



