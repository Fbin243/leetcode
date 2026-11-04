
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m, n = len(dungeon), len(dungeon[0])

        dp = [float('inf')] * (n + 1)

        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if i == m - 1 and j == n - 1:
                    dp[j] = max(1, 1 - dungeon[i][j])
                elif i == m - 1:
                    dp[j] = max(1, dp[j + 1] - dungeon[i][j])
                elif j == n - 1:
                    dp[j] = max(1, dp[j] - dungeon[i][j])
                else:
                    dp[j] = max(1, min(dp[j], dp[j + 1]) - dungeon[i][j])

        return dp[0]