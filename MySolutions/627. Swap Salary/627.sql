# ============================================================================
# Name        : Leetcode.627. Swap Salary
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : 
# ============================================================================
# Write your MySQL query statement below
UPDATE salary
SET sex = (CASE sex WHEN 'm' THEN 'f' ELSE 'm' END);