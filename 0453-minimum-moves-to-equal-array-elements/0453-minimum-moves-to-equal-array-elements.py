class Solution:
    def minMoves(self, nums: list[int]) -> int:
        if not nums:
            return 0
            
        min_val = min(nums)
        total = sum(nums)
        return total - min_val * len(nums)
