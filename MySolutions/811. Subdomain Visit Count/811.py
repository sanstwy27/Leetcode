# ============================================================================
# Name        : Leetcode.811. Subdomain Visit Count
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://blog.csdn.net/fuxuemingzhu/article/details/79789925
# ============================================================================
from typing import collections, List
class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        count = collections.Counter()
        for cpdomain in cpdomains:
            times, domain = cpdomain.split()
            times = int(times)
            # Count
            count[domain] += times
            for i, c in enumerate(domain):
                if c == '.':
                    count[domain[i + 1:]] += times

        return [str(times) + " " + domain for domain, times in count.items()]


cpdomains = ["9001 discuss.leetcode.com"]
print(Solution().subdomainVisits(cpdomains))