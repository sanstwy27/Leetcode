# ============================================================================
# Name        : Leetcode.1131. Maximum of Absolute Value Expression
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://leetcode.com/problems/maximum-of-absolute-value-expression/discuss/
#               340075/c%2B%2B-beats-100-(both-time-and-memory)-with-algorithm-and-image
# [Sol]:
#    Use the idea that abs(A) + abs(B) = max(A+B, A-B, -A+B, -A-B).
# [Formule]:
#    |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
# [Eq]:
#    1. arr1[i] - arr1[j] - arr2[i] + arr2[j] - i + j
#        => (arr1[i] - arr2[i] - i) - (arr1[j] - arr2[j] - j)
#    2. arr1[i] - arr1[j] - arr2[i] + arr2[j] + i - j
#        => (arr1[i] - arr2[i] + i) - (arr1[j] - arr2[j] + j)
#    3. arr1[i] - arr1[j] + arr2[i] - arr2[j] - i + j
#        => (arr1[i] + arr2[i] - i) - (arr1[j] + arr2[j] - j)
#    4. arr1[i] - arr1[j] + arr2[i] - arr2[j] + i - j
#        => (arr1[i] + arr2[i] + i) - (arr1[j] + arr2[j] + j)
#    5. -arr1[i] + arr1[j] - arr2[i] + arr2[j] - i + j
#        => (-arr1[i] - arr2[i] - i) + (arr1[j] + arr2[j] + j)
#    6. -arr1[i] + arr1[j] - arr2[i] + arr2[j] + i - j
#        => (-arr1[i] - arr2[i] + i) + (arr1[j] + arr2[j] - j)
#    7. -arr1[i] + arr1[j] + arr2[i] - arr2[j] - i + j
#        => (-arr1[i] + arr2[i] - i) + (arr1[j] - arr2[j] + j)
#    8. -arr1[i] + arr1[j] + arr2[i] - arr2[j] + i - j
#        (-arr1[i] + arr2[i] + i) + (arr1[j] - arr2[j] - j)
#
#    1<=>8, 2<=>7, 3<=6, 4<=>5
# ============================================================================
from typing import collections, List
class Solution:
    def maxAbsValExpr(self, arr1: List[int], arr2: List[int]) -> int:
        case1_max, case1_min = float('-inf'), float('inf')
        case2_max, case2_min = float('-inf'), float('inf')
        case3_max, case3_min = float('-inf'), float('inf')
        case4_max, case4_min = float('-inf'), float('inf')
        for i in range(0, len(arr1)):
            # (arr1[i] - arr2[i] - i) - (arr1[j] - arr2[j] - j)
            case1_max = max(case1_max, arr1[i] - arr2[i] - i)
            case1_min = min(case1_min, arr1[i] - arr2[i] - i)
            # (arr1[i] - arr2[i] + i) - (arr1[j] - arr2[j] + j)
            case2_max = max(case2_max, arr1[i] - arr2[i] + i)
            case2_min = min(case2_min, arr1[i] - arr2[i] + i)
            # (arr1[i] + arr2[i] - i) - (arr1[j] + arr2[j] - j)
            case3_max = max(case3_max, arr1[i] + arr2[i] - i)
            case3_min = min(case3_min, arr1[i] + arr2[i] - i)
            # (arr1[i] + arr2[i] + i) - (arr1[j] + arr2[j] + j)
            case4_max = max(case4_max, arr1[i] + arr2[i] + i)
            case4_min = min(case4_min, arr1[i] + arr2[i] + i)
        return max(case1_max - case1_min,
                    case2_max - case2_min,
                     case3_max - case3_min,
                      case4_max - case4_min)



# arr1 = [1,2,3,4]
# arr2 = [-1,4,5,6]
arr1 = [1,-2,-5,0,10]
arr2 = [0,-2,-1,-7,-4]
print(Solution().maxAbsValExpr(arr1, arr2))