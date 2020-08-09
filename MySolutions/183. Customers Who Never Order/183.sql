# ============================================================================
# Name        : Leetcode.183. Customers Who Never Order
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description :
# Reference   :
# ============================================================================
# Write your MySQL query statement below
SELECT Name AS Customers
FROM   Customers
WHERE  Id NOT IN (
                    SELECT DISTINCT CustomerId
                    FROM  ORDERS
);