from functools import lru_cache


class Solution:
    def longestPalindrome(self, word1: str, word2: str) -> int:
        tmp = set(word1)
        iscommon = False
        for c in word2:
            if c in tmp:
                iscommon = True
        if not iscommon:
            return 0

        word = word1 + word2
        memo = {}
        cache = {}
        self.helper(word, 0, len(word) - 1, memo, cache)

        res = 0
        for (i, j), val in memo.items():
            if i < len(word1) and j >= len(word1):
                res = max(res, val)
        return res

    def helper(self, word: str, i, j, memo, cache) -> bool:
        """
        max length of palindrome subsequence between i and j
        """
        if i > j:
            return 0
        if i == j:
            return 1

        if (i, j) in cache:
            return cache.get((i, j))

        cache[(i, j)] = 0

        if word[i] == word[j]:
            memo[(i, j)] = 2 + self.helper(word, i + 1, j - 1, memo, cache)
            cache[(i, j)] += memo[(i, j)]
            return cache[(i, j)]
        else:
            cache[(i, j)] += max(
                self.helper(word, i + 1, j, memo, cache),
                self.helper(word, i, j - 1, memo, cache),
            )
            return cache[(i, j)]


if __name__ == "__main__":
    word1 = "ab"
    word2 = "ab"
    solution = Solution()
    print(solution.longestPalindrome(word1, word2))
    print(solution.memo)
