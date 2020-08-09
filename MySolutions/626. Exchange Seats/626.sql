# ============================================================================
# Name        : Leetcode.626. Exchange Seats
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   :
# ============================================================================
# Write your MySQL query statement below
SELECT S.id AS id,
       IFNULL(A.student, S.student) AS student
FROM   seat AS S LEFT JOIN seat AS A ON
        (S.id % 2 = 1 AND S.id + 1 = A.id) OR
        (S.id % 2 = 0 AND S.id - 1 = A.id)
ORDER BY id ASC