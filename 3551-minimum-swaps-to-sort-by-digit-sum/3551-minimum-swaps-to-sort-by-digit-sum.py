class Solution:
    def minSwaps(self, nums: list[int]) -> int:
        def digit_sum(n: int) -> int:
            return sum(int(d) for d in str(n))

        n = len(nums)
        # Sorted version: by digit sum, then by value
        sorted_nums = sorted(nums, key=lambda x: (digit_sum(x), x))

        # Map value -> original index
        pos = {v: i for i, v in enumerate(nums)}

        visited = [False] * n
        swaps = 0

        for i in range(n):
            if visited[i] or nums[i] == sorted_nums[i]:
                continue
            # Traverse cycle
            cycle_size = 0
            j = i
            while not visited[j]:
                visited[j] = True
                # Find where nums[j] should go in sorted array
                target = sorted_nums[j]
                j = pos[target]
                cycle_size += 1
            swaps += cycle_size - 1

        return swaps