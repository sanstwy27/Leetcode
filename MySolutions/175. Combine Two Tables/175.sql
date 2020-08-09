# ============================================================================
# Name        : Leetcode.175. Combine Two Tables
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description :
# Reference   :
# ============================================================================
# Write your MySQL query statement below
SELECT FirstName, LastName, City, State
FROM   Person LEFT JOIN Address ON Address.PersonId = Person.PersonId;