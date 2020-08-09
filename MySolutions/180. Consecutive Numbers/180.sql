# ============================================================================
# Name        : Leetcode.180. Consecutive Numbers
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description :
# Reference   :
# ============================================================================
# Write your MySQL query statement below
SELECT DISTINCT Num AS ConsecutiveNums
FROM Logs AS I
WHERE I.Num = (SELECT Num FROM Logs AS J WHERE J.Id=I.Id+1) AND
      I.Num = (SELECT Num FROM Logs AS J WHERE J.Id=I.Id+2)












