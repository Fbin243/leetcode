class Solution:
    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        def max_subsequence(nums: List[int], length: int) -> List[int]:
            drop = len(nums) - length
            stack = []
            for num in nums:
                while drop > 0 and stack and stack[-1] < num:
                    stack.pop()
                    drop -= 1
                stack.append(num)
            return stack[:length]

        def merge(num1: List[int], num2: List[int]) -> List[int]:
            result = []
            while num1 or num2:
                if num1 >= num2:
                    result.append(num1.pop(0))
                else:
                    result.append(num2.pop(0))
            return result

        start = max(0, k - len(nums2))
        end = min(k, len(nums1))

        max_result = []
        for i in range(start, end + 1):
            sub1 = max_subsequence(nums1, i)
            sub2 = max_subsequence(nums2, k - i)
            merged = merge(sub1, sub2)
            max_result = max(max_result, merged)

        return max_result