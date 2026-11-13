import collections

class Solution:
    def countNonDecreasingSubarrays(self, nums: list[int], k: int) -> int:
        ans = 0
        cost = 0
        dq = collections.deque()
        
        n = len(nums)
        right = n - 1
        
        for left in range(n - 1, -1, -1):
            num = nums[left]
            count = 1
            
            while dq and dq[-1][0] < num:
                next_num, next_count = dq.pop()
                cost += (num - next_num) * next_count
                count += next_count
            
            dq.append((num, count))
            
            while cost > k:
                right_val, right_count = dq.popleft()
                
                cost -= (right_val - nums[right])
                right -= 1
                
                if right_count > 1:
                    dq.appendleft((right_val, right_count - 1))
            
            ans += (right - left + 1)
            
        return ans
