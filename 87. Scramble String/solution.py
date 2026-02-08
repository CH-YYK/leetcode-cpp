from collections import Counter
from functools import lru_cache


class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        @lru_cache(maxsize=None)
        def dfs(t1, t2) -> bool:
            if t1 == t2:
                return True
            if Counter(t1) != Counter(t2):
                return False
            l = len(t1)
            for i in range(1, len(t1)):
                if dfs(t1[:i], t2[:i]) and dfs(t1[i:], t2[i:]):
                    return True
                if dfs(t1[:i], t2[l - i :]) and dfs(t1[l - i :], t2[:i]):
                    return True
            return False

        return dfs(s1, s2)
