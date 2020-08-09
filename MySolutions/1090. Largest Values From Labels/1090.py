# ============================================================================
# Name        : Leetcode.1090. Largest Values From Labels
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : Question Explanation
#               https://leetcode.com/problems/largest-values-from-labels/discuss/313011/Question-
#               Explanation-and-Simple-Solution-or-Java-or-100
#[[quote]]
#	Example: values = [5,4,3,2,1], labels = [1,1,2,2,3], num_wanted = 3, use_limit = 1
#
#	In this example, subset size <= 3 (as num_wanted = 3)
#	Listing members in each label
#	Label 1 -> [5,4]
#	Label 2 -> [3,2]
#	Label 3 -> [1]
#
#	Now from each label we can use only 1 element because use_limit for each label is 1.
#	The question asks us to find the largest possible sum of the subset, 
#	so we take from each label group, the largest element available.
#	So in this example,
#	from label 1 : we take 5,
#	from label 2: we take 3
#	from label 3: we take 1 (since label 1 has only one element)
#	5+3+1=9
#[[/quote]]
# ============================================================================
from typing import collections, List
class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], num_wanted: int, use_limit: int) -> int:
        if(len(values) == 0):
            return 0

        x = []
        for i in range(0, len(values)):
            x.append((values[i], labels[i]))
        x.sort(reverse=True)
        
        res = []
        hit = collections.Counter()
        cnt = num_wanted
        for a, b in x:
            if(cnt <= 0):
                break
            if(hit[b] < use_limit):
                res.append(a)
                hit[b] += 1
                cnt -= 1

        return sum(res)




# values = [5,4,3,2,1]
# labels = [1,1,2,2,3]
# num_wanted = 3
# use_limit = 1
# values = [5,4,3,2,1]
# labels = [1,3,3,3,2]
# num_wanted = 3
# use_limit = 2
# values = [9,8,8,7,6]
# labels = [0,0,0,1,1]
# num_wanted = 3
# use_limit = 1
# values = [9,8,8,7,6]
# labels = [0,0,0,1,1]
# num_wanted = 3
# use_limit = 2
values = [3,7,2,7,2]
labels = [2,2,2,2,1]
num_wanted = 2
use_limit = 5
print(Solution().largestValsFromLabels(values, labels, num_wanted, use_limit))



