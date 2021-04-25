class Solution:
    def maxBuilding(self, n: int, restrictions: List[List[int]]) -> int:
        dp = [-1] * n
        for vec in restrictions:
            dp[vec[0] - 1] = vec[1]
        dp[0] = 0

        for i in range(n):
            if dp[i] != -1:
                dp[i] = min(dp[i-1] + 1, dp[i])
            else:
                dp[i] = dp[i-1] + 1

        res = 0
        for i in range(n-1, -1, -1):
            if i < n - 1 and dp[i+1] + 1 < dp[i]:
                dp[i] = dp[i+1] + 1
            if dp[i] > res:
                res = dp[i]
        return res
