# ============================================================================
# Name        : Leetcode.1223. Dice Roll Simulation
# Author      : HuaHua
# Version     : sanstwy27 Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://www.youtube.com/watch?v=3JOZcD-BRLE
# ============================================================================
from typing import collections, List
class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        # const
        kDicePoint = 6
        kMaxRolls = 15
        kMod = 10**9 + 7
        
        # dp[i][j][k] = # of sequence ends with k consecutive j after i rolls
        dp = []
        for k in range(n + 1):
            dice = []
            for j in range(kDicePoint):
                rolls = []
                for i in range(kMaxRolls + 1):
                    rolls.append(0)
                dice.append(rolls)
            dp.append(dice)

        # 1 step, 1 dice, 1 way
        for j in range(0, kDicePoint):
            dp[1][j][1] = 1

        for i in range(2, n + 1):
            for j in range(0, kDicePoint):
                for p in range(0, kDicePoint):
                    for k in range(1, rollMax[p] + 1):
                        if(p != j):
                            # not the same dice
                            dp[i][j][1] = (dp[i][j][1] + dp[i - 1][p][k]) % kMod
                        elif(k < rollMax[p]):
                            # same dice, make sure k + 1 <= rollMax
                            dp[i][j][k + 1] = (dp[i][j][k + 1] + dp[i - 1][p][k]) % kMod
            #self.show(dp)
            #print("==========")
        
        ans = 0
        for j in range(0, kDicePoint):
            for k in range(1, rollMax[j] + 1):
                ans = (ans + dp[n][j][k]) % kMod
                
        return ans

    def show(self, dp: List[List[List[int]]]):
        for k in range(n + 1):
            print("[ n = ", k)
            for j in range(len(dp[k])):
                print(" [ ", end="")
                for i in range(len(dp[k][j])):
                    print(dp[k][j][i], " ", end="")
                print(" ] ")
            print("]")



n = 3
rollMax = [1,1,1,2,2,3]
print(Solution().dieSimulator(n, rollMax))

