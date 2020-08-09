# ============================================================================
# Name        : Leetcode.184. Department Highest Salary
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description :
# ============================================================================
# Write your MySQL query statement below
SELECT Department.Name AS Department, Employee.Name AS Employee, Salary
FROM Employee INNER JOIN Department ON Employee.DepartmentId = Department.Id,
     (SELECT MAX(Salary) AS BS, DepartmentId AS BDID
      FROM Employee
      GROUP BY DepartmentId ) AS B
WHERE Salary = BS AND DepartmentId = BDID