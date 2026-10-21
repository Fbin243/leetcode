class Solution:
    def numOfWays(self, nums: list[int]) -> int:
        n = len(nums)
        mod = 10**9 + 7

        # Pascal's triangle for combinations
        comb = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(n + 1):
            comb[i][0] = 1
            for j in range(1, i + 1):
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod

        def count(nums: list[int]) -> int:
            if len(nums) <= 2:
                return 1

            root = nums[0]
            left = [x for x in nums[1:] if x < root]
            right = [x for x in nums[1:] if x > root]

            return (comb[len(nums) - 1][len(left)]
                    * count(left)
                    * count(right)) % mod

        return (count(nums) - 1) % mod
