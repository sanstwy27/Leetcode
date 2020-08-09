# ============================================================================
# Name        : Leetcode.176. Second Highest Salary
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
# Write your MySQL query statement below
SELECT MAX(Salary) AS SecondHighestSalary 
FROM   Employee
WHERE  Salary < (SELECT MAX(m.Salary) FROM   Employee m)
ORDER BY Salary DESC