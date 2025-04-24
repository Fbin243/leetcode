'''
/**
 * Author: Fbin
 * Created at: 24/04/2025
 * Link:https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/?envType=daily-question&envId=2025-04-24
 * Goal: Zalo Tech Freshers 2025
 */
 '''

class Solution:
  def countCompleteSubarrays(self, nums: list[int]) -> int:
    l = 0
    r = 0
    n = len(nums)
    d = {}
    res = 0
    distictCnt = len(set(nums))
    
    while r < n:
      d[nums[r]] = d.get(nums[r], 0) + 1
      
      cnt = 0
      while(l <= r and len(d) == distictCnt):
        if d[nums[l]] > 0:
          d[nums[l]] -= 1
          if d[nums[l]] == 0:
            d.pop(nums[l])
        cnt += 1
        l += 1
        
      res += cnt * (n - r)
      
      r += 1
  
    return res
      
# Example usage
if __name__ == "__main__":
  nums = [1,3,1,2,2]
  solution = Solution()
  result = solution.countCompleteSubarrays(nums)
  print(result)  # Output: 10
    